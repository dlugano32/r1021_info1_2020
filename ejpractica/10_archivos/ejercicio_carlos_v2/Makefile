CC = gcc
CFLAGS = -Wall
OBJ = main.o funciones.o
DEPS = my.h
EXE = out

all: clean $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o $(EXE)