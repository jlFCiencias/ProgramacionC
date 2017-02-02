/*
 * Jose Luis Torres Rodriguez
 *
 * Practica 9
 *
 * Crea un programa que imprima el ultimo elemento que se reciba por linea de comandos, se debe cumplir la
 * condicion de que debe de tenerse al menos un elemento en la lista de argumentos
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
  (argc<2)?fprintf(stderr, "Error: se requiere al menos un argumento \n"):printf("Ultimo argumento: %s\n",argv[argc-1]);
  return(0);
}
