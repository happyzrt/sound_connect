/*******
0:communicate.h
1:the client communicate 
*******/
#ifdef __cplusplus
extern "C"{
#endif
#ifndef communicate_h
#define communicate_h

#include<sys/types.h>
#include<sys/socket.h>

typedef struct
{
    int status;
}user_status;

typedef struct
{
    const char* module;
    int (*login)(char* name, char* password);
    int (*data_send)(char* send_buf, int send_size);
    int (*data_recv)(char* recv_buf, int recv_size);
    int (*set_status)(user_status *status_t);
    int (*get_status)(user_status *status_t);
    int (*logout)();
    int (*version)();
}communicate_api_client;
#endif
#ifdef __cplusplus
}
#endif
