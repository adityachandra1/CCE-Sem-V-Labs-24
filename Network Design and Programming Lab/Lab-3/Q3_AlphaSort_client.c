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
    char buff[50];
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
    printf("\nSocket connected.\n");
    printf("\n\n");
    strcpy(buff, "");
    printf("Enter alphanumeric string: ");
    scanf("%s", buff);

    sntb = send(s, buff, sizeof(buff), 0);
    if (sntb == -1) {
        close(s);
        printf("\nMessage Sending Failed");
        exit(0);
    }
    close(s);
}