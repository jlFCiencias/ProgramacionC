/*
 Jose Luis Torres
 Practica 4
 Realiza un programa que tome como parametro un caracter, hecho esto, 
 regresa su equivalente hexadecimal en la terminal, el formato es tu decision.
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
  (argc<2)?fprintf(stderr,"Se requiere un caracter como argumento.\n"):printf("Valor hexadecimal de %c: 0x%x\n", argv[1][0], argv[1][0]);
  return(0);
}
