/*
 * Jose Luis Torres Rodriguez
 * Practica 8
 * Ahora que entiendes un poco de formateadores de salida de datos con printf, y que estos aplican de la
 * misma manera a scanf, puedes hacer un programa pequeño utilizando user_defined.c, para crear una base
 * de datos de becarios de la onceava generacion, minimo 15 de tus compañeros
 * Ya que no hemos llegado a archivos, redirige la salida a un archivo de texto.
 * ./practica8 >> base_becarios
 * Pista. Crea un arreglo de tipo becario.
*/
#include<stdio.h>
#include<string.h>

struct becario{
	char nombre[30];
	int edad;
	float promedio;
	char procedencia[50];
	int generacion;
	unsigned int proyecto:1;
};

int main()
{
  struct becario becarios[15]={
    {"Diana Olivia", 26, 9.0, "Facultad de Ciencias", 11, 1},
    {"Armando", 24, 8.9, "Facultad de Ingenieria", 11, 1},
    {"Virgilio", 25, 9.2, "Facultad de Ingenieria", 11, 0},
    {"Giovanni", 24, 9.2, "Facultad de Ingenieria", 11, 1},
    {"Mario Arturo", 46, 9.4, "Facultad de Ciencias", 11, 1},
    {"Ivan Hernandez", 36, 9.0, "Facultad de Ciencias", 11, 0},
    {"Zaine Coronado", 24, 8.9, "Facultad de Ingenieria", 11, 0},
    {"Jennifer Mtz.", 24, 8.9, "Facultad de Ingenieria", 11, 0},
    {"Angel Gutierrez", 26, 9.3, "Universidad Insurgentes", 11, 1},
    {"Cristian", 26, 9.3, "Facultad de Ingenieria", 11, 1},
    {"Diana Gonzalez", 25, 9.4, "Facultad de Ingenieria", 11, 0},
    {"Gonzalo Lopez", 25, 9.5, "Facultad de Ciencias", 11, 0},
    {"Luis Martinez", 25, 9.4, "Facultad de Ingenieria", 11, 1},
    {"Jose Luis", 46, 9.0, "Facultad de Ciencias", 11, 1},
    {"Sergio", 26, 9.0, "Facultad de Ciencias", 11, 1}
  };
  int i;

  printf("%-20.15s %-7s Promedio \t %-25.23s \t Generacion \t Proyecto \n", "Nombre", "Edad", "Procedencia");
  for (i=0; i<15; i++)
    {
      printf("%-20.15s %-7d %-5.1f \t %-25.23s \t %-12d \t %s \n", 
	     becarios[i].nombre, becarios[i].edad, becarios[i].promedio, 
	     becarios[i].procedencia, becarios[i].generacion, (becarios[i].proyecto == 0)?"No":"Si");
    }
  return(0);
}
