/*******
0:playback.h
1:programs that use libplayback.so should include playback.h
*******/
#ifdef __cplusplus
extern "C"{
#endif
#ifndef playback_h
#define playback_h
typedef struct
{
    int (*play)();
    int (*stop)();
    int (*version)();
}playback_api_s;
#ifdef __cplusplus
}
#endif
