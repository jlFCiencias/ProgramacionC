/*
 * Practica 14: numeros aleatorios
 * Jose Luis Torres Rodriguez
 * Hay dos formas de generar numeros aleatorios, como los egresados de alguna licenciatura o como los
 * integrantes de PBSI.
 * Recuerda que todo es un archivo, lee los bytes necesarios del "device" /dev/random en tu equipo, para
 * generar un numero aleatorio, que pueda ser alojado en un entero.
 * La función read() recibe descriptor de archivo, dirección de la variable en la que se almacenaran los
 * bytes leídos, y los bytes a leer.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  int fd; //Declaracion de un descriptor de archivos.
  char *archivo="/dev/random\0"; // Ruta del archivos que queremos abrir
  unsigned long int entero; // Variable para almacenar el numero

  /* Intentamos abrir el archivo */
  if((fd=open(archivo,O_RDONLY))==-1)
    {
      fprintf(stderr,"No se pudo abrir el archivo");
      return(1);
    }

  /* Intentamos leer del archivo */ 
  if(read(fd,&entero,sizeof(unsigned long int))==-1)
    {
      /* Si no se pudo leer...*/
      fprintf(stderr,"Error al leer el entero.");
      return(1);
    }
  else /* Si pudimos leer mostramos el numero */
    printf("Valor generado: %ld\n", entero);

  /* Cerramos el archivo */
  if(close(fd)==-1)
    fprintf(stderr,"No se pudo cerrar el descriptor de archivo");
  return(0);
}
