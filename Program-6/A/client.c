#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>

void str_cli(FILE *fp, int sockfd){
        int buffs = 1024;
        char *buff = malloc(buffs);

        while(fgets(buff, buffs, fp) != NULL){
                send(sockfd, buff, sizeof(buff), 0);
                if((recv(sockfd, buff, buffs, 0) ) >0 )
                        fputs(buff, stdout);
        }
        printf("\nEOF\n");
}

int main(int argc, char *argv[]){
        int create_socket;
        struct sockaddr_in address;

        if((create_socket = socket(AF_INET, SOCK_STREAM, 0) ) >0)
                printf("Socket is created\n");

        address.sin_family = AF_INET;
        address.sin_port = htons(15001);
        inet_pton(AF_INET, argv[1], &address.sin_addr);

        if((connect(create_socket, (struct sockaddr*)&address, sizeof(address)) ) == 0)
                printf("Connection was accepted with the server...%s\n",argv[1]);

        str_cli(stdin, create_socket);
        return close(create_socket);
}
