#include <stdio.h> 
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>

#define PORT 6969
#define MAXSIZE 1000

int main(){
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
    serv_addr.sin_port = htons(PORT);
    printf("Ready to connect!\n");

    //connecting to server
    connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //interacting with client

    char buffer[4096];
    int n;
    int array[MAXSIZE];

    printf("Connected to server %d\n", serv_addr.sin_addr.s_addr);
    strcpy(buffer, "Client says Hi");
    send(sockfd, buffer, sizeof(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    puts(buffer);
    while(1){
        // memset(0, buffer, sizeof buffer);
        fgets(buffer, 4096, stdin);
        write(sockfd, buffer, 4096);
        read(sockfd, buffer, 4096);
        printf("%s", buffer);
        scanf("%d", &n);
        write(sockfd, n, sizeof(n));
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        write(sockfd, array, sizeof(array));
        read(sockfd, array, sizeof(array));
        for(int i = 0; i < n; i++){
            printf("%d ", array[i]);
        }
    }

    //close the connection
    close(sockfd);
    return 0;
}

