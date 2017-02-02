/*
 Jose Luis Torres
 Practica 4
 Implementa de manera recursiva el calculo de factorial.

*/

#include<stdio.h>

long factorial(int);

int main()
{
  int n;

  printf("Calculo de factorial \n Proporciona un numero entero mayor que cero: ");
  scanf("%d", &n);
  (n<0)?fprintf(stderr, "Error: se requiere un valor positivo.\n"):printf("Factorial de %d: %ld\n", n, factorial(n));
  return(0);
}

long factorial(int n)
{
  return((n>0)?n*factorial(n-1):1);
}
