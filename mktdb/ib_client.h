#pragma once

#include "ib_api_callback.h"

class EPosixClientSocket;

class IBClient : public IBApiCallback
{
public:
    IBClient();
    ~IBClient();

    bool connect(const char *host, unsigned int port, int clientId);
    void disconnect();
    bool isConnected() const;

    void processMessages();

private:
    std::unique_ptr<EPosixClientSocket> client;
};