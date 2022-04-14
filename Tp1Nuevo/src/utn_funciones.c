

#include "utn_funciones.h"


void getStringPractica (char cadena[], char mensaje[], int tam ) { // Funcion de Practica, Se rompe facil

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	while(strlen(cadena)> tam){

		printf("Reingrese: ");
		fflush(stdin);
		fflush(stdin);
		gets(cadena);
	}
}
static int esNumerica(char* cadena, int limite){

	int retorno= 1; //VERDADERO
	int i;

	if(cadena[0]=='\0'){

		retorno=0;
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


 static int getString ( char *cadena, int tamMax){

	int retorno=-1;
	char buffer[4096];

	if(cadena!=NULL && tamMax>0){

		fflush(stdin);
		if(fgets(buffer, sizeof(buffer), stdin) != NULL ){

			if(buffer[strnlen(buffer,sizeof(buffer))-1]=='\n'){

				buffer[strnlen(buffer,sizeof(buffer))-1]='\0';
			}

			if(strnlen(buffer, sizeof(buffer)) <= tamMax){

				strncpy(cadena,buffer,tamMax);
				retorno=0;
			}
		}
	}

	return retorno;
}

 static int getInt(int* pResultado){

	int retorno=-1;
	char buffer[50];

	if(pResultado != NULL &&
		getString(buffer,sizeof(buffer))==0 &&
		esNumerica(buffer, sizeof(buffer)))
	{
		retorno=0;
		*pResultado=atoi(buffer);

	}

	return retorno;
}
 static int validarFloat (char *stringRecibido, int largo){

 	int retorno=1;
 	int i=0;
 	int contadorPuntos=0;

 	if(stringRecibido[0]=='\0'){

 		retorno=0;
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

  static int getFloat(float* pResultado){

	int retorno=-1;
	char buffer[50];

	if(pResultado != NULL &&
		getString(buffer,sizeof(buffer))==0 &&
		validarFloat(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		*pResultado=atof(buffer);

	}

	return retorno;
}



 static  int esTextoBasico(char* cadena){

 	int retorno= 1;
 	int i=0;

 	if(cadena[0]=='\0' || isspace(cadena[0])){

 		retorno=0;
 	}

 	for( ;cadena[i]!='\0';i++){

 		//if(cadena[i]<'A'||(cadena[i]>'Z'&&cadena[i]<'a')||(cadena[i]>'z'&&cadena[i]<'ñ')||cadena[i]>'Ñ'){

 		if(		cadena[i]<32 ||
				(cadena[i]>32&&cadena[i]<65) ||
				(cadena[i]>90&&cadena[i]<97) ||
 				(cadena[i]>122&&cadena[i]<164) ||
				cadena[i]>165)
 		{

 			retorno=0;
 			break;
 		}
 	}
 	return retorno;
 }

static int getChar(char* pResultado, int tam){

	int retorno=0;
	char buffer[4096];

	if(pResultado!=NULL &&
	getString(buffer, sizeof(buffer))==0 &&
	esTextoBasico(buffer)==1 &&
	strnlen(buffer, sizeof(buffer)) <= tam)

	{
		retorno=1;
		strncpy(pResultado, buffer, tam);
	}


	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos){

	int retorno =-1;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
			printf("%s",mensaje);

			if(getInt(&buffer)==0 &&
					buffer>=minimo &&
					buffer<=maximo)
			{

				*pResultado=buffer;
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo, float maximo, int reintentos){

	int retorno =-1; //Fallo de la funcion
	float buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
			printf("%s",mensaje);

			if(getFloat(&buffer)==0 &&
					buffer>=minimo &&
					buffer<=maximo){

				*pResultado=buffer;
				retorno=0; // Ingreso todo bien
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCharNombre(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax){

	int retorno =-1;
	char buffer[4093];

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0  && tamMax>1){

		do{
			printf("%s",mensaje);

			if(getChar(buffer, tamMax)==1){

				strncpy(pResultado,buffer,tamMax);
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}

	return retorno;
}
int PrimerasLetrasMayuscula(char*mensaje){

	int i;
	strlwr(mensaje);
	mensaje[0]=toupper(mensaje[0]);

	for(i=1;mensaje[i]!='\0';i++){

		if(isspace(mensaje[i])){
			mensaje[i+1]=toupper(mensaje[i+1]);
		}
	}
	return 1;
}
int ConcatenarNombreYApellido(char*nombre,char*apellido,char*nombreCompleto,int tam){
	int retorno=0;
	snprintf(nombreCompleto,tam,"%s, %s",apellido,nombre);
	retorno=PrimerasLetrasMayuscula(nombreCompleto);
	return retorno;
}






