/*******
0:database.c
1:the file provide interfaces that support data query
*******/

#include"database.h"

/*
	function:register
	descriptions:register a new account
*/
int register_new(char *user_new, char* password_new)
{
	return 0;s
}

/*
	function:is_registered
	descriptions:check if the user is in the database
*/
int is_registered(char* user)
{
	return 1;
}

/*
	function:is_password_ok
	descriptions:check if the password is correct
*/
int is_passworld_ok(char *user, char *password)
{
	return 1;
}

/*
	function:login
	descriptions:login to database
*/
int login(char *user, char * password)
{
	return 0;
}

/*
	function:logout
	descriptions:logout from database
*/
int logout(char *user, char * password)
{
	return 0;
}

/*
	function:is_login
	descriptions:check if the user has loged in
*/
int is_login(char *user)
{
	return 1;
}
