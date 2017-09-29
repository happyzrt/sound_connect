.PHONY:target
target:
	gcc -c database.c
	gcc -c communicate.c
	gcc -c server.c
	gcc -o server server.o communicate.o database.o -lpthread
