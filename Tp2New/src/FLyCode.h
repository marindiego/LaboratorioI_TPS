/*
 * FLyCode.h
 *
 *  Created on: 15 may. 2022
 *      Author: Usuario
 */

#ifndef FLYCODE_H_
#define FLYCODE_H_

#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3

#define CARGADO 1
#define VACIO 0

#define t_flyCodesPass 10

#include "utn_funciones.h"
#include "Passenger.h"

typedef struct{
	int idflycode;//PK
	char flycode[10];
	char statusFlightChar[10];
	int statusFlight;
	int isEmpty;

}FlyCode;


/*___________________________________

			HARDCODE
_____________________________________
*/

int pass_HardcodeFlyCodePassenger (FlyCode* list, int FlyCodes,int* idFlyCode); // FlyCode

/*___________________________________

		Sub funciones
_____________________________________
*/
int initFlyCodes (FlyCode* list, int len);

int pass_findEmptySpaceFlyCode (FlyCode* listFlyCode, int len_flyCode);

int pass_findFlyCodeById(FlyCode* list, int len,int id);

int pass_checkFlyCode (FlyCode* listFlyCode, int len_flyCode);

void printfestadosDeVueloOpciones ();

void printCoverFlyCode ();

int printfFlyCodes (FlyCode* listFlyCode, int len_flyCode);


/*
 * Setters
 *
 */

int flyCode__setFlyCode (FlyCode* this, char* flyCode);

int flyCode__setStatusFlight (FlyCode* this, char* statusFlightstr, int statusFlight);

int flyCode__setId (FlyCode* this, int id);

/*
 *
 * Getters
 */

int pass_getStatusFlightByInt (int* statusFlight, char* statusFlightstr);

int pass_getANewFlyCodeFromStdin (char* flyCode,FlyCode* listFlyCode, int len_flyCode);

int passenger_getFlyCodeFromStdInByInt (int* flyCode, FlyCode* listFlyCode, int len_flyCode);

/*
 *
 * Alta
 */

int addFlyCode (FlyCode* list,int len_flyCode, char* flyCode, int statusFlight,char* statusFlightstr, int* idPassenger);

int pass_loadFlyCode (FlyCode* listFlyCode, int len_flyCode,int* idFlyCode );

/*
 *
 * Baja
 */

int removeFlyCode (FlyCode* list, int len, int id);

int flyCode__BajaCodigoDeVuelo (FlyCode* listFlyCode, int len_flyCode);

/*
 * Modificar
 */

int flyCode__ChangeFlyCodeAttribute (FlyCode* list, int len_flyCode,int index);

int flyCode_ModifcarCodigoVuelo (FlyCode* list, int len_flyCode);

#endif /* FLYCODE_H_ */
