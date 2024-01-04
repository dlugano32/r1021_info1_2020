CC = gcc
CFLAGS = -Wall
LIB =
OBJ=main.c funciones.c
DEPS = my.h
EXE = main

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXE)