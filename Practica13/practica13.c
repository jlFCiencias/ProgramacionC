/*
 * Jose Luis Torres Rodriguez
 * Practica 13
 * Con el preprocesador, hacer que C pueda interpretar el siguiente código.
 */

#include<stdio.h>

#define BEGIN int main(){
#define INTEGER int
#define IF if
#define THEN {
#define PRINT printf
#define ELSE }else{
#define ENDIF }
#define END return(0);}

BEGIN
INTEGER x=10;
IF(x>=10)
THEN
PRINT("TENGO DIEZ\n");
ELSE
PRINT("REPROBARE");
ENDIF
END
