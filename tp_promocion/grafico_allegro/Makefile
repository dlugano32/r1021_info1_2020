CC = gcc
CFLAGS = -Wall
LIB = -lallegro -lallegro_primitives -lallegro_font -lallegro_image
OBJ=grafico_barras.c
DEPS = my.h
EXE = main

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIB)

clean:
	rm -f $(EXE)