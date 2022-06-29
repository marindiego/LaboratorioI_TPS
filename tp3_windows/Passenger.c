/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

Passenger* Passenger_new()
{
	return (Passenger*) malloc(sizeof(Passenger));
}

void Passenger_delete(Passenger* this)
{
	free( this);
}

Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr,char*codigoVueloStr, char* tipoPasajeroStr,char* estadoVueloStr)
{
	Passenger* this=Passenger_new();

	if (this!= NULL && idStr!= NULL && nombreStr !=NULL && apellidoStr!=NULL && precioStr!=NULL && codigoVueloStr!=NULL && estadoVueloStr!=NULL ) {

		if (	!Passenger_setIdTxt(this, idStr) &&
				!Passenger_setNombre(this, nombreStr) &&
				!Passenger_setApellido(this, apellidoStr) &&
				!Passenger_setPrecioTxt(this, precioStr) &&
				!Passenger_setCodigoVuelo(this, codigoVueloStr) &&
				!Passenger_setTipoPasajero(this, tipoPasajeroStr)&&
				!Passenger_setEstadoVuelo(this, estadoVueloStr) )
		{
			return this;
		}
	}

	Passenger_delete(this);
	return NULL;
}
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio, char* codigoVuelo,char* tipoPasajero, char* estadoVuelo)
{
	Passenger* this;

	this= Passenger_new();

	if (this!= NULL && nombre !=NULL && apellido!=NULL && codigoVuelo!=NULL && estadoVuelo!=NULL ) {

		if (	Passenger_setId(this, id)==-1 ||
				Passenger_setNombre(this, nombre)==-1 ||
				Passenger_setApellido(this, apellido)==-1 ||
				Passenger_setPrecio(this, precio)==-1 ||
				Passenger_setCodigoVuelo(this,codigoVuelo) ==-1 ||
				Passenger_setTipoPasajero(this,tipoPasajero)==-1 ||
				Passenger_setEstadoVuelo(this, estadoVuelo) == -1)

		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}


void Passenger_printOne (Passenger* this)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	char tipoPasajero[50];
	char estadoVuelo[50];


	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this, apellido);
	Passenger_getPrecio(this, &precio);
	Passenger_getCodigoVuelo(this, codigoVuelo);
	Passenger_getTipoPasajero(this, tipoPasajero);
	Passenger_getEstadoVuelo(this, estadoVuelo);



	printf("%-5d       %-10s          %-12s        %9.2f          %12s               %-9s             %9s \n",
			id,
			nombre,
			apellido,
			precio,
			codigoVuelo,
			tipoPasajero,
			estadoVuelo);
	//printf(" -------------------------------------------------------------------------------------------------------------------\n");
}

void Passenger_printfPassengerOptionsMenu ()
{
	printf(
			"\n1) Cargar los datos de los Pasajeros desde el archivo data.csv (modo texto).\n"
			"2) Cargar los datos de los Pasajeros desde el archivo data.csv (modo binario).\n"
			"3) Alta de empleado\n"
			"4) Modificar datos de empleado\n"
			"5) Baja de empleado\n"
			"6) Listar Pasajeros\n"
			"7) Ordenar Pasajeros\n"
			"8) Guardar los datos de los Pasajeros en el archivo data.csv (modo texto).\n"
			"9) Guardar los datos de los Pasajeros en el archivo data.csv (modo binario).\n"
			"10) Salir\n");
}

