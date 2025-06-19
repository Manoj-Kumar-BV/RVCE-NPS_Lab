#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>

void str_echo(int connfd, int port){
        int n=1, buffs=1024;
        char *buff = malloc(buffs);

        do{
                while((n=recv(connfd,buff,buffs, 0)) > 0){
                        printf("From the client connected to the port: %d\n", port);
                        fputs(buff, stdout);
                        printf("Reply to the client connected to the port: %d\n",port);
                        fgets(buff, buffs, stdin);
                        send(connfd,buff,n,0);
                }
        }while(n>0);
}

int main(){
        int listenfd,connfd,pid,addrlen;
        struct sockaddr_in addr;

        if((listenfd = socket(AF_INET, SOCK_STREAM, 0) ) > 0)
                printf("Socket was Created\n");
        else
                printf("Socket was not created\n");

        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(15001);

        if(bind(listenfd,(struct sockaddr*)&addr, sizeof(addr)) == 0 )
                printf("Binding Socket\n");

        listen(listenfd,3);

        for(;;){
                addrlen = sizeof(addr);
                connfd = accept(listenfd, (struct sockaddr*)&addr, &addrlen);

                if(connfd > 0)
                        printf("A new client connected from the port %d\n",addr.sin_port);
                else
                        printf("new client's connection was not accepted\n");

                if((pid=fork()) == 0){
                        close(listenfd);
                        str_echo(connfd,addr.sin_port);
                        exit(0);
                }
                close(connfd);
        }
        return 0;
}
