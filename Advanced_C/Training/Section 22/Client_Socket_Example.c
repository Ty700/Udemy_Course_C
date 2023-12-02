#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <stdlib.h>
#include <stddef.h>

#define SERVER_PORT 8080

//Socket Creation
short socketCreate(void) {
    short hSocket;
    printf("Creating the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//Connect to the server
int socketConnect(int hSocket) {
    int iRetval = -1;
    int ServerPort = SERVER_PORT;
    struct sockaddr_in remote= {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    iRetval = connect(hSocket,(struct sockaddr *)&remote,sizeof(struct sockaddr_in));
    return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char* Rqst, short lenRqst) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizeof(tv)) < 0) {
        printf("Time Out\n");
        exit(EXIT_FAILURE);
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

int main(int argc, char *argv[])  {
    int hSocket = 0;
    char clientMsg[1024] = {0};
    hSocket = socketCreate();

    if(hSocket == -1)   {
        perror("Error: Socket Creation");
        exit(EXIT_FAILURE);
    }

    //Connect to server
    if (socketConnect(hSocket) < 0) {
        perror("Error: Connection.\n");
        exit(EXIT_FAILURE);
    }

    printf("Sucessfully conected with server\n");

    while(1){
        printf("Enter the Message: ");

        fgets(clientMsg, sizeof(clientMsg) - 1, stdin);

        if(strncmp(clientMsg, "exit", 4) == 0){
            printf("Closing Connection\n");
            close(hSocket);
        }

        socketSend(hSocket, clientMsg, strlen(clientMsg));
    }
    return 0;
}