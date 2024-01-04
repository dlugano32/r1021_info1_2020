CC=gcc
CFLAGS=-Wall
DEPS=chat.h

all: server client

server: server_chat.c $(DEPS)
	$(CC) -o server $< $(CFLAGS)

client: client_chat.c $(DEPS)
	$(CC) -o client $< $(CFLAGS)

clean:
	rm -f client server