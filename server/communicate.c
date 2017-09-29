/*******
0:communicate.c
1:communicate with user_client
*******/

#include "communicate.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>

#define max_user 100
#define m_buffer_size (1024*1024)
communicate_server_s g_server_info[max_user];
int g_cur_index = 0;
int g_user_sum = 0;

/*
	function:recv_data_head
	descriptions:receive data head
*/
int recv_data_head(int socket_connect, communicate_data_s *data_head)
{
	int ret;
	struct timeval timeout;
	fd_set readfds;
	
	FD_ZERO(&readfds);
	FD_SET(socket_connect, &readfds);
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	
	ret = select(socket_connect+1, &readfds, NULL, NULL, &timeout);
	if(ret < 0)
	{
		/*select error*/
	}
	else if(ret == 0)
	{
		/*timeout*/
	}
	else
	{
		if(FD_ISSET(socket_connect, &readfds))
		{
			recv(socket_connect, data_head, sizeof(communicate_data_s), 0);
		}
	}
	return 0;
}

/*
	function:recv_data_real
	descriptions:receive data head
*/
int recv_data_real(int socket_connect, char *data_real, int length)
{
	int ret;
	struct timeval timeout;
	fd_set readfds;
	
	FD_ZERO(&readfds);
	FD_SET(socket_connect, &readfds);
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	
	ret = select(socket_connect+1, &readfds, NULL, NULL, &timeout);
	if(ret < 0)
	{
		/*select error*/
	}
	else if(ret == 0)
	{
		/*timeout*/
	}
	else
	{
		if(FD_ISSET(socket_connect, &readfds))
		{
			recv(socket_connect, data_real, length, 0);
		}
	}
	return 0;
}

/*
	function:send_data_head
	descriptions:receive data head
*/
int send_data_head(int socket_connect, communicate_data_s *data_head)
{
	int ret;
	struct timeval timeout;
	fd_set writefds;
	
	FD_ZERO(&writefds);
	FD_SET(socket_connect, &writefds);
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	
	ret = select(socket_connect+1, NULL, &writefds, NULL, &timeout);
	if(ret < 0)
	{
		/*select error*/
	}
	else if(ret == 0)
	{
		/*timeout*/
	}
	else
	{
		if(FD_ISSET(socket_connect, &writefds))
		{
			send(socket_connect, data_head, sizeof(communicate_data_s), MSG_NOSIGNAL);
		}
	}
	return 0;
}

/*
	function:recv_data_head
	descriptions:receive data head
*/
int send_data_real(int socket_connect, char *data_real, int length)
{
	int ret;
	struct timeval timeout;
	fd_set writefds;
	
	FD_ZERO(&writefds);
	FD_SET(socket_connect, &writefds);
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	
	ret = select(socket_connect+1, NULL, &writefds, NULL, &timeout);
	if(ret < 0)
	{
		/*select error*/
	}
	else if(ret == 0)
	{
		/*timeout*/
	}
	else
	{
		if(FD_ISSET(socket_connect, &writefds))
		{
			send(socket_connect, data_real, length, MSG_NOSIGNAL);
		}
	}
	return 0;
}

/*
	function:task_communicate
	descriptions:task that write the shared memory and monitor the shared memory
*/
static void task_communicate(void *server_info)
{
    communicate_server_s *task_serving_p = (communicate_server_s *)server_info;
    
}

/*
	function:communicate_begin_serve
	descriptions:begin service for user
*/
int communicate_begin_serve(int socket_connect)
{
    char *user_name, *user_password, *temp;
    communicate_data_s data_head;
    char *data_buff;
    
	if(g_user_sum == max_user)
    {
        return -1;
    }
    recv_data_head(socket_connect, &data_head);
    if(data_head.data_type != 0)
    {
        return -1;
    }
    data_buff = (char *)malloc(data_head.data_length);
    recv_data_real(socket_connect, data_buff, data_head.data_length);
    
    user_name = strstr(data_buff, "user_name:") + 10;
    temp = data_buff;
    while(*temp != 0)
    {
        temp++;
    }
    user_password = strstr(temp+1, "user_password:") + 14;
    
    if(is_registered(user_name))
    {
        if(is_passworld_ok(user_name, user_password))
        {
            login(user_name, user_password);
        }
        else
        {
            printf("password isn't correct\n");
            return -1;
        }
    }
    else
    {
        printf("user not registed\n");
        return -1;
    }
    
    while(g_server_info[g_cur_index].is_used)
    {
        g_cur_index++;
        if(g_cur_index == max_user)
        {
            g_cur_index = 0;
        }
    }
	g_user_sum++;
    
    g_server_info[g_cur_index].user_id = get_user_id(user_name);
    g_server_info[g_cur_index].socket_server = socket_connect;
    pthread_mutex_init(&(g_server_info[g_cur_index].memory_mutex), NULL);
    g_server_info[g_cur_index].memory_head = (char *)malloc(m_buffer_size);
    g_server_info[g_cur_index].memory_size = m_buffer_size;
    g_server_info[g_cur_index].pointer_cur = g_server_info[g_cur_index].memory_head;
    g_server_info[g_cur_index].is_used = 1;
    int temp_task_id;
    pthread_attr_t attr;
    struct sched_param param;
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    param.sched_priority = 99;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create((pthread_t*)(&temp_task_id), &attr, task_communicate, (void *)&(g_server_info[g_cur_index]));
    g_server_info[g_cur_index].task_id = temp_task_id;
	
	free(data_buff);
    
    return 0;
}
