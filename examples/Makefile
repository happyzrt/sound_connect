.PHONY:target clean
target:latency pcm pcm_min rawmidi timer
latency:latency.c
	gcc latency.c -o latency -lasound -lm
pcm:pcm.c
	gcc pcm.c -o pcm -lasound -lm
pcm_min:pcm_min.c
	gcc pcm_min.c -o pcm_min -lasound
rawmidi:rawmidi.c
	gcc rawmidi.c -o rawmidi -lasound
timer:timer.c
	gcc timer.c -o timer -lasound
clean:
	rm -rf latency pcm pcm_min rawmidi timer
