/*
  Jose Luis Torres Rodriguez
  Practica 1
*/

#include<stdio.h>
#include<limits.h>

char *cadena="Hola mundo";

int main()
{
  printf("signed char: minimo %d, maximo %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("signed int: min %d, max %d\n", INT_MIN, INT_MAX);
  printf("signed long int: min %ld, max %ld\n", LONG_MIN, LONG_MAX);
  printf("signed short int: min %d, max %d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned char: min %d, max %d\n", 0, UCHAR_MAX);
  return(0);
}
