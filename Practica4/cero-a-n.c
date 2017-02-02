/*
 Jose Luis Torres
 Practica 4
 Realiza un programa que imprima los numeros de 0 a n, 
 n debe ser ingresado por el usuario.
*/

#include<stdio.h>

int main()
{
  int i, // Indice para el ciclo
    n;  // Dato del usuario

  printf("Escribe el valor de n: ");
  scanf("%d", &n);
  for(i=0; i<=n; printf("%d\n", i++));
  return(0);
}
