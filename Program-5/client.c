#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>

void str_cli(FILE *fp, int sockfd){
        int buffs = 1024, cont;
        char *buff = malloc(buffs);

        while(fgets(buff, buffs, fp) != NULL ){
                send(sockfd,buff, buffs, 0);

                if((cont = recv(sockfd, buff, buffs, 0) ) >= 0){
                        printf("Server Replied\n");
                        fputs(buff, stdout);
                }
        }
        printf("\n str cli \n");
        printf("\n EOF \n");
}

int main(int argc, char* argv[]){
        int create_socket, ret;
        struct sockaddr_in addr;

        if((create_socket = socket(AF_INET, SOCK_STREAM, 0)) >0)
                printf("Socket Created\n");

        addr.sin_family = AF_INET;
        addr.sin_port = htons(15001);
        inet_pton(AF_INET, argv[1], &addr.sin_addr);

        if((ret = connect(create_socket, (struct sockaddr*)&addr, sizeof(addr)) ) == 0)
                printf("Connected\n");
        else
                printf("Error in connecting\n");

        str_cli(stdin, create_socket);

        return 0;
}
