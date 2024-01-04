CC=gcc
CFLAGS=-Wall
DEPS=socket.h

all: server client

server: server_fork.c $(DEPS)
	$(CC) -o server $< $(CFLAGS)

client: client_echo.c $(DEPS)
	$(CC) -o client $< $(CFLAGS)

clean:
	rm -f client server