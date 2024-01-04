La logica del programa esta excelente, el tema es que a veces tira segmentation fault random
es decir, a veces me deja correr el programa completo y a veces me tira segmentation fault al recibir
el segundo archivo, o al recibir el septimo archivo. 
Yo creo que el problema es cuando mando el archivo enorme por los sockets, hay veces que llegan solo 65.555 bytes
y otras veces llega completo. Por lo tanto, intente poner un sleep para que 
esto no pase mas, con el sleep es menos frecuente el segmentation fault, pero sigue pasando de vez en cuando.
El programa anda, yo le dejo una carpeta aca que se llama "archivos generados" donde estan los comprobantes de que
funciona y una captura de pantalla donde aparece mi usuario de linux y se ve que el programa termina.