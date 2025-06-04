#include "clientsocket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

ClientSocket::ClientSocket() : sockfd(-1) {}

ClientSocket::~ClientSocket() {
    if (sockfd != -1) {
        close(sockfd);
    }
}

bool ClientSocket::connectToServer(const std::string& ip, int port) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) return false;

    sockaddr_in serv_addr{};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr);

    if (::connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Sunucuya bağlanılamadı.\n";
        return false;
    }

    return true;
}

bool ClientSocket::send(const std::string& data) {
    return ::send(sockfd, data.c_str(), data.size(), 0) >= 0;
}

std::string ClientSocket::receive() {
    char buffer[1024] = {0};
    int bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes > 0) return std::string(buffer, bytes);
    return "";
}
