CC = gcc
CFLAGS = -Wall
LIB =
OBJ_1=A_process.c
OBJ_2=B_process.c
DEPS =my.h
EXE_1 = A_main
EXE_2= B_main

all: $(EXE_1) $(EXE_2)

$(EXE_1): $(OBJ_1)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXE_2): $(OBJ_2)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXE_1) $(EXE_2)