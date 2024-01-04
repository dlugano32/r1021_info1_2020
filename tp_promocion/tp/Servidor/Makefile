LIB = -lallegro -lallegro_primitives -lallegro_font -lallegro_image -g
CC=gcc
CFLAGS=-Wall
DEPSS=mys.h

all: clean server 

server: server.c $(DEPSS)
	$(CC) -o server funcioness.c $< $(CFLAGS) $(LIB)

clean:
	rm -f server