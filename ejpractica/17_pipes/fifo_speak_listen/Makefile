CC = gcc
CFLAGS = -Wall
LIB =
OBJ_1= fifo_speak.c
OBJ_2= fifo_listen.c
EXE_1 = speak
EXE_2=listen

all: $(EXE_1) $(EXE_2)

$(EXE_1): $(OBJ_1)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXE_2): $(OBJ_2)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(EXE_1) $(EXE_2)