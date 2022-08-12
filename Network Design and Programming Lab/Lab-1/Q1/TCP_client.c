#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 100

int main() {
    int recb, res;

    int PORT;
    printf("Input PORT: ");
    scanf("%d", &PORT);

    struct sockaddr_in server;

    // Create Socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockfd < 0 ? perror("\nSocket creation error.") : printf("\nSocket created.");

    // Setup Server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");  // HOME
    server.sin_port = htons(PORT);
    printf("Ready to connect!");

    // Connecting
    connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0 ? perror("\nConnection error.") : printf("\nSocket connected.");

    char buffer[MAX];
    char arr[MAX];

    int a[MAX];
    int opt = 1;
    int n;
    int key = 0;

    printf("\n\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        arr[i] = a[i];

    res = send(sockfd, arr, sizeof(arr), 0);
    if (res < 0) {
        close(sockfd);
        printf("\nArray Sending Failed");
        exit(0);
    }
    printf("Array sent to the server");

    while (opt != 5) {
        printf("\n\n");
        printf("1.Search for a number\n2.Sort in ascending order\n3.Sort in descending order\n4.Split into even and odd arrays\n5.Exit\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                // Search
                printf("\nEnter the number to be searched: ");
                scanf("%d", &key);
                buffer[0] = n;
                buffer[1] = opt;
                buffer[2] = key;
                res = send(sockfd, buffer, sizeof(buffer), 0);
                if (res == -1) {
                    close(sockfd);
                    printf("\nParameters Sending Failed");
                    exit(0);
                }
                printf("\nParameters Sent Successfully");
                break;
            case 2:
                // Sort ascending
                buffer[0] = n;
                buffer[1] = opt;
                res = send(sockfd, buffer, sizeof(buffer), 0);
                if (res == -1) {
                    close(sockfd);
                    printf("\nMessage Sending Failed");
                    exit(0);
                }
                break;
            case 3:
                // Sort descending
                buffer[0] = n;
                buffer[1] = opt;
                res = send(sockfd, buffer, sizeof(buffer), 0);
                if (res == -1) {
                    close(sockfd);
                    printf("\nMessage Sending Failed");
                    exit(0);
                }
                break;
            case 4:
                // Split
                buffer[0] = n;
                buffer[1] = opt;
                res = send(sockfd, buffer, sizeof(buffer), 0);
                if (res == -1) {
                    close(sockfd);
                    printf("\nMessage Sending Failed");
                    exit(0);
                }
                break;
            case 5:
                // Exit
                buffer[0] = n;
                buffer[1] = opt;
                res = send(sockfd, buffer, sizeof(buffer), 0);
                if (res == -1) {
                    close(sockfd);
                    printf("\nMessage Sending Failed");
                    exit(0);
                }
                break;
            default:
                printf("\nInvalid choice. Try again!");
        }
    }
    close(sockfd);
}

/* I/O
Input PORT: 6900

Socket created.Ready to connect!
Socket connected.

Enter the number of elements: 6

Enter the elements: 1 9 2 8 5 6
Array sent to the server

1.Search for a number
2.Sort in ascending order
3.Sort in descending order
4.Split into even and odd arrays
5.Exit
Enter your choice: 1

Enter the number to be searched: 8

Parameters Sent Successfully

1.Search for a number
2.Sort in ascending order
3.Sort in descending order
4.Split into even and odd arrays
5.Exit
Enter your choice: 1

Enter the number to be searched: 0

Parameters Sent Successfully

1.Search for a number
2.Sort in ascending order
3.Sort in descending order
4.Split into even and odd arrays
5.Exit
Enter your choice: 2


1.Search for a number
2.Sort in ascending order
3.Sort in descending order
4.Split into even and odd arrays
5.Exit
Enter your choice: 3


1.Search for a number
2.Sort in ascending order
3.Sort in descending order
4.Split into even and odd arrays
5.Exit
Enter your choice: 4


1.Search for a number
2.Sort in ascending order
3.Sort in descending order
4.Split into even and odd arrays
5.Exit
Enter your choice: 5
*/