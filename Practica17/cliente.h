/*
 * Cabecera de sockets de conexion
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>

// Tamanio del buffer usado en la conexion
#define MAX_DATA_SIZE 1024

// Codigos de respuestas del servidor
#define PROMPT            1
#define OK                2
#define BYE               3
#define CMD_NORECONOCIDO -1

// Protopipos
int createsocketclient(char *, int);
int cierraSocket(int);
int readsocket (int, char *, int );
int writesocket (int, char *, int);
void error(char *);
int leeCadena(char *);
void muestraAyuda();
int respuesta(char *);
