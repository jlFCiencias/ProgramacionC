/*
 * Jose Luis Torres Rodriguez
 *
 * Practica 7
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
  char *pass=(char *) calloc(sizeof(char),60); /* Password proporcionado por el usuario*/
  char *passCifrado=(char *) calloc(sizeof(char),60); /* Password cifrado */
  char *passDesCifrado=(char *) calloc(sizeof(char),60); /* Password descifrado */
  char *cadenaXOR=(char *) calloc(sizeof(char),60); /* Cadena para XOR */
  int t, i;

  /* Solicitamos el password al usuario */
  printf("Introduce tu password: ");
  scanf("%s", pass);
  
  /* Creamos una cadena aleatoria para aplicar el XOR, de la misma longitud que el password */
  srand(time(NULL));
  for(i=0, t = strlen(pass); i<t; i++)
      cadenaXOR[i]=64+rand()%(122-64);

  for(i=0; i<t; i++) /* Creamos la cadena cifrada */
      passCifrado[i]=pass[i]^cadenaXOR[i];
  
  for(i=0; i<t; i++) /* Desciframos la cadena */
      passDesCifrado[i]=passCifrado[i]^cadenaXOR[i];

  printf("Password cifrado: %s\n",passCifrado);
  printf("Cadena aleatoria: %s\n", cadenaXOR);
  printf("Password descifrado: %s\n",passDesCifrado);
  free(pass);
  free(passCifrado);
  free(passDesCifrado);
  free(cadenaXOR);
}
