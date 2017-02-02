/*
 * 
 */

#include "cliente.h"

int main(int argc, char *argv[])
{
  int s_serv; // Descriptor
  char buffer[MAX_DATA_SIZE];  // Texto recibido

  if (argc !=3) 
    { 
      error("Uso: cliente <Dirección IP> <puerto>\n");
      exit(1);
    }
  printf("Conectando ");
  if ((s_serv = createsocketclient(argv[1], atoi(argv[2])))<0)
    {
      exit(1);
    }
  printf(" conexion establecida!\n");
  /* Iniciamos el intercambio de instrucciones */
  while(1)
    {
      while(readsocket(s_serv, buffer, 1024) > 0) {
	*(buffer+strlen(buffer)-2) = 0x0; // Nos olvidamos del CR LF
	printf("REC: %s", buffer);
	printf("ENV: ");
	leeCadena(buffer);
	if (writesocket(s_serv, buffer, 1024)<0)
	  {
	    printf("Se perdio la conexion ...");
	    break;
	  }
	if (strncmp(buffer, "Fin", 3))
	  {
	    printf("Finalizando ...");
	    break;
	  }
      }
    }
  cierraSocket(s_serv);
  printf(" conexion finalizada.\n");
  exit(0);
}


/*
 * Crea un socket cliente para conectarse a la direccion "addr" haciendo uso del
 * puerto "port", devuelve el descriptor de dicho socket.
 */
int createsocketclient(char *addr, int port)
{
  int s_serv; //
  struct sockaddr_in serv_addr; // Informacion sobre la direccion del servidor
  struct hostent *server; 

  /* Intentamos resolver la direccion del servidor, tambien se verifica que sea valida */
  if ((server = gethostbyname(addr)) == NULL)
    {
      error("ERROR en la direccion proporcionada.\n");
      return(-1);
    }
  printf(".");
  if ((s_serv = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      error("ERROR: no es posible crear el socket.");
      return(-1);
    }
  printf(".");
  bzero((char *)&serv_addr, sizeof(serv_addr)); // Limpiamos la variable
  serv_addr.sin_family = AF_INET; // Usaremos direcciones IP V4
  bcopy((char *)server->h_addr, 
	(char *)&serv_addr.sin_addr.s_addr,
	server->h_length);
  serv_addr.sin_port = htons(port); // Convertimos el puerto a "network byte order" como short
  /* Intentamos la conexion con el servidor */
  if (connect(s_serv,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
      error("ERROR: no es posible realizar la conexion");
      return(-1);
    }
  printf(".");
  /* Si todo va bien devolvemos el descriptor */
  return(s_serv);
}

/*
 * Cierra el socket asociado con el descriptor recibido
 *
 */
int cierraSocket(int desc)
{
  return(close(desc));
}

/*
 * Lee la informacion del socket "sRead" y la almacena en "buffer"
 * "size_read" indica la cantidad maxima de caracteres a leer.
 * Devuelve el numero de caracteres leidos o un valor negativo en caso de error.
 */
int readsocket(int sRead, char *buffer, int size_read)
{
  int readRes; 

  memset(buffer, '\0', size_read); // Limpiamos el buffer
  if((readRes = recv(sRead, buffer, size_read, 0))<0)
    error("Error no es posible leer del socket");
  return(readRes);
}

/*
 * Escribe informacion del "buffer" en el socket sWrite.
 * "size_write" indica la cantidad maxima de caracteres a escribir.
 * Devuelve el numero de caracteres escritos o un valor negativo en caso de error.
 */
int writesocket(int sWrite, char *buffer, int size_write)
{
  int writeRes;
  
  if ((writeRes = send(sWrite, buffer, size_write, 0))<0)
      error("Error no es posible escribir en el socket");
  return(writeRes);
}

/*
 * Funcion para mostrar los mensajes de error
 */ 
void error(char *msg)
{
  fprintf(stderr, "%s", msg);
}


/*
 * Leemos el comando a enviar al servidor.
 * Devuelve en "buffer" la cadena a enviar.
 */
int leeCadena(char *buffer)
{
  int r= scanf("%s", buffer);
  fseek(stdin,0,SEEK_END);
  return(r);
}

