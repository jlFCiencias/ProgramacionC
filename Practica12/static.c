/*
 * Jose Luis Torres Rodriguez
 * Practica 12
 * Cambia el programa static.c para que todas las variables "vivan" en el "heap", o que al menos todo se
 * trate como variable de tipo "apuntador".
 * Si no puedes hacer lo anterior, solamente redúcelo.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int i=0;
  char *c=(char *)calloc(sizeof(char),5);
  strcpy(c, "hola");
  while(*(c+i) != '\0') printf("%c\n", *(c+i++));
  return(0);
}
