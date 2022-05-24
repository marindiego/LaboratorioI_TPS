/*
 * Passenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */

#include "Passenger.h"



/** \brief Load 12 Passengers sequentially
 *
 * \param list Passenger*
 * \param int Passengers
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (0) if ok
 *
 */
int pass_HardcodePassengers (Passenger *list, int len_Passengers,int* idPassengers){

	int retorno=-1; //Error
	int i;
	int flagMax=1;

	if(list!=NULL && len_Passengers >= 0){

		Passenger buffer[100]=
				{{101,"Diego","Marin",6000,4,12,CARGADO},
				{102,"Carla","Suarez", 8000,3,12, CARGADO},
				{103,"German","Scarafilo",6000,4,11,CARGADO},
				{104,"Carlos","Ramirez",4000,1,12,CARGADO},
				{105,"Hector","Alvarez", 5500,5,10, CARGADO},
				{106,"Edgar","Facundo",9800,1,11,CARGADO},
				{107,"Fabian","Geopolis",5000,5,10,CARGADO},
				{108,"David","Yiuta",4000,6,12,CARGADO},
				{109,"Octavio","Lepez", 6000,2,10,CARGADO},
				{110,"Gonzalo","Bastian",5000,4,12,CARGADO},
				{111,"Emiliano","Marin", 4000,2,10,CARGADO},
				{112,"Wilker","Fariñez",3000,3,11,CARGADO}};
				//Agregar Otro Passengers

		for (i = 0; i < len_Passengers; i++) {
			list[i]=buffer[i];

			if (flagMax || list[i].id > *idPassengers) {

				*idPassengers = list[i].id;
				flagMax=0;
			}
		}
		(*idPassengers)++; //Incremento Id para el proximo pasajero
		retorno=0;
	}
	return retorno;
}




/*__________________________________

			SUB FUNCIONES
_____________________________________
*/
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isempty) in TRUE in all
 * position of the array
 * \param list Passenger* Pointer to array of Passengers
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger* list, int len)
{
	int retorno=-1;
	int i;

	if(list!=NULL && len>0){
		retorno=0;
		for (i = 0; i < len; i++)
		{
			(list+i)->isEmpty=VACIO;
		}
	}
	return retorno;
}

/** \brief find an Passenger by Id en returns the index position in array.
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return Return Passenger index position or (-1) if [Invalid length or NULL
pointer received or Passenger not found]
 *
 */
