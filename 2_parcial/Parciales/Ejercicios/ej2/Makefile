CC = gcc
CFLAGS = -Wall
LIB =
OBJ_1=servidor.c socket.c
OBJ_2=cliente.c socket.c
DEPS = socket.h
EXE_1 = server
EXE_2 = client

all: $(EXE_1) $(EXE_2)

$(EXE_1): $(OBJ_1)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXE_2): $(OBJ_2)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXE_1) $(EXE_2)