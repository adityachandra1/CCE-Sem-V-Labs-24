#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int s, r, recb, sntb, x;
    printf("INPUT port number: ");
    scanf("%d", &x);
    struct sockaddr_in server;
    char buff[50], buff2[50];
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        printf("\nSocket creation error.");
        exit(0);
    }
    printf("\nSocket created.");

    server.sin_family = AF_INET;
    server.sin_port = htons(x);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    r = connect(s, (struct sockaddr*)&server, sizeof(server));
    if (r == -1) {
        printf("\nConnection error.");
        exit(0);
    }
    printf("\nSocket connected.");

    printf("\n\n");
    int pid;
    pid = fork();
    while (1) {
        if (pid > 0) {
            // parent
			printf("PID: %d\nPPID: %d\n", pid, getppid());
            recb = recv(s, buff, sizeof(buff), 0);
            if (recb == -1) {
                printf("\nMessage Recieving Failed");
                close(s);
                exit(0);
            }
            if (strcmp(buff, "BYE") == 0)
                break;
            printf("Parent - Message Recieved: ");
            printf("%s\n", buff);
        } else {
            // child
			printf("PID: %d\nPPID: %d\n", pid, getppid());
            printf("Child - Type Message: ");
            scanf("%s", buff2);

            sntb = send(s, buff2, sizeof(buff2), 0);
            if (sntb == -1) {
                close(s);
                printf("\nMessage Sending Failed");
                exit(0);
            }
            if (strcmp(buff2, "BYE") == 0)
                break;
        }
    }

    close(s);
}