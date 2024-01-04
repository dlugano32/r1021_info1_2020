#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
        int time_now=0, time_count=0;

        while(time_now < 3)
        {
                time_count=time(NULL);
                sleep(1);
                time_now+= (time(NULL) - time_count);

                printf("Time_now=%d\n", time_now);
        }

        printf("Sali con time_now= %d\n", time_now);

        return 0;
}        