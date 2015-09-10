#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


//iniziamo con il server
//decidiamo una porta da usare: 5002

const int portno = 5002;

struct messages {
    int lenght;
    char *message;
    
};


int main () {
    
   struct messages prova;
    
    //serve un file descriptor della socket del SERVER
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    
    sockfd=socket(AF_INET, SOCK_STREAM, 0); //installa nuova socket di tipo TCP (SOCK_STREAM)
    //riempiamo struct con zeri per prima cosa
    bzero((char *) &serv_addr, sizeof(struct sockaddr_in));
    // o anche: bzero((char *) &serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET; //riempire la struct usando socket IPv4
    serv_addr.sin_addr.s_addr = INADDR_ANY; //
    serv_addr.sin_port = htons(portno); //htons serve per convertire i dati dalla codifica del server a quella della rete
    
    //abiamo dato le caratteristiche del socket e ora gli diciamo di agganciare il socket alla rete di sistema in modo da averlo montato sulla porta del computer
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
        printf ("Errore, non posso connettermi a %d",portno);
        exit(1);
    }
    
    listen(sockfd, 100); //crea file di connessioni perchè ne serve una alla volta

    //un ciclo che non esce mai
    while(true){
        newsockfd=accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); //il server aspetta di essere chiamato e quando avviene mette la connessione in newsockfd
    
    read(newsockfd, &(prova.lenght), sizeof (int));
    prova.message=(char *) malloc (sizeof (char) * prova.lenght);
    read(newsockfd, prova.message, sizeof (char) * prova.lenght);
    //ipotizziamo che il messaggio arrivi tutto intero
    //mandiamo indietro il messaggio moltiplicato x3
    prova.lenght=(prova.lenght )* 3;
    write(newsockfd, &(prova.lenght), sizeof (int)); //comunichiamo lunghezza
    write(newsockfd, prova.message, sizeof (char) * prova.lenght/3);
    write(newsockfd, prova.message, sizeof (char) * prova.lenght/3);
    write(newsockfd, prova.message, sizeof (char) * prova.lenght/3);
    
    write(1, prova.message,sizeof (char) * prova.lenght/3);
    
    close(newsockfd);
    free(prova.message);
    }
    
    return 0;
}
