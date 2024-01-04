/*
   Programa que tiene como objetivos:
   Leer un archivo bmp.
   Crear un registro usando vector de memoria dinámica.
   Generar nombre para un nuevo archivo de salida.
   Crear un nuevo archivo de salida cambiando los colores RGB y guardar el contenido de la nueva imagen.
*/
#include"my.h"

int main( int argc, char **argv )
{
    FILE * fdin;
    FILE * fdout;
    bmpFileHeader header;           /* cabecera */
    bmpInfoHeader bInfoHeader;
    unsigned int *imgdata;          /* datos de imagen */
    unsigned short type;            /* 2 bytes identificativos */
    int i;
    unsigned char prom;
    char *arch_salida=NULL;
    union datos pixel;
    
    if(argc<2)
    {
        printf("ERROR - cantidad de argumentos incorrectos\n");
        return -1;
    }
    SEPARADOR;
    printf("\nArchivo Ingresado:\t%s\n", *(argv+1) );
    
//GENERA NOMBRE DE ARCHIVO DE SALIDA
    crea_nombre( &arch_salida , *(argv+1) , "-salida.bmp" );

    fdin = fopen( *(argv+1), "r");
    if(fdin==0)
    {
        printf("Error - no se abrio archivo\n");
        return 1;
    }

/* Leemos los dos primeros bytes */
    fread(&type, sizeof(unsigned short), 1, fdin);

    if (type !=0x4D42)          /* Comprobamos el formato */
    {
      fclose(fdin);
      return 1;
    }

    fdout = fopen( arch_salida , "w" );
    if( fdout==0 )
    {
        printf("ERROR - no se creo el archivo de salida \n");
    }

    fwrite(&type, sizeof(unsigned short), 1, fdout);
    
/* Leemos la cabecera de fichero completa */
    fread(&header, sizeof(bmpFileHeader), 1, fdin);

    fwrite(&header, sizeof(bmpFileHeader), 1, fdout);

/* Leemos la cabecera de información completa */
    fread(&bInfoHeader, sizeof(bmpInfoHeader), 1, fdin);
  
    fwrite(&bInfoHeader, sizeof(bmpInfoHeader), 1, fdout);

/* Reservamos memoria para la imagen, ¿cuánta?
     Tanto como indique imgsize */
    imgdata=(unsigned int*)malloc(bInfoHeader.imgsize);

/* Nos situamos en el sitio donde empiezan los datos de imagen,
   nos lo indica el offset de la cabecera de fichero*/
    fseek(fdin, header.offset, SEEK_SET);

/* Leemos los datos de imagen, tantos bytes como imgsize */
    fread(imgdata, bInfoHeader.imgsize,1, fdin);
        
    for (i=0; i< bInfoHeader.imgsize/4;i++)
    {
        pixel.pixel_int = *(imgdata+i) ;
        prom = (pixel.pixel_char[0] + pixel.pixel_char[1] + pixel.pixel_char[2])/3;
//[alfa,R,G,B]   dejo el alfa como estaba originalmente (indica la opacidad de cada píxel)        
        if(prom < 128)
        {
            pixel.pixel_char[0]=0x00; //BLUE
            pixel.pixel_char[1]=0x00; //GREEN
            pixel.pixel_char[2]=0x00; //RED
        }
        else
        {
            pixel.pixel_char[0]=0xff;
            pixel.pixel_char[1]=0xff;
            pixel.pixel_char[2]=0xff;
        }

        *(imgdata+i) = pixel.pixel_int ;
    }

    fwrite(imgdata, bInfoHeader.imgsize,1, fdout);
    printf("ARCHIVO DE SALIDA %s GUARDADO\n",arch_salida);

//SE LIBERA MEMORIA ANTES DE SALIR DEL PROGRAMA    
    free( arch_salida );       // es del malloc *buffer en crear nombre
    
    fclose( fdin );
    fclose( fdout );
    return 0;
}
