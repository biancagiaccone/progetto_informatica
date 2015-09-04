#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//const char* ip_address = "10.42.0.1"; //andre!
const char* ip_address = "127.0.0.1";
const int portno = 5002;

struct messages {
    int lenght;
    char *message;
    
};


int main(int argc, char**argv) {
    int n;
    int sockfd;
    struct sockaddr_in servaddr;
    char termget[1000];
    char * retmsg;
    
    
    while (fgets(termget, 1000,stdin) != NULL)
    {
        sockfd=socket(AF_INET,SOCK_STREAM,0);
    
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr=inet_addr(ip_address);
        servaddr.sin_port=htons(portno);
        
        connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

        n = strlen(termget) - 1;
        write(sockfd, &n ,sizeof(int));
        write(sockfd, termget, sizeof(char) * n);

        read(sockfd, &n, sizeof(int));

        retmsg = (char *)malloc(sizeof(char) * (n + 1));
        retmsg[n] = '\0';

        read(sockfd, retmsg,                          sizeof(char) * n/3);
        read(sockfd, retmsg + sizeof(char) * n/3,     sizeof(char) * n/3);
        read(sockfd, retmsg + sizeof(char) * 2 * n/3, sizeof(char) * n/3);
        printf("\n Return Message: %s \n \n", retmsg);

        free(retmsg);
        close(sockfd);
    }

    return 0;
}
