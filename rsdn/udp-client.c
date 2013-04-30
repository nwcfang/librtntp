#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <tio.h>

char message[] = "Hello there!";

struct tm *sTime;
time_t rawTime;

tio_param tp[] = {
    {"a:", "IP", "Строка с IP адресом сервера"},
    {"p:", "PORT", "Номер порта"},
    {NULL, NULL, NULL}
};

int main(int argc, const char* argv[] )
{
    int sock;
    struct sockaddr_in addr;

    tioInit("v0.1", "Клиент UDP", tp, argc, argv );
    
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(tioGetDefL("PORT", 36000));

     
    char buff[20];
    tioGetDefS("IP","127.0.0.1", buff, 20);
    inet_aton(buff, &(addr.sin_addr));
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }
    time(&rawTime);
    sTime = localtime(&rawTime);
    

    send(sock, sTime, sizeof(*sTime), 0);

    
    close(sock);
    tioFinish(0);
        
    return 0;
}


