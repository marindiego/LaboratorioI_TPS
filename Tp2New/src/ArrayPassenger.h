/*
 * ArrayPassenger.h
 *
 *  Created on: 15 may. 2022
 *      Author: Usuario
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "utn_funciones.h"
#include "Passenger.h"
#include "FLyCode.h"
#include "TypePassenger.h"



/*_____________________________________________

			Imprimir Mensajes
________________________________________________
*/
void printfPassengerOptionsMenu ();

void printfMenuInformar ();

void printfInformarPrecio ();

void printOpcionesAlta ();

void printCoverListPassenger ();

int printPassenger(Passenger* this, FlyCode* thisFlyCode, TypePassenger* thisTypePassenger);

int printPassengers(Passenger* list,int length, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePassenger,int len_typePassenger);

int printPassengersByStatusFlight (int statusFlight, Passenger* arrayPassengers,int len_passenger, FlyCode* arrayFlyCodes, int len_flyCode, TypePassenger* arrayTypePassengers,int len_typePassenger);

void printfListados ();

void printfAscendeteDescendente ();

void printfPassengerOptionsMenuModificar ();

/*
 * Sub Funciones
 *
 * */

int AltaForzada (Passenger* arrayPassengersHardcode, int len,int* idPassengers,FlyCode* arrayFlyCodes, int len_flyCode,int* idFlyCode);



/*
 * Sort
 *
 */

int sortPassengersByLastNameTypePassenger(Passenger* lista, int len, int order, TypePassenger* listTypePassengers, int len_typePass);

int sortPassengersByCode (Passenger* lista, int len,int order,FlyCode* arrayFlyCodes, int len_flyCode);

/*
 * Informar
 *
 */

int InformarListarPasajeros (Passenger* list, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

int pass_pricePassengers (Passenger* list, int len,float* price);

int pass_promedyPassengers (Passenger* list, int len, float price, float* promedio);

int printfPasajerosPrecioPromedio (Passenger* list, int len, float precio, float promedio);

int printfPasajerosPrecioTotalPromedio (float price, float promedio);

int InformarPrecioPasajeros (Passenger* list, int len);

int pass_InformarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

int InformarPassenger (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

/*
 *  Baja
 *
 */

int pass_BajaPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

int BajaPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

/*
 *
 * Getters
 */


int pass_getPassengerFromStdIn (Passenger* buffer, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

/*
 * Alta
 *
 */

int addPassenger(Passenger* list, int len, int* idPassenger, char name[], char lastName[],float price,
					int  typePassenger, int flycode);

int pass_loadPassenger (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass, int* idPassenger);

int pass_AltaPassengers(Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass,int* idPassenger, int* idFlyCode);

int AltaPassengers (Passenger* arrayPassengers, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass,int* idPassenger, int* idFlyCode);

/*
 *
 * Modificar
 *
 */


int pass_modificarNuevoCodigoDeVuelo (Passenger* list, int index,FlyCode* listFlyCode, int len_flyCode);

int pass_modificarNuevoTipoPasajero (Passenger* list, int index, TypePassenger* listTypePass, int len_typePass);

int	pass_changePassengerAttribute(int opcion,Passenger* list, int index,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

int pass_ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

int ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

#endif /* ARRAYPASSENGER_H_ */
