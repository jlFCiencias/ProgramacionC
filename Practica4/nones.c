/*
 Jose Luis Torres
 Practica 4
 Realiza un programa que imprima los numeros nones de 1 a n, 
 n debe ser ingresado por el usuario.
*/

#include<stdio.h>

int main()
{
  int i, // Indice para el ciclo
    n;  // Dato del usuario

  printf("Escribe el valor de n: ");
  scanf("%d", &n);
  for(i=1; i<=n; printf("%d\n", i),i+=2);
  return(0);
}
