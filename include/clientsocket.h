#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <string>

class ClientSocket {
public:
    ClientSocket();
    ~ClientSocket();

    bool connectToServer(const std::string& ip, int port);
    bool send(const std::string& data);
    std::string receive();

private:
    int sockfd;
};

#endif
