#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    auto sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);


    return 0;
}
