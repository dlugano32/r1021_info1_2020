#include <stdio.h>
#include <time.h>

int main (void) 
{
        time_t curtime;

        time(&curtime);

        printf("Current time = %s", ctime(&curtime));

        return(0);
}