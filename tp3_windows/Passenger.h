/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "utn_funciones.h"
#include "ValidacionesGenericos.h"
#include "LinkedList.h"

#define NOMBRE_len 10
#define CODIGOVUELO_len 8
#define ESTADOVUELO_len 12
#define TYPEPASS_len 13

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[50];
	char estadoVuelo[50];

}Passenger;

Passenger* Passenger_new();
void Passenger_delete(Passenger* this);

Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr,char*codigoVueloStr, char* tipoPasajeroStr,char* estadoVueloStr);
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio, char* codigoVuelo,char* tipoPasajero, char* estadoVuelo);

void Passenger_printOne (Passenger* this);
void Passenger_printfPassengerOptionsMenu ();
void Passenger_printReturnRemove (int retorno);
void Passenger_printReturnAdd(int retorno);
void Passenger_printReturnEdit(int retorno);
void Passenger_printOptionsTypePassenger ();
void Passenger_printOptionsEstadoVuelo();

int Passenger_setId(Passenger* this,int id);
int Passenger_setIdTxt(Passenger* this,char* id);
int Passenger_getId(Passenger* this,int* id);
int Passenger_getIdTxt(Passenger* this,char* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);
int Passenger_getNewNombreFromStdin (Passenger* this);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);
int Passenger_getNewApellidoFromStdin (Passenger* this);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getNewCodigoVueloFromStdin (Passenger* this);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajeroFromStdin(char* tipoPasajero);
int Passenger_getNewTipoPasajeroFromStdin (Passenger* this);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_getPrecioTxt(Passenger* this,char* precio);
int Passenger_getNewPrecioFromStdin (Passenger* this);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVueloFromStdin(char* estadoVuelo);
int Passenger_getNewEstadoVueloFromStdin(Passenger* this);



void Passenger_printOpcionsSort ();
void Passenger_printOpcionMayorMenor ();
void Passenger_printOpcionMayorMenor ();
void Passenger_printOptionsModificar ();

int Passenger_compareByName (void* pass1,void* pass2);
int Passenger_compareByLastName (void* pass1,void* pass2);
int Passenger_compareByPrice (void* pass1,void* pass2);
int Passenger_compareByFlyCode (void* pass1,void* pass2);
int Passenger_compareByTipoPasajero (void* pass1,void* pass2);
int Passenger_compareByEstadoVuelo (void* pass1,void* pass2);

int Passenger_findPassengerById (LinkedList* ListPassengers, int id);
int Passenger_confirmDecision (char* mensaje);

Passenger* Passenger_addOneFromStdin (int* id);
int Passenger_editOneFromStdin (Passenger* this);


#endif /* PASSENGER_H_ */
