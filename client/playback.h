/*******
0:playback.h
1:programs that use libplayback.so should include playback.h
2:program can dlsym(so_handle, "playback_api") to get a pointer pointing to a const struct playback_api_s
*******/
#ifdef __cplusplus
extern "C"{
#endif

#ifndef playback_h
#define playback_h
#endif

typedef struct
{
    int (*play)();
    int (*stop)();
    int (*version)();
}playback_api_s;

#ifdef __cplusplus
}
#endif
