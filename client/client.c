/*******
0:client.c
*******/
#include<dlfcn.h>
#include"playback.h"

static int playback_test();

/*
    function:main
    descriptions:the client main function
*/
int main(int argc, char* argv[])
{
    playback_test();
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
