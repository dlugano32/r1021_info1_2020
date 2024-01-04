CC = gcc
CFLAGS = -Wall
LIB = -lallegro -lallegro_primitives -lallegro_font -lallegro_image
OBJ=server.c funciones.c
DEPS = my.h
EXE = main

all:clean $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIB)

clean:
	rm -f $(EXE)