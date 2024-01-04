CC=gcc
CFLAGS=-Wall
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o
LIBS = -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
clean:
	rm -f *.o hellomake
