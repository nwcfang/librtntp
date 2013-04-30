#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <tio.h>

int resSocket = 0;

void sighandle(int signum)
{
    if(signum == SIGINT)
    close(resSocket);
    puts( "\nServer is off" );
}

tio_param tp[] = {
    {"a:", "IP", "Строка с IP адресом сервера"},
    {"p:", "PORT", "Номер порта"},
    {NULL, NULL, NULL}
};

int main(int argc, const char* argv[])
{
    struct sockaddr_in addr;
    int bytes_read;
    struct tm sTime;
    tioInit("v0.1", "Сервер UDP", tp, argc, argv );
    resSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(resSocket < 0)
    {
        perror("socket");
        exit(1);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(tioGetDefL("PORT", 36000));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(resSocket, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }
    signal(SIGINT, sighandle);

    while(1)
    {
        bytes_read = recv(resSocket, &sTime, sizeof(sTime), 0);
        if(bytes_read <= 0) 
            break;
        printf("%s", asctime(&sTime));
    }
    
    return 0;
}
