#include <stdio.h>
#include <stdlib.h>
#define N 3

struct fifo
{
       int *input;
       int *output;
};

struct fifo * fifoCreate (int N);
int fifoWrite (struct fifo *p, int *dataPtr, int dataSize);
int fifoRead (struct fifo *p, int *dataPtr, int dataSize);
int fifoDestroy (struct fifo *p);