int findPassengerById(Passenger* list, int len,int id)
{
	int index=-1;
	int i;
	if (list!=NULL && len>0 && id>0)
	{
		for (i = 0; i < len; i++)
		{
			if ( list[i].id == id &&
					list[i].isEmpty== CARGADO )
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
/** \brief  Return the Index position
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if it found a free space
 *
 */
int pass_findEmptySpace (Passenger* list, int len)
{
	int index=-1;
	int i;

	if(list!=NULL && len>0){
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty== VACIO) {
				index = i;
				break;
			}
		}
	}

	return index;
}


/** \brief  Verify that there is at least one Passenger in the system
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if its not found a Passenger - (0) if ok
 *
 */
int pass_checkPassenger (Passenger* list, int len)
{
	int i;
	int respuesta=-1; // Pointer NULL or len < 0 or there is not space
	if (list!=NULL && len>0  ) {
		for (i = 0; i < len; i++) {
			if((list+i)->isEmpty!= VACIO){
				respuesta=0; //There are space in the array
				break;
			}
		}
	}
	return respuesta;
}

/** \brief Asks a number
 *
 * \param mensaje char*
 * \return int Return (-1) if NULL masage - (0) if cancelled - (1) if ok
 */
int pass_confirmDecision (char* mensaje)
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

/*
 *
 *
 *  	IMPRIMIR MENSAJES Y RETORNOS
 *
 * */



/*_____________________________________________

		  	  Sort
________________________________________________
*/


/** \brief Sort passengers descending by their id
 *
 * \param list Passenger*
 * \param int opcion
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (o) if OK
 *
 */
int sortPassengersById (Passenger* lista,int len)
{
	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	Passenger buffer;

	if( lista!=NULL &&  len>0 ){
		do{
			flagSwap=0;
			for(i=0; i<len-1 ; i++){
				contador++;
				if( lista[i].id > lista[i+1].id)
				{
					flagSwap=1;
					buffer=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a Passenger] - (0) if Ok
 *
 */
int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int index;
	if (list!=NULL && len>0 && id>0)
	{
		if( (index= findPassengerById(list, len, id)) >= 0 )
		{
			list[index].isEmpty=VACIO; //Change Flag FALSE
			retorno=0;
		}
	}

	return retorno;
}

/*
 *	 Alta
 * */


//_________Getters__________
/// @brief load 1 passager into the list
///
/// @param char* name
/// @return int Return (-1) if Error Failed to get a passenger - (0) if Ok
int passenger_getNameFromStdIn (char* name)
{
	int retorno = -1; // Error getting a name
	char buffer[15];

	if (name != NULL  )
	{
		retorno = -3; //Invalid Opcion
		if (!utn_getCharNombre(buffer, "Nombre: ", "\n\tError, nombre invalido\n\n", 1, pass_MaxLenNameLasName)) {

			if (PrimerasLetrasMayuscula(buffer))
			{
				strcpy(name,buffer);
				retorno = 0; //ok
			}
		}

	}
	return retorno;
}
/// @brief Get a lastname through a pointer to the entity
///
/// @param this
/// @return int Return (-1) if Error getting a lastname - NULL pointer - (0) if Ok
int passenger_getLastNameFromStdIn (char* lastName)
{
	int retorno = -1; // Error getting a lastname - NULL pointer
	char buffer[15];

	if (lastName != NULL  )
	{
		retorno = -3; //Invalid Opcion
		if (!utn_getCharNombre(buffer, "Apellido: ", "\n\tError, apellido invalido\n\n", 1, pass_MaxLenNameLasName)) {

			if (PrimerasLetrasMayuscula(buffer))
			{
				strcpy(lastName,buffer);
				retorno = 0; //ok
			}
		}
	}
	return retorno;
}
/// @brief  Get a price through a pointer to the entity
///
/// @param this
/// @return int Return (-1) if Error getting a price- (0) if Ok
int passenger_getPriceFromStdIn (float* price)
{
	int retorno = -1; // Error getting a price
	float buffer;

	if (price != NULL )
	{
		retorno = -3; //Invalid Opcion
		if (!utn_getFloat(&buffer, "Precio: ", "\n\tError, precio invalido\n\n", 1, INT_MAX, 1)) {

			*price = buffer;
			retorno = 0; //ok
		}
	}
	return retorno;
}
/*
 * |----- isValid FUNCIONES ----- |
 */

static int isValidId (int id)
{
	int retorno = -1; //Not id

	if(id >= 100)
	{
		retorno = 1; //ok
	}
	return retorno;
}

static int isValidPrice (float price)
{
	int retorno = -1; // Not price

	if (price > 100  )
	{
		retorno = 1;//Ok
	}

	return retorno;
}

/*
 *
 * setters
 *
 */
/// @brief Sets the (name) to a list item
///
/// @param this
/// @param name char* const
/// @return int Return (-1) if Cant set the name - (0) if Ok
int passenger_setName (Passenger* this, char* name){

	int retorno = -1; //Cant set the name

	if(this != NULL && name != NULL && isValidTextoBasico(name, pass_MaxLenNameLasName) )
	{
		retorno = 0; //ok
		strcpy(this->name, name);
	}
	return retorno;

}
/// @brief Sets the (lastname) to a list item
///
/// @param this
/// @param lastName
/// @return int Return (-1) if Cant set the lastname - (0) if Ok
int passenger_setLastName (Passenger* this, char* lastName)
{
	int retorno = -1; //Cant set the lastname

	if(this != NULL && lastName != NULL && isValidTextoBasico(lastName, pass_MaxLenNameLasName))
	{
		retorno = 0; // ok
		strcpy(this->lastName, lastName);
	}
	return retorno;
}

/// @brief  Sets the (price) to a list item
///
/// @param this
/// @param price
/// @return int Return (-1) if Cant set the price - (0) if Ok
int passenger_setPrice (Passenger* this, float price)
{
	int retorno = -1; //Cant set the price

	if(this != NULL && isValidPrice(price)) //validacion
	{
		retorno = 0; //ok
		this->price = price;
	}
	return retorno;
}
/// @brief Sets the (flyCode int ) to a list item
///
/// @param this
/// @param flycode
/// @param listFlyCode
/// @param len_flyCode
/// @return  int Return (-1) if Cant set the flyCode - (0) if Ok
int passenger_setFlyCodeInt (Passenger* this, int flycode)
{
	int retorno = -1; //Cant set the flycode

	if(this != NULL && flycode > 0 ) // Validacion
	{
		this->idflycode = flycode;
		retorno = 0; //OK
	}
	return retorno;

}
/// @brief Sets the (id) to a list item
///
/// @param this
/// @param int id
/// @return int Return (-1) if Cant set the id - (0) if Ok
int passenger_setId (Passenger* this, int id)
{
	int retorno = -1; // Cant set the id

	if(this != NULL && isValidId(id))
	{
		retorno = 0; //ok
		this->id=id;
	}
	return retorno;

}
/*
 *
 * Modificar
 */
/// @brief Changes the value of an entity pointer at a specific index
///
/// @param list
/// @param index
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (0) if Ok
int pass_modificarNuevoNombre (Passenger* list, int index)
{
	int change = -1;
	char name[pass_MaxLenNameLasName];

	if (list!=NULL && index >= 0) {

		change = passenger_getNameFromStdIn(name);
		if (!change) {

			change = 1;// Change cancelled
			if (!pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				change = passenger_setName(&list[index], name);
			}
		}
	}
	return change;
}
/// @brief Changes the value of an entity pointer at a specific index
///
/// @param list
/// @param index
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (0) if Ok
int pass_modificarNuevoApellido (Passenger* list, int index)
{
	int change = -1;
	char lastName[pass_MaxLenNameLasName];

	if (list!=NULL && index >= 0)
	{
		change = passenger_getLastNameFromStdIn(lastName);
		if (!change) {

			change = 1;// Change cancelled
			if (!pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar |  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				change = passenger_setLastName(&list[index], lastName);
			}
		}
	}
	return change;
}
/// @brief Changes the value of an entity pointer at a specific index
///
/// @param list
/// @param index
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (0) if Ok
int pass_modificarNuevoPrecio (Passenger* list, int index)
{
	int change = -1;
	float price;

	if (list!=NULL && index >= 0)
	{
		change = passenger_getPriceFromStdIn(&price);
		if (!change)
		{
			change = 1;// Change cancelled
			if (!pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
									"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar |  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				change = passenger_setPrice(&list[index], price);
			}
		}
	}
	return change;
}

