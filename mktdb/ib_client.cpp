#include "pch.h"
#pragma hdrstop
#include "ib_client.h"
#include "posix_client/EPosixClientSocket.h"
#include "posix_client/EPosixClientSocketPlatform.h"

IBClient::IBClient()
{
    client.reset(new EPosixClientSocket(this));
    srand(time(nullptr)); // ?
}

IBClient::~IBClient()
{
}

bool IBClient::connect(const char *host, unsigned int port, int clientId)
{
    const char *ip = !(host && *host) ? "127.0.0.1" : host;

    echo("Connecting to %s:%d, client id: %d...\n", ip, port, clientId);

	bool res = client->eConnect(ip, port, clientId, /* extraAuth */ false);
	if (res)
		echo("Connected\n");
	else
		echo("Failed to connect\n");

	return res;
}

void IBClient::disconnect()
{
    echo("Disconnect...\n");
    client->eDisconnect();
}

bool IBClient::isConnected() const
{
    return client->isConnected();
}

void IBClient::processMessages()
{
	fd_set readSet, writeSet, errorSet;

	struct timeval tval;
	tval.tv_usec = 0;
	tval.tv_sec = 0;

	time_t now = time(NULL);

    client->reqCurrentTime();

	//if( m_sleepDeadline > 0) {
	//	// initialize timeout with m_sleepDeadline - now
	//	tval.tv_sec = m_sleepDeadline - now;
	//}

	if (client->fd() >= 0) 
    {
		FD_ZERO(&readSet);
		errorSet = writeSet = readSet;

		FD_SET(client->fd(), &readSet);

		if( !client->isOutBufferEmpty())
			FD_SET(client->fd(), &writeSet);

		FD_SET(client->fd(), &errorSet);

		int ret = select(client->fd() + 1, &readSet, &writeSet, &errorSet, &tval);

		if (ret == 0) 
        { 
            // timeout
			return;
		}

		if( ret < 0) 
        {	
            // error
			disconnect();
			return;
		}

		if (client->fd() < 0)
			return;

		if (FD_ISSET(client->fd(), &errorSet)) 
        {
			// error on socket
			client->onError();
		}

		if (client->fd() < 0)
			return;

		if (FD_ISSET( client->fd(), &writeSet)) 
        {
			// socket is ready for writing
			client->onSend();
		}

		if (client->fd() < 0)
			return;

		if (FD_ISSET( client->fd(), &readSet)) 
        {
			// socket is ready for reading
			client->onReceive();
		}
	}
}