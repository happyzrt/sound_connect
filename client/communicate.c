/*******
0:communicate.c
1:file communicate.c privide the following functions:
    login send recv get_status set_status logout
2:programs that use libcommunicate.so should include communicate.h
*******/

#include"communicate.h"

/*
    function:login
    descriptions:login to server
*/
int login(char* name, char* password)
{
    return 0;
}

/*
    function:data_send
    descriptions:send data to server
*/
int data_send(char* send_buf, int send_size)
{
    return 0;
}

/*
    function:data_recv
    descriptions:recv data from server
*/
int data_recv(char* recv_buf, int recv_size)
{
    return 0;
}

/*
    function:get_status
    descriptions:get the user status from server
*/
int set_status(user_status *status_t)
{
    return 0;
}

/*
    function:set_status
    descriptions:set the user status to server
*/
int get_status(user_status *status_t)
{
    return 0;
}

/*
    function:logout
    descriptions:logout from server
*/
int logout()
{
    return 0;
}

/*
    function:version
    descriptions:version
*/
int version()
{
    printf("communicate api version:0.1\n");
    return 0;
}

/*
    the const communicate_api is used for programs(who call the communicate interfaces)
*/
const communicate_api_client communicate_api =
{
    .module = "communicate_client",
    login,
    data_send,
    data_recv,
    get_status,
    set_status,
    logout,
    version
};
