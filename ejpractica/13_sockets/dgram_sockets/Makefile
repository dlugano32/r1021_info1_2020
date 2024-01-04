CC=gcc
CFLAGS=-Wall
DEPS=mylib.h

all: clean sendto recvfrom

sendto: sendto.c $(DEPS)
	$(CC) -o send $< $(CFLAGS)

recvfrom: recvfrom.c $(DEPS)
	$(CC) -o recv $< $(CFLAGS)

clean:
	rm -f recv send