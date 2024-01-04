CC = gcc
CFLAGS = -Wall
LIB =
OBJ=servidor.c socket.c
DEPS = socket.h
EXE = server

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXE)