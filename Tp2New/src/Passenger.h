/*
 * Passenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "utn_funciones.h"

#define t_pass 5

#define CARGADO 1
#define VACIO 0

#define pass_MaxLenNameLasName  15

typedef struct{

	int id;  //PK
	char name[51];
	char lastName[51];
	float price;
	int idflycode; //FK
	int typePassenger; //FK
	int isEmpty;
}Passenger;

/*___________________________________

			HARDCODE
_____________________________________
*/

int pass_HardcodePassengers (Passenger* list, int Passengers,int* idPassengers); // Passenger

/*__________________________________

			SUB FUNCIONES
_____________________________________
*/


int initPassengers(Passenger* list, int len); // Passenger

int findPassengerById(Passenger* list, int len,int id); // Passenger

int pass_findEmptySpace (Passenger* list, int len); // Passenger

int pass_checkPassenger (Passenger* list, int len); // Passenger

int pass_confirmDecision (char* mensaje);


/*______________________________________________

		  	  	  Sort
________________________________________________
*/


int sortPassengersById (Passenger* lista,int len); // Passenger ..

/*
 * Baja
 *
 * */


int removePassenger(Passenger* list, int len, int id);

/*
 * Alta
 *
 */


/*
//_________Getters__________
 * */


int passenger_getNameFromStdIn (char* name);

int passenger_getLastNameFromStdIn (char* lastName);

int passenger_getPriceFromStdIn (float* price);


/*
 *
 * setters
 *
 */

int passenger_setName (Passenger* this, char* name);

int passenger_setLastName (Passenger* this, char* lastName);

int passenger_setPrice (Passenger* this, float price);

int passenger_setFlyCodeInt (Passenger* this, int flycode);

int passenger_setId (Passenger* this, int id);

/*
 *
 * Modificar
 */

int pass_modificarNuevoNombre (Passenger* list, int index);

int pass_modificarNuevoApellido (Passenger* list, int index);

int pass_modificarNuevoPrecio (Passenger* list, int index);



#endif /* PASSENGER_H_*/
