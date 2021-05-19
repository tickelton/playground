#include <iostream>
#include <chrono>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std::chrono;
using namespace std::chrono_literals;

using fractions = duration<std::int64_t, std::ratio<1, 0x100000000>>; // 1/(2^32)

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
constexpr auto min_request_lenght = 14;
constexpr auto min_response_lenght = 41;
//constexpr auto ntp_time_offset = 2208988800; // Time difference between unix epoch and 01/01/1900

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

    constexpr uint8_t sttl = 255;
    const uint16_t val_ee = htons(1);
    char buf[recv_buffer_length] = {0};
    uint32_t seq_nr = 0;
    while(true) {
        struct sockaddr src_addr;
        socklen_t src_size = sizeof(struct sockaddr);

        auto recv_size = recvfrom(sockfd, &buf, recv_buffer_length, 0, &src_addr, &src_size);
        // get receive timestamp
        auto tp_r = system_clock::now();
		tp_r += (70 * 365 + 17) * 24h;
        auto total_r = tp_r.time_since_epoch();
        auto secs_r  = duration_cast<seconds>(total_r);
        auto fracs_r = duration_cast<fractions>(total_r - secs_r);
        auto sec_r =  static_cast<uint32_t>(secs_r.count());
        auto frac_r =  static_cast<uint32_t>(fracs_r.count());

        //struct timeval ts_recv;
        //if(-1 == gettimeofday(&ts_recv, NULL)) {
        //    std::cerr << "gettimeofday(): " << strerror(errno) << std::endl;
        //    return 1;
        //}
        //ts_recv.tv_sec += ntp_time_offset;


        if(0 == recv_size) {
            continue;
        }
        if(recv_size < min_request_lenght) {
            std::cerr << "Short request; len=" << recv_size << std::endl;
            continue;
        } else {
//            std::cout << "received "
//                << recv_size
//                << " bytes from "
//                << inet_ntoa((reinterpret_cast<sockaddr_in*>(&src_addr))->sin_addr)
//                << std::endl;

            char response_buf[min_response_lenght] = {0};
            uint32_t val_l = htonl(seq_nr);
            memcpy(response_buf, &val_l, 4);
            memcpy(response_buf+12, &val_ee, 2);
            //val_l = htonl(ts_recv.tv_sec);
            val_l = htonl(sec_r);
            memcpy(response_buf+16, &val_l, 4);
            //val_l = htonl(ts_recv.tv_nsec);
            //val_l = htonl(ts_recv.tv_usec);
            val_l = htonl(frac_r);
            memcpy(response_buf+20, &val_l, 4);
            memcpy(response_buf+24, buf, min_request_lenght);
            memcpy(response_buf+40, &sttl, 1);
//            struct timeval ts_send;
//            if(-1 == gettimeofday(&ts_send, NULL)) {
//                std::cerr << "gettimeofday(): " << strerror(errno) << std::endl;
//                return 1;
//            }
//            ts_send.tv_sec += ntp_time_offset;
            auto tp_s = system_clock::now();
    		tp_s += (70 * 365 + 17) * 24h;
            auto total_s = tp_s.time_since_epoch();
            auto secs_s  = duration_cast<seconds>(total_s);
            auto fracs_s = duration_cast<fractions>(total_s - secs_s);
            auto sec_s =  static_cast<uint32_t>(secs_s.count());
            auto frac_s =  static_cast<uint32_t>(fracs_s.count());
            //val_l = htonl(ts_send.tv_sec);
            val_l = htonl(sec_s);
            memcpy(response_buf+4, &val_l, 4);
            //val_l = htonl(ts_send.tv_nsec);
            //val_l = htonl(ts_send.tv_usec);
            val_l = htonl(frac_s);
            memcpy(response_buf+8, &val_l, 4);

            if(sendto(sockfd, &response_buf, min_response_lenght, 0, &src_addr, src_size) < min_response_lenght) {
                std::cerr << "sendto(): " << strerror(errno) << std::endl;
            }
            ++seq_nr;
        }
    }


    close(sockfd);

    return 0;
}
