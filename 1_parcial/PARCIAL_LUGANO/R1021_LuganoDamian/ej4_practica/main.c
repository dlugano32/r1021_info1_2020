#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
       int i=0;
       
       while(envp[i] !=NULL)
       {
              //printf("%s", envp[i]);
              if(strstr(envp[i], *(argv+1))!= NULL)
              {
                     printf("%s\n", envp[i]);
              }
              i++;
       }
}