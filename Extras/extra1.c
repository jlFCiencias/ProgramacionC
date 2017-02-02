/*
  Jose Luis Torres Rodriguez
  Extras: Ejercicio1
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[], char **envp)
{
  int count;  
  float sum1, sum2;
  
  /* Argumentos en la linea de comandos */  
  /*  printf( "\nCommand-line arguments:\n" );  
  for( count = 0; count < argc; count++ )  
  printf( "  argv[%d]   %s\n", count, argv[count] );   */

  /* */
  printf("%d argumentos\n", argc);
  /*atof(argv[1]) */
  if (argc == 3)
    {
      sum1 = atof(argv[1]);
      sum2 = atof(argv[2]);
      atof(argv[1])-atoi(argv[1])!=0? {printf("Error: solo es valido para enteros"),exit(0)}:;
      printf( "Convirtiendo la cadena \"%s\" en un numero: %i\n", argv[1], atoi(argv[1]));
    }
  
  /* Variables de ambiente 
  printf( "\nEnvironment variables:\n" );  
  while( *envp != NULL )  
  printf( "  %s\n", *(envp++) );  */
  
  return(0);
}
