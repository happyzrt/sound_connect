.PHONY:aim clean git_clean

aim:client

client:client.c playback.h libplayback.so communicate.h libcommunicate.so
	gcc client.c -o client -ldl
libplayback.so:playback.c playback.h
	gcc -c -fpic playback.c -lasound
	gcc -shared playback.o -o libplayback.so
libcommunicate.so:communicate.c communicate.h
	gcc -c -fpic communicate.c
	gcc -shared communicate.o -o libcommunicate.so
clean:
	rm -rf *.o

#only remain the file in git
git_clean:
	rm -rf *.o
	rm -rf *.so *.a
	rm -rf client
