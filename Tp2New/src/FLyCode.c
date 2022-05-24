/*
 * FLyCode.c
 *
 *  Created on: 15 may. 2022
 *      Author: Usuario
 */


#include "FLyCode.h"


/// @brief Load 5 flyCode sequentially
///
/// @param list
/// @param len_flypass
/// @return int return (-1) if NULL pointer or flyCodes < 0 - (0) if ok
int pass_HardcodeFlyCodePassenger (FlyCode* list, int len_FlyCodes,int* idFlyCode)
{
	int retorno = -1; //Error
	int flagMax=1;

	if(list!=NULL && len_FlyCodes >= 0)
	{
		retorno = 0; //OK
		FlyCode buffer[10]=
			   {{1,"AR140","Activo",ACTIVO,CARGADO},
				{2,"CM158","Activo",ACTIVO, CARGADO},
				{3,"XL1371","Cancelado",CANCELADO,CARGADO},
				{4,"EQ315","Activo",ACTIVO,CARGADO},
				{5,"CX9156","Cancelado",CANCELADO,CARGADO},
				{6,"YH565","Demorado",DEMORADO,CARGADO}};

		for (int i = 0; i < len_FlyCodes; i++) {

			list[i] = buffer[i];

			if (flagMax || list[i].idflycode > *idFlyCode) {

				*idFlyCode = list[i].idflycode;
				flagMax=0;
			}
		}

		(*idFlyCode)++; //Incremento Id para el proximo codigo de vuelo
	}
	return retorno;
}
/// @brief  To indicate that all position in the array are empty,
/// this function put the flag (isempty) in TRUE in all
/// position of the array
///
/// @param list FlyCode
/// @param len int array lenth
/// @return  int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initFlyCodes (FlyCode* list, int len)
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
/** \brief  Return the Index position of the array FlyCode
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if it found a free space
 *
 */
int pass_findEmptySpaceFlyCode (FlyCode* listFlyCode, int len_flyCode)
{
	int index=-1;
	int i;

	if(listFlyCode!=NULL && len_flyCode>0)
	{
		for (i = 0; i < len_flyCode; i++) {
			if (listFlyCode[i].isEmpty == VACIO) {
				index = i;
				break;
			}
		}
	}

	return index;
}
/** \brief find a flyCode by Id en returns the index position in array.
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return Return Passenger index position or (-1) if [Invalid length or NULL
pointer received or Passenger not found]
 *
 */