void Passenger_printReturnRemove (int retorno)
{
	switch (retorno) {

		case 0:
			printf("\n\t!.......BAJA COMPLETADA........!\n\n");
			break;
		case -1:
			printf("\n\tNo hay pasajeros cargados en el programa\n\n");
			break;
		case 2:
			printf("\n\tNo existe ese id o fue dado de baja antes\n");
			break;
	}
}
void Passenger_printReturnAdd(int retorno)
{
	switch (retorno)
	{
		case 0:
			printf("\n\t!--------ALTA COMPLETADA--------!\n\n");
			break;
		case 1:
			printf("\n\t!---------ALTA CANCELADA--------!\n\n");
			break;
		case 2:
			printf("\n\tIngresa bien los datos, volve a intentarlo\n\n");
			break;
		case -1:
			printf("\n\tNULL linked list \n\n");
			break;
	}
}
void Passenger_printReturnEdit(int retorno)
{
	switch (retorno)
	{
		case 0:
			printf("\n\t!--------MODIFICAR COMPLETADA--------!\n\n");
			break;
		case 1:
			printf("\n\t!---------MODIFICAR CANCELADA--------!\n\n");
			break;
		case 2:
			printf("\n\tIngresa bien los datos, volve a intentarlo\n\n");
			break;
		case -1:
			printf("\n\tNULL linked list \n\n");
			break;
	}
}
void Passenger_printOptionsTypePassenger ()
{
	printf("\n"
			"1)FirstClass\n"
			"2)ExecutiveClass\n"
			"3)EconomyClass\n\n");

}
void Passenger_printOptionsEstadoVuelo()
{
	printf("\n"
			"1)Aterrizado\n"
			"2)En Vuelo\n"
			"3)Demorado\n\n");

}


