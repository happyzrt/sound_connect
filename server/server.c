/*******
0:server.c
1:service for user_client
*******/

#include"communicate.h"
#include"database.h"

static int is_service down();

/*
	function:main
	descriptions:the main function
*/
int main(int argc,char* argv[])
{
    int serving = 1;
    int socket_server,socket_connect;
    struct sockaddr_in addr_server;
    extern int errno;
    
    socket_server = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_server < 0)
    {
        printf("create socket_server error:%s\n", strerror(errno));
        return -1;
    }
    
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_server.sin_port = htons(7014);
    bind(socket_server, (struct sockaddr *)addr_server, sizeof(addr_server));
    
    listen(socket_server, 7);
    while(serving)
    {
        int addr_length = sizeof(addr_server);
        socket_connect = accept(socket_server, (struct sockaddr *)&addr_server, &addr_length);
        if(socket_connect < 0)
        {
            printf("accept error:%s\n", strerror(errno));
            return -1;
        }
        
        //start a thread to provide service for user
        communicate_begin_serve(socket_connect);
        
        if(is_service_down())
        {
            close(socket_server);
            serving = 0;
        }
    }
    printf("service exit success\n");
	return 0;
}

/*
    function:is_service_down
    descriptions:check if we should stop service
*/
static int is_service_down()
{
    return 0;
}
