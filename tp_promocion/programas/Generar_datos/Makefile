CC = gcc
CFLAGS = -Wall
LIB =
OBJ=generar_datos.c
DEPS = my.h
EXE = main

all: clean $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f Zona* $(EXE)