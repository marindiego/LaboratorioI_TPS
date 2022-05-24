/*
 * ValidacionesGenericos.c
 *
 *  Created on: 9 may. 2022
 *      Author: Usuario
 */


#include "ValidacionesGenericos.h"


int isValidAlfaNumerico(char str[])
{
   int i=0;

   if(str[0]=='\0' || isspace(str[0])){

	   return -1;
   }

   while(str[i] != '\0')
   {
       if( (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return -1;
       i++;
   }
   return 1;
}

int isValidNumerica(char* cadena, int limite){

	int retorno= 1; //VERDADERO
	int i;

	if(cadena[0]=='\0' || isspace(cadena[0])){

		return 0;
	}

	for(i=0 ; i<limite && cadena[i]!='\0' ;i++){

		if(i==0 && (cadena[i]=='-' || cadena[i]=='+')){

			i=1;
			continue;
		}

		if(cadena[i]<'0'|| cadena[i]>'9'){

			retorno=0;
			break;
		}
	}
	return retorno;
}

int isValidFlotante (char *stringRecibido, int largo){

	int retorno=1;
	int i=0;
	int contadorPuntos=0;

	if(stringRecibido[0]=='\0' || isspace(stringRecibido[0])){

		return 0;
	}


	for(;  stringRecibido[i]!='\0'; i++){


		if(stringRecibido[i]<'0' || stringRecibido[i]> '9' )
		{

			if(stringRecibido[i]=='.')
			{

				contadorPuntos++;
				if(contadorPuntos>1){

					retorno=0;
					break;
				}
			}
			else
			{
				if(i==0 &&  ( stringRecibido[i] == '+' || stringRecibido[i] == '-' )){

					continue;

				}
				else{

					retorno=0;
					break;
				}
			}
		}
	}


	return retorno;
}
int isValidTextoBasico(char* cadena, int longitud)
{
	int retorno= 1;
 	int i=0;

 	if(cadena[0]=='\0' || isspace(cadena[0])){

 		retorno=0;
 	}

 	for( ;cadena[i]!='\0' && i < longitud ;i++){

 		if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
 		{
 			retorno=0;
 			break;
 		}
 	}
 	return retorno;
 }
