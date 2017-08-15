/*******
0:playback.c
1:file playback.c provided functions:
    a:audio playback
    b:audio process
    c:handle volume
2:when compiling, we should link libasound.so and a file libplayback.so will produced
3:programs that use libplayback.so should include playback.h
*******/
#include"playback.h"

/*
    function:play
    decriptions:play audio
*/
int play()
{
    return 0;
}

/*
    fucntion:stop
    descriptions:stop audio
*/
int stop()
{
    return 0;
}

/*
    function:version
    descriptions:version
*/
int version()
{
    printf("playback api version:0.1\n");
    return 0;
}

/*
    the const playback_api is used for programs(who call the playback interfaces)
*/
const playback_api_s playback_api =
{
    .module = "playback",
    play,
    stop,
    version
};
