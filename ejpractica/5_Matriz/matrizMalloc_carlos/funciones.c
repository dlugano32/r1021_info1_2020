#include"my.h"

void ingresoDatos( int **m , int file , int row)
{
    int i,j;

    for ( i=0 ; i < file ; i++ )
    {
        for ( j=0 ; j < row ; j++ )
        {
            printf(" fila %d  columnas %d \t", i , j );
            scanf( "%d", &m[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}

void imprimoMatriz( int **m , int file , int row)
{
    int i,j;
    
    for (i=0 ; i<file ; i++)
    {
        for (j=0 ; j < row ; j++)
        {
            printf("%d \t",m[i][j]);
        }
        printf("\n");
    }
}
   
void liberoMemoria(int ** m , int file )
{
    int i;
    
    for (i=0 ; i<file ; i++)
    {
        free(m[i]);
    }
    free(m);   
}    
    
