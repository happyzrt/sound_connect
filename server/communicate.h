/*******
0:communicate.h
1:interfaces that used for communicating with client
*******/

typedef struct
{
    int user_id;
    int socket_server;
    pthread_t task_id;
    pthread_mutex_t memory_mutex;
    char *memory_head;
    int memory_size;
    char *pointer_cur;
    int is_used;
}communicate_server_s;

typedef struct
{
    int user_id_from;
    int user_id_to;
    int data_type;
    int data_length;
}communicate_data_s;

int communicate_begin_serve(int socket_connect);

