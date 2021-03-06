/*******
0:database.h
1:interfaces that support data query
*******/
#ifndef __DATABASE_H__
#define __DATABASE_H__

#if __cplusplus
extern "C"{
#endif
int register_new(char *user_new, char* password_new);
int is_registered(char* user);
int is_passworld_ok(char *user, char *password);
int login(char *user, char * password);
int logout(char *user, char * password);
int is_login(char *user);
int get_user_id(char *user);

#if __cplusplus
}
#endif
#endif
