.PHONY:aim clean git_clean

aim:client

client:client.c playback.c playback.h
	gcc -c -fpic playback.c
	gcc -shared playback.o -o libplayback.so
	gcc client.c -o client -ldl

clean:
	rm -rf *.o

#only remain the file in git
git_clean:
	rm -rf *.o
	rm -rf *.so *.a
	rm -rf client
