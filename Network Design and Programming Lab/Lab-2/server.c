#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAXSIZE 20

void clearBuffer(char* b) {
    for (int i = 0; i < MAXSIZE; i++) b[i] = '\0';
}

int readFile(FILE* fp, char* buf, int s) {
    if (fp == NULL) {
        strcpy(buf, "File Not Found!");
        int len = strlen("File Not Found!");
        buf[len] = EOF;
        return 1;
    }

    char ch, ch2;
    for (int i = 0; i < s; i++) {
        ch = fgetc(fp);
        buf[i] = ch;
        if (ch == EOF)
            return 1;
    }
    return 0;
}

int search(FILE* fp, char* word) {
    char str[MAXSIZE];
    char* pos;
    int index, count;
    count = 0;

    while ((fgets(str, MAXSIZE, fp)) != NULL) {
        index = 0;
        while ((pos = strstr(str + index, word)) != NULL) {
            index = (pos - str) + 1;
            count++;
        }
    }
    return count;
}

void sort(FILE* fp, char* string, int s) {
    if (fp == NULL) {
        strcpy(string, "File Not Found!");
        int len = strlen("File Not Found!");
        string[len] = EOF;
        return;
    }

    int len = 0;
    for (int i = 0; i < s; i++) {
        ch = fgetc(fp);
        string[i] = ch;
        len++;
        if (ch == EOF)
            break;
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s - 1; j++) {
            if (buf[j] == '\0') {
                break;
            }
            if (buf[j] > buf[j + 1]) {
                char chTemp = buf[j];
                buf[j] = buf[j + 1];
                buf[j + 1] = chTemp;
            }
        }
    }
}

int main() {
    int port = 0;
    printf("Enter PORT: ");
    scanf("%d", &port);
    struct sockaddr_in serv_addr, cli_addr;

    // creating a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error while creating socket");
    } else {
        printf("Socket Created!\n");
    }

    // setup server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    printf("Starting the Server\n");

    // binding with IP
    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // listen to upto 5 clients
    listen(sockfd, 5);
    printf("Listening to PORT : %d ...\n", port);

    // connecting to client
    int clength = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clength);

    // interacting with client

    char buffer[MAXSIZE];
    char option[MAXSIZE];
    char string[MAXSIZE];
    char replace[MAXSIZE];
    FILE* fp;

    while (1) {
        clearBuffer(buffer);
        clearBuffer(string);
        int req = recv(newsockfd, buffer, sizeof(buffer), 0);
        puts(buffer);
        fp = fopen(buffer, "r");
        if (fp == NULL) {
            printf("Open Failed\n");
        } else {
            printf("Open Success\n");
        }
        req = recv(newsockfd, string, MAXSIZE, 0);
        puts(string);
        int count = search(fp, string);
        clearBuffer(buffer);
        if (count == 0) {
            strcpy(buffer, "String not found\n");
        } else {
            snprintf(buffer, MAXSIZE, "String found %d times", count);
        }
        // string to match
        while (1) {
            send(newsockfd, buffer, MAXSIZE, 0);
            readFile(fp, buffer, MAXSIZE);
            sort(buffer, MAXSIZE);
            send(newsockfd, buffer, MAXSIZE, 0);
            clearBuffer(buffer);
            clearBuffer(string);
        }
        if (fp != NULL)
            fclose(fp);
    }
    // close the connection
    close(sockfd);
    return 0;
}
