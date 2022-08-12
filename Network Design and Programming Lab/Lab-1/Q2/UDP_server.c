#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 100

int main() {
	struct sockaddr_in serv_addr, cli_addr;
    int sockfd, r, recb, sntb;
    int PORT;
    printf("Input PORT: ");
    scanf("%d", &PORT);
    char buffer[100];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockfd < 0 ? perror("Error while creating socket\n") : printf("Socket Created!\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	socklen_t len;
	int ca;
    len = sizeof(cli_addr);
    ca = sizeof(cli_addr);

	bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ? perror("Error while binding\n") : printf("Binding Successful\n");

    while (1) {
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cli_addr, &ca) < 0? perror("Not Received\n") : prin
        if (recb == -1) {
            printf("\nMessage Recieving Failed");
            close(sockfd);
            exit(0);
        }
        printf("\nMessage Recieved: ");
        printf("%sockfd\n", buffer);
        if (!strcmp(buffer, "halt"))
            break;

        char buff2[50];
        strcpy(buff2, buffer);
        buffer[1] = strlen(buff2);
        int n = 0;
        for (int i = 0; i < buffer[1]; i++)
            if (buff2[i] == 'a' || buff2[i] == 'e' || buff2[i] == 'o' || buff2[i] == 'i' || buff2[i] == 'u')
                n++;
        buffer[2] = n;
        buffer[0] = 1;
        for (int i = 0; i < buffer[1] / 2; i++) {
            if (buff2[i] != buff2[buffer[1] - i - 1]) {
                buffer[0] = 0;
                break;
            }
        }
        sntb = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cli_addr, len);
        if (sntb == -1) {
            printf("\nMessage Sending Failed");
            close(sockfd);
            exit(0);
        }

        if (!strcmp(buffer, "halt"))
            break;
    }
    close(sockfd);
}