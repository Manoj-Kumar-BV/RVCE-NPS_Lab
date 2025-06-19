#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<time.h>
#include<sys/types.h>
#include<sys/socket.h>


#define HELLO_PORT 12345
#define HELLO_GROUP "225.0.0.37"
#define MSGBUFSIZE 25

int main(){
        int fd, nbytes, addrlen;
        struct sockaddr_in address;
        char msgbuf[MSGBUFSIZE];
        struct ip_mreq mreq;
        u_int yes = 1;

        if((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
                perror("socket");
                exit(1);
        }

        if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0){
                perror("Reusing ADDR Failed");
                exit(1);
        }

        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(HELLO_GROUP);
        address.sin_port = htons(HELLO_PORT);

        if((bind(fd,(struct sockaddr*)&address, sizeof(address))) < 0){
                perror("bind");
                exit(1);
        }

        mreq.imr_multiaddr.s_addr = inet_addr(HELLO_GROUP);
        mreq.imr_interface.s_addr = htonl(INADDR_ANY);

        if(setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0){
                perror("setsockopt");
                exit(1);
        }

        while(1){
                addrlen = sizeof(address);
                if((nbytes = recvfrom(fd, msgbuf, MSGBUFSIZE, 0, (struct sockaddr*)&address, &addrlen)) < 0){
                        perror("recvfrom");
                }
                puts(msgbuf);
        }
}
