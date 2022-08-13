#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int s, r, recb, sntb, x, ns, a = 0;
    printf("INPUT port number: ");
    scanf("%d", &x);
    socklen_t len;
    struct sockaddr_in server, client;
    char buff[50], buff2[50];

    s = socket(AF_INET, SOCK_STREAM, 0);
	s < 0? perror("Socket Creation Failed\n"): printf("Socket Created\n");

    server.sin_family = AF_INET;
    server.sin_port = htons(x);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(s, (struct sockaddr*)&server, sizeof(server)) < 0? perror("Binding error"): printf("Binding Done\n");

    listen(s, 1) < 0 ? exit(0): printf("Socket Listening\n");

    len = sizeof(client);

    ns = accept(s, (struct sockaddr*)&client, &len);
    if (ns == -1) {
        close(s);
        exit(0);
    }
    printf("\nSocket accepting.\n");
    int pid = fork();
    while (1) {
        if (pid > 0) {
            // parent
			printf("PID: %d\nPPID: %d\n", pid, getppid());
            printf("Parent - Type message: ");
            scanf("%s", buff2);

            sntb = send(ns, buff2, sizeof(buff2), 0);
            if (sntb == -1) {
                printf("\nMessage Sending Failed");
                close(s);
                close(ns);
                exit(0);
            }
            if (strcmp(buff2, "BYE") == 0)
                break;
        } else {
            // child
            recb = recv(ns, buff, sizeof(buff), 0);
			printf("PID: %d\nPPID: %d\n", pid, getppid());
            if (recb == -1) {
                printf("\nMessage Recieving Failed");
                close(s);
                close(ns);
                exit(0);
            }
            if (strcmp(buff, "BYE") == 0)
                break;
            printf("Child - Message Recieved: ");
            printf("%s\n", buff);
        }
    }

    close(ns);
    close(s);
}