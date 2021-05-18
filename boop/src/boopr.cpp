#include <iostream>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// tos=0x88, ttl=64, dnf=false, port=20001
// padding = {8, 8, 8, 8, 8, 8, 8, 534, 534, 534, 534, 1458}
/******************************************************************
 * 0                   1                   2                   3
 * 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                        Sequence Number                        |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                          Timestamp                            |
 * |                                                               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |         Error Estimate        |           MBZ                 |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                          Receive Timestamp                    |
 * |                                                               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                        Sender Sequence Number                 |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                      Sender Timestamp                         |
 * |                                                               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |      Sender Error Estimate    |           MBZ                 |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |  Sender TTL   |                                               |
 * +-+-+-+-+-+-+-+-+                                               +
 * |                                                               |
 * .                                                               .
 * .                         Packet Padding                        .
 * .                                                               .
 * |                                                               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *******************************************************************/



constexpr auto listen_port = 20001;
constexpr auto recv_buffer_length = 8192;

int main()
{
    auto sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (-1 == sockfd) {
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
        return 1;
    }

    constexpr auto enable = int{1};
    if (-1 == setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int))) {
        std::cerr << "setsockopt(SO_REUSEADDR) error: " << strerror(errno) << std::endl;
        close(sockfd);
        return 1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(listen_port);

    if(-1 == bind(sockfd, reinterpret_cast<sockaddr *>(&addr), sizeof(sockaddr_in))) {
        std::cerr << "Error binding to socket: " << strerror(errno) << std::endl;
        close(sockfd);
        return 1;

    }

    char buf[recv_buffer_length] = {0};
    while(true) {
        struct sockaddr src_addr;
        socklen_t src_size = sizeof(struct sockaddr);

        auto recv_size = recvfrom(sockfd, &buf, recv_buffer_length, 0, &src_addr, &src_size);

        if(recv_size > 0 ) {
            std::cout << "received "
                << recv_size
                << " bytes from "
                << inet_ntoa((reinterpret_cast<sockaddr_in*>(&src_addr))->sin_addr)
                << std::endl;
        }
    }


    close(sockfd);

    return 0;
}
