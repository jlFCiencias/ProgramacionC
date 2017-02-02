/*
 * Jose Luis Torres Rodriguez
 * Practica 4
 * Realiza un programa que imprima los primeros n numeros primos,
 * n debe ser especificado por el usuario.
 */
#include<stdio.h>
#include<stdlib.h>

int es_primo(int);

int main()
{
  long int n; // Limite para la lista de primos
  long int nprimo=0; // Cantidad de primos calculados
  long int i=3; // Indice para el ciclo
  
  printf("Introduce n: ");
  scanf("%ld", &n);

  if (n<=0) // No calculamos para negativos o cero
    {
      printf("Error: se requiere un valor positivo\n");
      exit(1);
    }

  printf("Posicion \t Valor\n");
  // Consideramos por separado el 2
  nprimo++;
  printf("%ld \t\t %ld\n", nprimo, (long int)2);
  // En el ciclo solamente tomamos en cuenta los numeros impares, a partir de 3
  while(nprimo <n)
    {
      if (es_primo(i))
	{
	  nprimo++;
	  printf("%ld \t\t %ld\n", nprimo, i);
	}
      i+=2; // Incrementamos al siguiente numero impar
    }
  exit(1);
}

/*
 * Verifica si n es numero primo
*/
int es_primo(int p)
{
  int i;
  int lim=(int)(p/2);

  if (p==2) return(1);
  if (p%2 == 0) return(0);
  for (i=3; i<lim; i++)
    {
      if (p%i == 0)
	return(0);
    }
  return(1);
}
