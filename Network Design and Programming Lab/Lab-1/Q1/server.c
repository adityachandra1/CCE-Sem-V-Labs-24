#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>

#define PORT 6969
#define MAXSIZE 1000

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortArray(int arr[], int n){
   for(int i = 0; i < n-1; i++){
    for(int j = 0; i < n-i-1; j++){
        if(arr[j] < arr[i])
        swap(&arr[i], &arr[j]);
    }
   }
}

// int searchKey(int arr[], int n, int k){

// }

// void splitArray(int arr[], int odd[], int even[], int n){

// }

int main(){
    struct sockaddr_in serv_addr, cli_addr;
    
    // creating a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("Error while creating socket");
    }else{
        printf("Socket Created!\n");
    }

    //setup server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    printf("Starting the Server\n");

    //binding with IP
    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    
    //listen to upto 5 clients
    listen(sockfd, 5);
    printf("Listening to PORT : %d ...\n", PORT);

    //connecting to client
    int clength = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clength);

    //interacting with client
    char buffer[4096];
    int n;
    int array[MAXSIZE];
    printf("Connected to client %d\n", cli_addr.sin_addr.s_addr);
    strcpy(buffer, "Server says Hi!");
    send(newsockfd, buffer, sizeof(buffer), 0);
    recv(newsockfd, buffer, sizeof(buffer), 0);
    puts(buffer);
    while(1){
        read(newsockfd, buffer, sizeof(buffer));
        if(strcmp(buffer, "sort") == 10){
            // Sorting the array
            strcpy(buffer, "Enter the array");
            write(newsockfd, buffer, sizeof(buffer));
            read(newsockfd, n, sizeof(n));
            read(newsockfd, array, sizeof(array));
            sortArray(array, n);
            write(newsockfd, array, sizeof(array));
        // }else if(strcmp(buffer, "search") == 0){

        // }else if(strcmp(buffer, "split") == 0){

        }else if(strcmp(buffer, "exit") == 10){
            break;
        }else{
            printf("Invalid input from client\n");
        }
    }

    //close the connection
    close(sockfd);
    return 0;
}
