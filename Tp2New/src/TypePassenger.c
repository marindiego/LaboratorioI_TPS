/*
 * TypePassenger.c
 *
 *  Created on: 16 may. 2022
 *      Author: Usuario
 */

#include "TypePassenger.h"

/// @brief Load 3 TypePassengers sequentially
///
/// @param list
/// @param len_tpass
/// @return int return (-1) if NULL pointer or TyPePassenger < 0 - (0) if
int pass_HardcodeTypePassenger (TypePassenger* list, int len_TypePassenger)
{
	int retorno = -1; //Error

	if(list!=NULL && len_TypePassenger >= 0){

		retorno = 0; //ok
		TypePassenger buffer[100]=
						   {{10,"Economica"},
						    {11,"Negocios"},
							{12,"Ejecutiva"}};

		for (int i = 0; i < len_TypePassenger; i++) {
			list[i]=buffer[i];
		}
	}
	return retorno;
}

/// @brief  Verify that there is at least one typePassenger in the system
///
/// @param listTypePassenger
/// @param len_typePassenger
/// @return int Return (-1) if its not found a TypePassenger - (0) if ok
int pass_checkTyPePassenger (TypePassenger* listTypePassenger, int len_typePassenger)
{
	int i;
	int respuesta=-1; // Pointer NULL or len < 0 or there is not space
	if (listTypePassenger!=NULL && len_typePassenger>0  ) {
		for (i = 0; i < len_typePassenger; i++) {
			if((listTypePassenger+i)->idTypePassenger >= 1){
				respuesta=0; //There are space in the array
				break;
			}
		}
	}
	return respuesta;
}
/// @brief print all available  type passenger
///
/// @param listTypePass
/// @param len_typePass
/// @return
int printfTypePassenger (TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1; // NULL pointer or len < 0

	if (listTypePass !=NULL && len_typePass > 0 && !pass_checkTyPePassenger(listTypePass, len_typePass))
	{
		printf("\n"
				"  --------------------------\n"
				" | Id  || Tipo de Pasajero  |\n"
				"  --------------------------\n");

		for (int i = 0; i < len_typePass; i++) {

			printf(" |%2d)  || %-10s        |\n",(listTypePass+i)->idTypePassenger,(listTypePass+i)->descripcionPassenger);
		}
		printf("  --------------------------\n");
		retorno = 0; //OK
	}
	return retorno;
}


/*
 * isValid
 *
 * */
static int isValidTypePassenger (int typePassenger)
{
	int retorno = -1; // Not valid number

	if ( typePassenger >=10 && typePassenger <= 12)
	{
		retorno = 1;//Ok
	}

	return retorno;
}

/*
 *
 * Setters
 *
 */
/// @brief  Sets the (TypePassenger) to a list item
///
/// @param this
/// @param typePassenger
/// @return int Return (-1) if Cant set the typePasenger - (0) if Ok
int passenger_setTypePassenger (Passenger* this, int typePassenger)
{
	int retorno = -1; //Cant set the typePassenger

	if (this != NULL && isValidTypePassenger(typePassenger) == 1)
	{
		this->typePassenger = typePassenger;
		retorno = 0; //Ok
	}
	return retorno;
}

/*
 *
 * Getters
 */

/// @brief Get a TypePassenger through a pointer to the entity
///
/// @param this
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error (this) is NULL or (listTypePass) is NULL or len < 0 - (0) if Ok
int passenger_getTypePassengerFromStdIn (int* typePassenger,TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1; // Error - (this) is NULL or (listTypePass) is NULL or len < 0
	int buffer;
	if (typePassenger != NULL  &&  listTypePass != NULL && len_typePass > 0 )
	{
		printfTypePassenger(listTypePass, len_typePass);

		retorno = -3;//Invalid Opcion
		if (!utn_getNumero(&buffer, "Escoja un id: ", "\n\tError, tipo de pasajero invalido\n\n", 1, 1000, 1)) //Pido y Valido el Tipo de pasajero con el maximo numero que puede ingresar
		{
			retorno = 2;// Invalid id entered
			if (isValidTypePassenger(buffer) == 1) {

				*typePassenger= buffer;
				retorno = 0; // OK
			}
		}
	}
	return retorno;
}
