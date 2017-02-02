/*
 Jose Luis Torres
 Practica 4
 Realiza un programa que calcule area de ciertas figuras geometricas, solamente, triangulo, rectangulo,
 cuadrado, dependiendo de la seleccion del usuario, se pediran, base, altura o solo lado.
*/

#include<stdio.h>

float areaTriangulo(float, float);
float areaRectangulo(float, float);

int main(int argc, char *argv[])
{
  float dato1, dato2, res;
  char opcion;
  int salir=0;

  printf("Calculo de areas version 1.0 \n\n");
  do
    {
      printf("Proporciona el tipo de figura o selecciona \"d\" para salir:");
      printf(" a) Cuadrado\n b) Rectangulo c) Triangulo\n d) Salir \n\n Opcion: ");
      scanf("%c", opcion);
      switch(c)
	{
	case 'a':
	case 'A': 
	  printf("Proporciona la medida del lado: ");
	  scanf("%f", dato1);
	  res = areaRectangulo(dato1, dato1);
	  break;
	  
	case 'b':
	case 'B':
	  printf("Proporciona la medida del lado mayor: ");
	  scanf("%f", dato1);
	  printf("Proporciona la medida del lado menor: ");
	  scanf("%f", dato2);
	  res = areaRectangulo(dato1, dato2);
	  break;

	case 'c':
	case 'C':
	  printf("Proporciona la medida de la base: ");
	  scanf("%f", dato1);
	  printf("Proporciona la medida de la altura: ");
	  scanf("%f", dato2);
	  res = areaTriangulo(dato1, dato2);      
	  break;

	case 'd':
	case 'D':
	  salir=1;

	default:
	  err=1;
	}
      (err==1)?printf("Opcion no valida.\n"):printf("Resultado: %f\n", res);
      err=0;
    } while (salir!=1);
  return(0);
}

float areaRectangulo(float lado1, float lado2)
{
  return(lado1*lado2);
}

float areaTriangulo(float base, float altura)
{
  return(base*altura/2);
}
