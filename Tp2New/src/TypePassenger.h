/*
 * TypePassenger.h
 *
 *  Created on: 16 may. 2022
 *      Author: Usuario
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

#include "utn_funciones.h"
#include "Passenger.h"

#define t_typePass 3

typedef struct{

	int idTypePassenger;  //PK
	char descripcionPassenger [30];
}TypePassenger;


/*___________________________________

			HardCode data
_____________________________________
*/


int pass_HardcodeTypePassenger (TypePassenger* list, int len_TypePassenger); //Type Passenger

/*___________________________________

		Sub funciones
_____________________________________
*/

int pass_checkTyPePassenger (TypePassenger* listTypePassenger, int len_typePassenger);
/*___________________________________

		Imprirmir
_____________________________________
*/
int printfTypePassenger (TypePassenger* listTypePass, int len_typePass);

/*
 *
 * setters
 */

int passenger_setTypePassenger (Passenger* this, int typePassenger);

/*
 *
 * Getters
 */

int passenger_getTypePassengerFromStdIn (int* typePassenger,TypePassenger* listTypePass, int len_typePass);

#endif /* TYPEPASSENGER_H_ */
