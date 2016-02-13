#include "pch.h"
#pragma hdrstop
#include "ib_client.h"

int main(int argc, char** argv)
{
    const char* host = argc > 1 ? argv[1] : "";
	unsigned int port = 7496;
	int clientId = 0;

    std::unique_ptr<IBClient> client(new IBClient());

    client->connect(host, port, clientId);
    while (client->isConnected()) 
    {
        client->processMessages();
	}

    return 0;
}