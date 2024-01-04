CC = gcc
CFLAGS = -Wall
LIB =
OBJ=cliente.c funciones.c
DEPS = my.h
EXE = main

all: clean $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXE)