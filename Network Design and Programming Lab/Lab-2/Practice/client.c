#include <stdio.h> 
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>

#define MAXSIZE 20

void clearBuffer(char* b){
    for (int i = 0; i < MAXSIZE; i++) b[i] = '\0';
}

int recvFile(char* buf, int s){
    char ch;
    for (int i = 0; i < s; i++) {
        ch = buf[i];
        if (ch == EOF){
			printf("\n");        
            return 1;
        }
        else
            printf("%c", ch);
    }
    return 0;
}

int main(){
	int port = 0;
	printf("Enter PORT: "); 
	scanf("%d", &port);
    struct sockaddr_in serv_addr;

    // creating a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("Error while creating socket");
    }else{
        printf("Socket Created!\n");
    }

    //setup client
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //HOME
    serv_addr.sin_port = htons(port);
    printf("Ready to connect!\n");

    //connecting to server
    connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //interacting with client

    char buffer[MAXSIZE];
    char option[MAXSIZE];
    char string[MAXSIZE];

    printf("Connected to server %d\n", serv_addr.sin_addr.s_addr);
    while (1) {
        printf("\nPlease enter file name to receive:\n");
        scanf("%s", buffer);
        send(sockfd, buffer, MAXSIZE,0);
        
        printf("\nPlease enter word to search:\n");
        scanf("%s", string);
        send(sockfd, string, MAXSIZE,0);
  
        printf("\n---------Data Received From Server---------\n");
  
        while (1) {
            // receive
            clearBuffer(buffer);
            clearBuffer(string);
            int res = recv(sockfd, buffer, MAXSIZE,0);
            res = recv(sockfd, string, MAXSIZE, 0);
            // process
            if(recvFile(buffer, MAXSIZE)){
            	printf("\n");
            	if(recvFile(string, MAXSIZE)){
            		break;
            	}
            }
            clearBuffer(buffer);
            
        }
        printf("\n-------------------------------\n");
    }

    //close the connection
    close(sockfd);
    return 0;
}
