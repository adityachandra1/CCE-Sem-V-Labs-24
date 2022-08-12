#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 100

// Error handling
void throwError(int sockfd, int newsockfd) {
    printf("\nMessage Recieving Failed");
    close(sockfd);
    close(newsockfd);
    exit(0);
}

// 1
int searchKey(char *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// 2 
void sort(char *arr, int n, int option) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1] && option == 1) {
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
            }else if(arr[j] < arr[j + 1] && option == 2){
                int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
            }
        }
    }
}

// 3
void splitOddEven(char *arr, int n){
    printf("\nEven array is: \n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }
    printf("\n\nOdd array is: \n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }
}

int main() {
    int r, req, sntb, x, a = 0;
    struct sockaddr_in serv_addr, cli_addr;
    int PORT;
    printf("Input PORT: ");
    scanf("%d", &PORT);

    // creating a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockfd < 0 ? perror("Error while creating socket\n") : printf("Socket Created!\n");

    // setup server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    printf("Starting the Server\n");

    // binding with IP
    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ? perror("Error while binding\n") : printf("Binding Successful\n");

    // listen to upto 5 clients
    listen(sockfd, 5);
    printf("Listening to PORT : %d...\n", PORT);

    // connecting to client
    int clength = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clength);
    newsockfd < 0 ? perror("Error while accepting\n") : printf("Connection Established!\n");

    char buffer[MAX], arr[MAX];
    int arr1[50], arr2[50];
    char message[MAX];

    recv(newsockfd, arr, sizeof(arr), 0) < 0 ? throwError(sockfd, newsockfd) : printf("\nOption Recieved!\n");

    printf("\n\nArray of numbers received!\n");

    int opt = 1, n;
    int key = 1;
    while (opt != 5) {
        recv(newsockfd, buffer, sizeof(buffer), 0) < 0 ? throwError(sockfd, newsockfd) : printf("\nOption Recieved!\n");

        n = buffer[0];
        opt = buffer[1];

        int l = 0, k = 0, x;
        switch (opt) {
            case 1:
                key = buffer[2];
                printf("\nSearching Key");
                int result = searchKey(arr, n, key);
                result == -1 ? printf("\nElement does not exist!") : printf("\nElement exists at position. %d", result + 1);
                printf("\n\n");
                break;
            case 2:
                sort(arr, n, 1);
                printf("\nProcessing done!");
                printf("\nSorted array is: \n");
                for (int i = 0; i < n; i++)
                    printf("%d  ", arr[i]);
                printf("\n\n");
                break;
            case 3:
                sort(arr, n, 2);
                printf("\nProcessing done!");
                printf("\nSorted array is: \n");
                for (int i = 0; i < n; i++)
                    printf("%d  ", arr[i]);
                printf("\n\n");
                break;
            case 4:
                printf("\nProcessing done!");
                splitOddEven(arr, n);
                printf("\n\n");
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                break;
        }
    }
    close(newsockfd);
    close(sockfd);
}

/* I/O

Input PORT: 6900
Socket Created!
Starting the Server
Binding Successful
Listening to PORT : 6900...
Connection Established!

Option Recieved!


Array of numbers received!

Option Recieved!

Searching Key
Element exists at position. 4


Option Recieved!

Searching Key
Element does not exist!


Option Recieved!

Processing done!
Sorted array is: 
1  2  5  6  8  9  


Option Recieved!

Processing done!
Sorted array is: 
9  8  6  5  2  1  


Option Recieved!

Processing done!
Even array is: 
8 6 2 

Odd array is: 
9 5 1 


Option Recieved!
Exiting
*/
