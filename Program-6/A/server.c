#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>

void str_echo(int connfd){
        int n=1, buffs = 1024;
        char *buff = malloc(buffs);

        do{
                while((n=recv(connfd, buff, buffs, 0)  > 0))
                        send(connfd, buff, n, 0);
        }while(n>0);
}

int main(){
        int listenfd, addrlen, connfd;
        struct sockaddr_in address;

        if((listenfd = socket(AF_INET, SOCK_STREAM,0) ) > 0)
                printf("Socket is Created\n");

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(15001);

        if((bind(listenfd, (struct sockaddr*)&address, sizeof(address))) == 0)
                printf("Binding Socket\n");

        listen(listenfd,3);
        printf("Server is listening\n");

        for(;;){
                addrlen = sizeof(address);
                connfd = accept(listenfd, (struct sockaddr*)&address, &addrlen);

                printf("Client %s is connected... on port %d\n",inet_ntoa(address.sin_addr), htons(address.sin_port));
                str_echo(connfd);
                close(listenfd);
        }
        return close(connfd);
}
