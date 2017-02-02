/*
 * Practica 3
 * Jose Luis Torres Rodriguez
 * El tiempo en la mayoria de los sistemas derivados de
 * UNIX, se mide en segundos transcurridos desde el 1
 * de enero de 1970, este dato no se ha cambiado
 * desde entonces, la sincronizacion de los servidores
 * que mueven al mundo se basan en este contador.
 * El problema es que esta variable tiene un limite, y
 * cuando se alcance este limite algo interesante
 * sucederá...
 * ¿Puedes hacer un programa que diga la fecha exacta de este suceso?
 * Pistas:
 * La variable se almacena en un tipo de dato int de 32 bits.
 * time.h define el tipo de dato time_t y la función ctime(), la
 * cual regresa una cadena con formato de fecha.
 */

#include <stdio.h>
#include <limits.h>
#include <time.h>

int main()
{
  time_t tiempo=0x00efffffffffffff;

  printf("Tamanio del tipo time_t: %lu bytes\n", sizeof(time_t));
  printf("Tiempo: %lu\n", tiempo);
  printf("Maximo valor que puede almacenar: 0x00efffffffffffff\n");
  printf("Fecha del fin del mundo: %s\n", ctime(&tiempo));
  return(0);
}
