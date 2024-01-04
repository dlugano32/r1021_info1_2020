CC=gcc
CFLAGS=-Wall
DEPS=socket.h

all: clean server client

server: server_fork.c $(DEPS)
	$(CC) -o server $< $(CFLAGS)

client: cliente.c $(DEPS)
	$(CC) -o client $< $(CFLAGS)

clean:
	rm -f client server