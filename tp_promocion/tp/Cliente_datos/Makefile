CC=gcc
CFLAGS=-Wall
DEPSDATOS=mydatos.h
DEPSC=myc.h

all: clean generar_datos cliente

generar_datos: generar_datos.c $(DEPSDATOS)
	$(CC) -o generar_datos $< $(CFLAGS)

cliente: cliente.c $(DEPSC)
	$(CC) -o cliente funcionesc.c $< $(CFLAGS)

clean:
	rm -f generar_datos cliente