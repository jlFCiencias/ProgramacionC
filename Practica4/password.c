/*
 Jose Luis Torres
 Realiza un programa de autenticacion, es decir que acepte un password, de ser correcto, imprimir "OK",
 de lo contrario imprimir "GTFOH
*/

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
  char cad[30];

  printf("Password: ");
  scanf("%s", cad);
  (strcmp(cad,"cert123"))?fprintf(stderr,"GTFOH!\n"):printf("OK\n");
  return(0);
}
