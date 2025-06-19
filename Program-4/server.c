#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<time.h>
#include<sys/socket.h>
#include<sys/types.h>

#define HELLO_PORT 12345
#define HELLO_GROUP "225.0.0.37"

int main(){
        int fd;
        char *message = "RVCE-CSE";
        struct sockaddr_in address;

        if((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
                perror("socket");
                exit(1);
        }

        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(HELLO_GROUP);
        address.sin_port = htons(HELLO_PORT);

        while(1){
                if(sendto(fd, message, sizeof(message), 0, (struct sockaddr*)&address, sizeof(address)) < 0){
                        perror("sendto");
                        exit(0);
                }
                sleep(1);
        }
}
