/*******
0:client.c
*******/

#include<dlfcn.h>
#include"playback.h"
#include"communicate.h"

static int playback_test();
static int communicate_test();

/*
    function:main
    descriptions:the client main function
*/
int main(int argc, char* argv[])
{
    playback_test();
    communicate_test();
    return 0;
}

/*
    function:playback_test
    descriptions:test the playback
*/
static int playback_test()
{
    void *so_handle;
    playback_api_s *pb;
    
    so_handle = dlopen("/home/seven/sound_connect/client/libplayback.so", RTLD_LAZY);
    pb = dlsym(so_handle, "playback_api");
    pb->version();
    pb->play();
    pb->stop();
    dlclose(so_handle);
    return 0;   
}

/*
    function:communicate_test
    descriptions:test the communicate
*/
static int communicate_test()
{
    void *so_handle;
    communicate_api_client *cm;
    
    so_handle = dlopen("/home/seven/sound_connect/client/libcommunicate.so", RTLD_LAZY);
    cm = dlsym(so_handle, "communicate_api");
    cm->version();
    cm->login("zrt", "xxxxxxx");
    cm->data_send("data_send", 7);
    cm->data_recv("data_recv", 7);
    cm->logout();
    dlclose(so_handle);
    return 0;   
}