int Passenger_setId(Passenger* this,int id)
{
	int set=-1;
	static int maxId =-1;
	if (this!=NULL) {

		set=0;
		if (id < 0) {

			maxId++;
			this->id= maxId;
		}
		else{
			if(id > maxId){
				maxId = id;
				this->id = id;
			}
		}
	}

	return set;;
}
int Passenger_setIdTxt(Passenger* this,char* id)
{
	int retorno = -1;
	int auxId;
	if (this != NULL && isValidNumerica(id,10)) {

		auxId = atoi(id);
		if (auxId > 0) {

			retorno = 0;
			this->id = auxId;
		}
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int get=-1;

	if (this!=NULL && id !=NULL ) {

		*id=this->id;
		get=0;
	}

	return get;
}
int Passenger_getIdTxt(Passenger* this,char* id)
{
	int get=-1;

	if (this!=NULL && id !=NULL ) {

		sprintf(id,"%d",this->id);
		get=0;
	}

	return get;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int name=-1;

	if (this!=NULL && nombre !=NULL && isValidTextoBasico(nombre, NOMBRE_len ) ) {

		strcpy(this->nombre,nombre);
		name=0;
	}

	return name;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int estado=-1;

	if (this!=NULL &&nombre !=NULL  ) {

		strcpy(nombre,this->nombre);
		PrimerasLetrasMayuscula(nombre);
		estado=0;
	}

	return estado;
}

int Passenger_getNewNombreFromStdin (Passenger* this)
{
	int retorno = -1;
	char buffer[50];

	if (this!=NULL ) {

		retorno = 2; //Invalid Opcion
		if (!utn_getCharNombre(buffer, "\nNuevo Nombre: ", "\n\tError, nombre invalido\n\n", 1, NOMBRE_len)) {

			retorno = 1;// retorno cancelled
			if (!Passenger_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				PrimerasLetrasMayuscula(buffer);
				Passenger_setNombre(this, buffer);

				retorno = 0; //ok
			}
		}
	}
	return retorno;
}
int Passenger_getNewApellidoFromStdin (Passenger* this)
{
	int retorno = -1;
	char buffer[50];

	if (this!=NULL ) {

		retorno = 2; //Invalid Opcion
		if (!utn_getCharNombre(buffer, "\nNuevo Apellido: ", "\n\tError, apellido invalido\n\n", 1, NOMBRE_len)) {

			retorno = 1;// retorno cancelled
			if (!Passenger_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				PrimerasLetrasMayuscula(buffer);
				Passenger_setApellido(this, buffer);

				retorno = 0; //ok
			}
		}
	}
	return retorno;
}
int Passenger_getNewPrecioFromStdin (Passenger* this)
{
	int retorno = -1;
	float buffer;

	if (this!=NULL ) {

		retorno = 2; //Invalid Opcion
		if (!utn_getFloat(&buffer, "\nNuevo Precio: ", "\n\tError, Precio invalido\n\n", 1, 100000,1)) {

			retorno = 1;// retorno cancelled
			if (!Passenger_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				Passenger_setPrecio(this, buffer);
				retorno = 0; //ok
			}
		}
	}
	return retorno;
}
int Passenger_getNewCodigoVueloFromStdin (Passenger* this)
{
	int retorno = -1;
	char buffer[50];

	if (this!=NULL ) {

		retorno = 2; //Invalid Opcion
		if (!utn_getAlphaNumerico(buffer, "\nNuevo Codigo Vuelo: ", "\n\tError, CodigoVuelo invalido\n\n",1,CODIGOVUELO_len)) {

			retorno = 1;// retorno cancelled
			if (!Passenger_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				Passenger_setCodigoVuelo(this, buffer);

				retorno = 0; //ok
			}
		}
	}
	return retorno;
}
int Passenger_getNewTipoPasajeroFromStdin (Passenger* this)
{
	int retorno = -1;
	char buffer[50];

	if (this!=NULL ) {

		retorno = 2; //Invalid Opcion
		if (!Passenger_getTipoPasajeroFromStdin(buffer)) {

			retorno = 1;// retorno cancelled
			if (!Passenger_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				Passenger_setTipoPasajero(this, buffer);

				retorno = 0; //ok
			}
		}
	}
	return retorno;
}
int Passenger_getNewEstadoVueloFromStdin(Passenger* this)
{
	int retorno = -1;
	char buffer[50];

	if (this!=NULL ) {

		retorno = 2; //Invalid Opcion
		if (!Passenger_getEstadoVueloFromStdin(buffer)) {

			retorno = 1;// retorno cancelled
			if (!Passenger_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				Passenger_setTipoPasajero(this, buffer);

				retorno = 0; //ok
			}
		}
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=-1;

	if (this!=NULL && apellido !=NULL ) {

		strcpy(this->apellido,apellido);
		retorno=0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=-1;

	if (this!=NULL && apellido !=NULL  ) {

		strcpy(apellido,this->apellido);
		PrimerasLetrasMayuscula(apellido);
		retorno=0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if (this!=NULL && codigoVuelo !=NULL && isValidAlfaNumerico(codigoVuelo)) {

		retorno=0;
		strcpy(this->codigoVuelo,codigoVuelo );
		strupr(codigoVuelo);
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if (this!=NULL && codigoVuelo!=NULL ) {

		strcpy(codigoVuelo,this->codigoVuelo);
		strupr(codigoVuelo);

		retorno=0;
	}
	return retorno;
}
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=-1;

	if (this!=NULL && isValidTextoBasico(tipoPasajero, 12) ) {

		strcpy(this->tipoPasajero,tipoPasajero);
		retorno=0;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=-1;

	if (this!=NULL && tipoPasajero!=NULL ) {

		strcpy(tipoPasajero,this->tipoPasajero);
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajeroFromStdin(char* tipoPasajero)
{
	int retorno=-1;
	int buffer;

	if (tipoPasajero!=NULL) {

		Passenger_printOptionsTypePassenger();
		if (!utn_getNumero(&buffer, "\nTipo de Pasajero: ", "\n\tError, Tipo Invalido\n",1,3,1)) {

			switch (buffer) {
				case 1:
					strcpy(tipoPasajero,"FirstClass");
					break;
				case 2:
					strcpy(tipoPasajero,"ExecutiveClass");
					break;
				case 3:
					strcpy(tipoPasajero,"EconomyClass");
					break;
			}
			retorno = 0;
		}
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if (this!=NULL && precio > 0) {
		retorno = 0;
		this->precio = precio;
	}

	return retorno;
}
int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int retorno = -1;
	float auxPrecio;

	if (this!=NULL && isValidFlotante(precio, 6)) {

		auxPrecio = atof(precio);
		if (auxPrecio > 0) {

			retorno = 0;
			this->precio =auxPrecio;
		}
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if (this!=NULL && precio != NULL) {

		retorno = 0;
		*precio=this->precio ;
	}

	return retorno;
}
int Passenger_getPrecioTxt(Passenger* this,char * precio)
{
	int retorno = -1;

	if (this!=NULL && precio != NULL) {

		retorno = 0;
		sprintf(precio,"%f",this->precio);
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno=-1;

	if (this!=NULL && estadoVuelo !=NULL && isValidTextoBasico(estadoVuelo, ESTADOVUELO_len)) {

		strcpy(this->estadoVuelo,estadoVuelo);
		retorno=0;
	}

	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if (this!=NULL && codigoVuelo!=NULL ) {

		strcpy(codigoVuelo,this->estadoVuelo);
		retorno=0;
	}
	return retorno;
}
int Passenger_getEstadoVueloFromStdin(char* estadoVuelo)
{
	int retorno=-1;
	int buffer;

	if (estadoVuelo!=NULL) {

		Passenger_printOptionsEstadoVuelo();
		if (!utn_getNumero(&buffer, "\nEstado de Vuelo: ", "\n\tError, Estado Invalido\n",1,3, ESTADOVUELO_len)) {

			switch (buffer) {
				case 1:
					strcpy(estadoVuelo,"Aterrizado");
					break;
				case 2:
					strcpy(estadoVuelo,"En Vuelo");
					break;
				case 3:
					strcpy(estadoVuelo,"Demorado");
					break;
			}
			retorno = 0;
		}
	}
	return retorno;
}

void Passenger_printOpcionsSort ()
{
	printf("\n"
			"1) Ordenar Por Nombre\n"
			"2) Ordenar Por Apellido\n"
			"3) Ordenar Por Precio\n"
			"4) Ordenar Por Codigo de Vuelo\n"
			"5) Ordenar Por Tipo de Pasajero\n"
			"6) Ordenar Por Estado de Vuelo\n"
			"7) Salir\n\n");
}

void Passenger_printOpcionMayorMenor ()
{
	printf("\n"
			"0)Ordenar de mayor a menor\n"
			"1)Ordenar de menor a mayor\n\n");
}
void Passenger_printOptionsModificar ()
{
	printf(	"\n1) Nombre\n"
			"2) Apellido\n"
			"3) Precio\n"
			"4) Codigo de Vuelo\n"
			"5) Tipo De Vuelo\n"
			"6) Estado De Vuelo\n"
			"7) Salir\n\n");
}


int Passenger_compareByName (void* pass1,void* pass2)
{
	int retorno =-1;

	Passenger*this_1=(Passenger*)pass1;
	Passenger* this_2=(Passenger*)pass2;

	char nombre1[50];
	char nombre2[50];

	if (	!Passenger_getNombre(this_1,nombre1) &&
			!Passenger_getNombre(this_2, nombre2)) {

		retorno = strcmp(nombre1,nombre2);
	}
	return retorno;
}

int Passenger_compareByLastName (void* pass1,void* pass2)
{
	int retorno =-1;

	Passenger*this_1=(Passenger*)pass1;
	Passenger* this_2=(Passenger*)pass2;

	char apellido1[50];
	char apellido2[50];

	if (	!Passenger_getApellido(this_1, apellido1) &&
			!Passenger_getApellido(this_2, apellido2)) {

		retorno = strcmp( apellido1, apellido2);
	}
	return retorno;
}

int Passenger_compareByPrice (void* pass1,void* pass2)
{
	int retorno =0;

	Passenger* this_1=(Passenger*)pass1;
	Passenger* this_2=(Passenger*)pass2;

	float aux1;
	float aux2;

	if (	!Passenger_getPrecio(this_1, &aux1) &&
			!Passenger_getPrecio(this_2, &aux2)) {

		if(aux1>aux2)
			retorno=1;
		else
			if(aux1<aux2)
				retorno=-1;
	}

	return retorno;
}
int Passenger_compareByFlyCode (void* pass1,void* pass2)
{
	int retorno =-1;

	Passenger*this_1=(Passenger*)pass1;
	Passenger* this_2=(Passenger*)pass2;

	char flyCode1[50];
	char flyCode2[50];

	if (	!Passenger_getCodigoVuelo(this_1, flyCode1) &&
			!Passenger_getCodigoVuelo(this_2, flyCode2)) {

		retorno = strcmp( flyCode1, flyCode2);
	}
	return retorno;
}
int Passenger_compareByTipoPasajero (void* pass1,void* pass2)
{
	int retorno =-1;

	Passenger*this_1=(Passenger*)pass1;
	Passenger* this_2=(Passenger*)pass2;

	char TipoPasajero1[50];
	char TipoPasajero2[50];

	if (	!Passenger_getTipoPasajero(this_1,TipoPasajero1) &&
			!Passenger_getTipoPasajero(this_2, TipoPasajero2)) {

		retorno = strcmp(TipoPasajero1, TipoPasajero2);
	}
	return retorno;
}
int Passenger_compareByEstadoVuelo (void* pass1,void* pass2)
{
	int retorno =-1;

	Passenger*this_1=(Passenger*)pass1;
	Passenger* this_2=(Passenger*)pass2;

	char EstadoVuelo1[50];
	char EstadoVuelo2[50];

	if (	!Passenger_getEstadoVuelo(this_1,EstadoVuelo1) &&
			!Passenger_getEstadoVuelo(this_2, EstadoVuelo2)) {

		retorno = strcmp( EstadoVuelo1, EstadoVuelo2);
	}
	return retorno;
}

int Passenger_findPassengerById (LinkedList* ListPassengers, int id)
{
	Passenger* buffer;
	int index;
	int idAux;
	int len_List_passenger = ll_len(ListPassengers);

	for (int i = 0; i < len_List_passenger; i++) {

		buffer = (Passenger*) ll_get(ListPassengers, i);
		Passenger_getId(buffer, &idAux);
		if (idAux == id) {

			index =i;
			break;
		}
	}
	return index;
}

/** \brief Asks a number
 *
 * \param mensaje char*
 * \return int Return (-1) if NULL masage - (0) if cancelled - (1) if ok
 */
int Passenger_confirmDecision (char* mensaje)
{
	int confirmar = -1;// Pointer NULL

	if(mensaje!=NULL)
	{
		confirmar = -3;// Invalid Opcion
		if (!utn_getNumero(&confirmar, mensaje, "\n\tSolo 1 o 0\n", 0, 1, 1)) {

			if (confirmar) {

				confirmar = 0; //Confirmar Decision
			}else{

				confirmar = 1; // Cancel decision
			}
		}
	}
	return confirmar;
}
Passenger* Passenger_addOneFromStdin (int* id)
{
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	char tipoPasajero[50];
	char estadoVuelo[50];

	Passenger* buffer;

	if (	!utn_getCharNombre(nombre,"\nNombre: ", "\n\tError, nombre Invalido\n", 1, NOMBRE_len) &&
			!utn_getCharNombre(apellido, "Apellido: ", "\n\tError, nombre Invalido\n", 1, NOMBRE_len) &&
			!utn_getFloat(&precio, "Precio: ", "\n\tError, precio Invalido\n\n", 0,100000,1) &&
			!utn_getAlphaNumerico(codigoVuelo,"Codigo de Vuelo: ", "\n\tError, codigo de vuelo Invalido\n", 1, CODIGOVUELO_len)&&
			!Passenger_getTipoPasajeroFromStdin(tipoPasajero) &&
			!Passenger_getEstadoVueloFromStdin(estadoVuelo))
	{
		buffer = Passenger_newParametros(*id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
	}
	else{
		buffer = NULL;
	}

	return buffer;
}
int Passenger_editOneFromStdin (Passenger* this)
{
	int retorno = -1;
	int opcion;

	if (this!=NULL) {

		do{
			Passenger_printOptionsModificar();


			if (!utn_getNumero(&opcion, "Opcion: ", "\n\tError, numero invalido\n\n", 1, 10, 0)) {

				Passenger_printOne(this);

				switch (opcion) {
					case 1:
						retorno = Passenger_getNewNombreFromStdin(this);
						break;
					case 2:
						retorno = Passenger_getNewApellidoFromStdin(this);
						break;
					case 3:
						retorno = Passenger_getNewPrecioFromStdin(this);
						break;
					case 4:
						retorno = Passenger_getNewCodigoVueloFromStdin(this);
						break;
					case 5:
						retorno = Passenger_getNewTipoPasajeroFromStdin(this);
						break;
					case 6:
						retorno = Passenger_getNewEstadoVueloFromStdin(this);
						break;
				}
			}
		}while(opcion!=7);
	}
	return retorno;
}