int pass_findFlyCodeById(FlyCode* list, int len,int id)
{
	int index=-1;
	int i;
	if (list!=NULL && len>0 && id>0)
	{
		for (i = 0; i < len; i++)
		{
			if ( list[i].idflycode == id &&
					list[i].isEmpty== CARGADO )
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
/// @brief  Verify that there is at least one flyCode in the system
///
/// @param listFlyCode
/// @param len_flyCode
/// @return int Return (-1) if its not found a flyCode - (0) if ok
int pass_checkFlyCode (FlyCode* listFlyCode, int len_flyCode)
{
	int i;
	int respuesta=-1; // Pointer NULL or len < 0 or there is not space
	if (listFlyCode!=NULL && len_flyCode>0  ) {
		for (i = 0; i < len_flyCode; i++) {
			if((listFlyCode+i)->isEmpty!= VACIO){
				respuesta=0; //There are space in the array
				break;
			}
		}
	}
	return respuesta;
}
/// @brief print one flight code
///
/// @param listFlyCode
/// @param len_flyCode
/// @return retunr (-1) if len < 0 or pointer NULL - (0)  if ok
int printfFlyCode (FlyCode* this)
{
	int retorno = -1; // len < 0 or pointer NULL

	if (this != NULL && this->isEmpty == CARGADO && this->idflycode>0 ) {

		printf(" |%2d)  || %-11s      || %-12s    |\n",this->idflycode,this->flycode,this->statusFlightChar);

	}

	return retorno;
}
/// @brief prints flight status options
///
void printfestadosDeVueloOpciones ()
{
	printf("\n1)Activo\n"
			"2)Cancelado\n"
			"3)Demorado\n"
			"\n----------------------------------------------\n");
}
/// @brief print the cover of the lis t
///
void printCoverFlyCode ()
{
	printf("\n"
			"  --------------------------------------------\n"
			" | Id  || Codigo de Vuelo  || Estado de Vuelo |\n"
			"  --------------------------------------------\n");
}
/// @brief print all available flight codes
///
/// @param listFlyCode
/// @param len_flyCode
/// @return int return (-1) if NULL pointer or len < 0 or isEmpty is VACIO - (0) if ok
int printfFlyCodes (FlyCode* listFlyCode, int len_flyCode)
{
	int retorno = -1; // len < 0 or pointer NULL

	if (listFlyCode !=NULL && len_flyCode >= 0 && !pass_checkFlyCode(listFlyCode, len_flyCode)) {

		printCoverFlyCode();
		for (int i = 0; i < len_flyCode; i++) {

			printfFlyCode((listFlyCode+i));
		}
		printf("  --------------------------------------------\n");
		retorno = 0; //OK
	}
	return retorno;
}


/*
 * |----- isValid FUNCIONES ----- |
 */

/// @brief Validate that it is a flight code
///
/// @param flyCode
/// @param listFlyCode
/// @param len_flyCode
/// @return int Return (-1) if NULL pointer oro len < 0 or Invalid input FlyCode - (0) if Ok
static int isValidFlyCode (char* flyCode, FlyCode* listFlyCode, int len_flyCode)
{
	int retorno = -1;// NULL pointer oro len < 0 or Invalid input FlyCode

	if ( flyCode != NULL && listFlyCode != NULL && len_flyCode > 0 && isValidAlfaNumerico(flyCode)== 1 ) {

		strupr(flyCode);

		for (int i = 0; i < 2; i++) {

			if ((*(flyCode+i) < 'A' || *(flyCode+i) > 'Z')) {

				return -1;
			}
		}
		retorno = 1;
	}
	return retorno;
}


/*
 *
 * Setters
 *
 * */
/// @brief Sets a flycode thought a pointer to the entity
///
/// @param this
/// @param flyCode
/// @return int return (-1) if [Error invalid pointer] - (0) if ok
int flyCode__setFlyCode (FlyCode* this, char* flyCode)
{
	int retorno = -1; //NUll pointer

	if (this!=NULL && flyCode !=NULL ) {

		strcpy(this->flycode,flyCode);
		retorno = 0; //OK
	}

	return retorno;
}
/// @brief Sets a statusFlight as a integer as a string thought a pointer to the entity
///
/// @param this
/// @param statusFlightstr
/// @param statusFlight
/// @return int return (-1) if [Error invalid pointer] - (0) if ok
int flyCode__setStatusFlight (FlyCode* this, char* statusFlightstr, int statusFlight)
{
	int retorno = -1; //NUll pointer

	if (this !=NULL && statusFlightstr!=NULL  && statusFlight >0 ) {

		retorno = 0; // OK
		strcpy(this->statusFlightChar,statusFlightstr);
		this->statusFlight = statusFlight;
	}

	return retorno;
}
/// @brief  Sets the (id) thought a pointer to the entity
///
/// @param this
/// @param id
/// @return int return (-1) if [Error invalid pointer] - (0) if ok
int flyCode__setId (FlyCode* this, int id)
{
	int retorno = -1; // Cant set the id

	if(this != NULL )
	{
		retorno = 0; //ok
		this->idflycode=id;
	}
	return retorno;
}
/*
 *
 * Getters
 */

/// @brief Get a statusFLight as a integer as a string and return it by reference
///
/// @param statusFlight
/// @param statusFlightstr
/// @return int Return (-1) if Error NULL pointer - (-3) if Invalid input data - (0) if  Ok
int pass_getStatusFlightByInt (int* statusFlight, char* statusFlightstr)
{
	int retorno =-1; //NULL pointer
	int buffer;

	if (statusFlight!=NULL && statusFlightstr !=NULL) {

		printfestadosDeVueloOpciones();

		retorno = -3; //Invalid input data
		if (!utn_getNumero(&buffer, "Estado de vuelo......: ", "\n\tError, estado de vuelo invalido\n\n", 1, 3, 1)) {

			switch (buffer)
			{
			case 1:
				*statusFlight = ACTIVO;
				strcpy(statusFlightstr,"Activo");
				break;
			case 2:
				*statusFlight = CANCELADO;
				strcpy(statusFlightstr,"Cancelado");
				break;
			case 3:
				*statusFlight = DEMORADO;
				strcpy(statusFlightstr,"Demorado");
				break;
			}
			retorno = 0;//OK
		}
	}
	return retorno;
}
/// @brief Get a (flyCode) and return it by reference
///
/// @param buffer
/// @param listFlyCode
/// @param len_flyCode
/// @return int Return (-1) if Error NULL pointer or len < 0 -  (-3) if Invalid input data -(0) if  Ok
int pass_getANewFlyCodeFromStdin (char* flyCode,FlyCode* listFlyCode, int len_flyCode)
{
	int retorno= -1; // NULL pointer or len < 0
	char buffer[11];

	if (flyCode!=NULL ) {

		retorno = -3;//Invalid input data
		if ( !utn_getAlphaNumerico(buffer, "Nuevo codigo de vuelo: ","\n\tError, codigo de vuelo invalido", 1, 11) ) {

			retorno =-2;//Invalid input flyCode
			if (isValidFlyCode(buffer, listFlyCode, len_flyCode) == 1) {

				strcpy(flyCode,buffer);
				retorno = 0; //ok
			}
		}
	}
	return retorno;
}
/// @brief Get a (flyCode int) and return it by reference
///
/// @param this
/// @param listFlyCode
/// @param len_flyCode
/// @return int Return (-1) if Error this is NULL or listFlyCode is NULL or len <  0 - (4) - if No flyCode at list - (0) if Ok
int passenger_getFlyCodeFromStdInByInt (int* flyCode, FlyCode* listFlyCode, int len_flyCode)
{
	int retorno = -1; // this is NULL or listFlyCode is NULL or len <= 0
	int buffer;
	if (flyCode != NULL && listFlyCode != NULL && len_flyCode > 0)
	{
		retorno = 4; //No flyCode at list
		if (!printfFlyCodes ( listFlyCode,  len_flyCode))
		{
			retorno = -3; //Invalid data input
			if (!utn_getNumero(&buffer, "Escoja un id: ", "\n\tError, opcion invalida\n\n", 1, 10, 1)) //Pide un codigo de vuelo
			{
				retorno = 2;// Invalid id entered
				if (pass_findFlyCodeById(listFlyCode, len_flyCode, buffer)>=0) {
					*flyCode = buffer;
					retorno = 0; // Ok
				}
			}
		}
	}
	return retorno;
}


/*
 *
 * Alta
 */
/// @brief add in a existing list of FlyCodes the values received as parameters
///  in the first empty position
///
/// @param list
/// @param flyCode
/// @param statusFlight
/// @param statusFlightstr
/// @param idPassenger
/// @return int Return (-1) if Error [Invalid length or NULL pointer or without
/// [free space] - (3) if No more space - (-4) if setter error - (0) if Ok
int addFlyCode (FlyCode* list,int len_flyCode, char* flyCode, int statusFlight,char* statusFlightstr, int* idPassenger)
{
	int retorno = -1; // NULL pointer or parameters are invalid
	int index;

	if (list!=NULL && flyCode !=NULL && statusFlight >0 && statusFlightstr !=NULL && idPassenger !=NULL) {

		retorno = 3;//No more space
		if ((index=pass_findEmptySpaceFlyCode(list, len_flyCode))>=0) {

			retorno = -4;// Error setter
			if (	!flyCode__setId(&list[index], *idPassenger) &&
					!flyCode__setFlyCode(&list[index], flyCode) &&
					!flyCode__setStatusFlight(&list[index], statusFlightstr, statusFlight))
			{
				(*idPassenger)++; //Increase Id number
				list[index].isEmpty = CARGADO;
			}
			retorno = 0; // ok
		}
	}
	return retorno;
}

/// @brief loads a flyCode to the list passenger
///
/// @param listFlyCode
/// @param len_flyCode
/// @param idFlyCode
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ]  - (1) if cancelled register -
///  (-3) if Invalid input data - (3) if No more space - (-4) if setter error - (0) if Ok
int pass_loadFlyCode (FlyCode* listFlyCode, int len_flyCode,int* idFlyCode )
{
	int retorno = -1;
	FlyCode buffer;

	if ( listFlyCode !=NULL && len_flyCode > 0 && idFlyCode !=NULL) {

		retorno = pass_getANewFlyCodeFromStdin(buffer.flycode, listFlyCode, len_flyCode);
		if (!retorno) {

			retorno = pass_getStatusFlightByInt(&buffer.statusFlight,buffer.statusFlightChar);
			if (!retorno) {

				buffer.isEmpty = CARGADO;
				buffer.idflycode = *idFlyCode;// Prototipo de como quedaria en la lista

				printfFlyCodes(&buffer, len_flyCode);

				retorno=1;//Register a flyCode cancelled
				if (!(retorno=pass_confirmDecision(
						"\n--------------\n"
						"Confirmar\n"
						"---------------\n"
						"Estas seguro que quieres agregrar los datos de un nuevo codigo de vuelo al sistema?\n"
						"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
						"Decisicion: ")))
				{
					retorno = addFlyCode(listFlyCode, len_flyCode, buffer.flycode, buffer.statusFlight, buffer.statusFlightChar, idFlyCode);
					//Add a passenger to the list
					if (!retorno) {
						retorno= 0;//OK
					}
				}
			}
		}
	}
	return retorno;
}

/*
 *
 * Baja
 */
/** \brief Remove a FlyCode by Id (put isEmpty Flag in 0)
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a Passenger] - (0) if Ok
 *
 */
int removeFlyCode (FlyCode* list, int len, int id)
{
	int retorno=-1;
	int index;
	if (list!=NULL && len>0 && id>0)
	{
		if( (index= pass_findFlyCodeById(list, len, id)) >= 0 )
		{
			list[index].isEmpty=VACIO; //Change Flag FALSE
			retorno=0;
		}
	}

	return retorno;
}

/// @brief  Remove a flyCode item into the list
///
/// @param listFlyCode
/// @param len_flyCode
/// @return int Return (-1) if Error [Invalid length or NULL pointer] or (-3) if it can't get a number or (-2) if can't
/// find a Passenger - (1) if the usuary does not want to removee the id - (0) if Ok
int flyCode__BajaCodigoDeVuelo (FlyCode* listFlyCode, int len_flyCode)
{
	int retorno = -1;
	int idIngresado;

	if (listFlyCode!=NULL && len_flyCode > 0)
	{
		printfFlyCodes(listFlyCode, len_flyCode);

		retorno = -3;// Its not a number
		if (!utn_getNumero(&idIngresado, "\nId Baja: ", "\n\tError, intentalo de nuevo\n\n", 1, INT_MAX, 1))
		{
			retorno = -2;// Not found id
			if (pass_findFlyCodeById(listFlyCode, len_flyCode, idIngresado)>=0) {

				retorno = 1;//Remove cancelled
				if (!(retorno = pass_confirmDecision(
						"\n--------------\n"
						"Confirmar\n"
						"---------------\n"
						"Estas seguro que quieres eliminar este id de la base de datos del sistema?\n"
						"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
						"Decisicion: ")))
				{
					retorno = removeFlyCode(listFlyCode, len_flyCode, idIngresado);
				}
			}
		}
	}
	return retorno;
}

/*
 *
 * Modifcar
 */

/// @brief a new value is get and set to the entity
///
/// @param list
/// @param len_flyCode
/// @param index
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (-3) if invalid imput  -
/// (3) if back menu - (2) if invalid id - (1) if modify canceled - (0) if Ok
int flyCode__ChangeFlyCodeAttribute (FlyCode* list, int len_flyCode,int index)
{
	int modificar = -1;
	int opcion;
	char flyCode[pass_MaxLenNameLasName];
	int statusFlight;
	char  statusFlightstr[11];

	if (list!=NULL && len_flyCode > 0) {

		printf("\n1)Codigo de vuelo\n"
				"2)Estado de vuelo\n");

		modificar = -3; //Invalid input data
		if (!utn_getNumero(&opcion, "\nOpcion: ", "\n\tError, opcion invalida\n\n", 1, 2, 1)) {

			switch (opcion)
			{
				case 1:
					modificar = pass_getANewFlyCodeFromStdin(flyCode, list, len_flyCode);
					if (!modificar) {

						modificar = 1; // Change canceled
						if (!pass_confirmDecision(
								"\n--------------\n"
								"Confirmar\n"
								"---------------\n"
								"Estas seguro que quieres cambiar?\n"
								"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
								"Decisicion: "))
						{
							modificar = flyCode__setFlyCode(&list[index], flyCode);
						}
					}
					break;
				case 2:
					modificar = pass_getStatusFlightByInt(&statusFlight, statusFlightstr);
					if (!modificar) {

						modificar = 1; // Change canceled
						if (!pass_confirmDecision(
								"\n--------------\n"
								"Confirmar\n"
								"---------------\n"
								"Estas seguro que quieres cambiar?\n"
								"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
								"Decisicion: "))
						{
							modificar = flyCode__setStatusFlight(&list[index], statusFlightstr, statusFlight);
						}
					}
					break;
			}
		}
	}

	return modificar;
}
/// @brief  Ask for the necessary data before modifying any field of the entity.
///
/// @param list
/// @param len_flyCode
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (-3) if invalid imput  -
/// (3) if back menu - (1) if modify canceled  - (0) if Ok
int flyCode_ModifcarCodigoVuelo (FlyCode* list, int len_flyCode)
{
	int modificar = -1;
	int idIngresado;
	int index;

	if (list!=NULL && len_flyCode > 0) {

		modificar = printfFlyCodes(list, len_flyCode);
		if (!modificar) {

			modificar = -3;//Invalid input data
			if (!utn_getNumero(&idIngresado, "\nId Modificar: ", "\n\tError opcion invalida\n\n", 0, INT_MAX, 1))
			{
				modificar = 2;//Not found id
				if ((index=pass_findFlyCodeById(list, len_flyCode, idIngresado))>=0) {

					modificar = flyCode__ChangeFlyCodeAttribute(list, len_flyCode, index);
				}
			}
		}
	}
	return modificar;
}
