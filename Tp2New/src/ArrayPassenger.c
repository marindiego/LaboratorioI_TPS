/*
 * ArrayPassenger.c
 *
 *  Created on: 15 may. 2022
 *      Author: Usuario
 */


#include "ArrayPassenger.h"
/// @brief Main options menu
///
void printfPassengerOptionsMenu ()
{
	printf("\t\tPrograma de Passengers en C:\n\n"
			"\t\t1) ALTA Pasajero\n\n"
			"\t\t2) MODIFICACIÓN Pasajero\n\n"
			"\t\t3) BAJA Pasajero\n\n"
			"\t\t4) INFORMAR Pasajero\n\n"
			"\t\t5) Alta Forzada\n\n"
			"\t\t6) Salir\n"
			""
			"\n\n");
}

/// @brief Main menu informar
///
void printfMenuInformar ()
{
	printf("\n0) Volver Menu anterior\n"
			"1) Informar Listados\n"
			"2) Informar Precio de los pasajes.\n"
			"\n--------------------------------------------------\n");
}
/// @brief Informar precio
///
void printfInformarPrecio ()
{
	printf("\n1) Total y promedio de los precios de los pasajes\n"
			"2) Cuantos pasajeros superan el precio promedio\n"
			"\n\n-------------------------------------------------\n\n");
}
/// @brief  printOpciones Alta
///
void printOpcionesAlta ()
{
	printf("\n0) Volver al menu\n"
			"1) Dar de Alta un pasajero\n"
			"2) Dar de Alta un Codigo de vuelo\n"
			"\n\n-------------------------------------------------\n\n");
}
/// @brief Cover of Passenger
///
void printCoverListPassenger ()
{
	printf("\n" // Portada de la lista de pasajeros
				" -------------------------------------------------------------------------------------------------------------------  \n"
				"| Id   ||    Nombre         ||    Apellido      ||      Precio     ||     Código de vuelo    ||   IdTipoPasajero    | \n"
				" -------------------------------------------------------------------------------------------------------------------  \n");
}

/// @brief   print the content of 1 Passenger
///
/// @param this
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePassenger
/// @param len_typePassenger
/// @return int return (-1) if NULL pointer or len < 0 or isEmpty is VACIO - (0) if ok
int printPassenger(Passenger* this, FlyCode* thisFlyCode, TypePassenger* thisTypePassenger)
{
	int retorno = -1; //NULL pointer or len < 0 or isEmpty is VACIO or there is no one loaded (FlyCode and TypePassenger list)

	if (	this!=NULL && this->isEmpty == CARGADO &&
			thisFlyCode!=NULL && thisFlyCode->isEmpty == CARGADO &&
			thisTypePassenger!=NULL )
	{
		printf("| %-3d  ||    %-10s     ||    %-9s     ||    %9.2f    ||        %-9s       ||         %-8d    |\n" ,this->id ,this->name, this->lastName,this->price,thisFlyCode->flycode,thisTypePassenger->idTypePassenger);
		printf(" -------------------------------------------------------------------------------------------------------------------\n");
		retorno = 0; //OK
	}

	return retorno;
}
/// @brief print the content of Passengers array
///
/// @param list
/// @param length
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int return (-1) if len < 0 or pointer NULL - (-1) if  No passanger load - No flyCode load - No TypePassenger load (0) if OK
int printPassengers(Passenger* list,int length, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePassenger,int len_typePassenger)
{
	int retorno=-1; // len < 0 or pointer NULL

	if (	list!=NULL && length>0 &&
			listFlyCode !=NULL && len_flyCode > 0 &&
			listTypePassenger!=NULL && len_typePassenger > 0 )
	{

		retorno = -2; //  No passanger load - No flyCode load - No TypePassenger load
		if (!pass_checkPassenger(list, length))
		{
			printCoverListPassenger ();

			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < len_flyCode; j++) {

					if ((list+i)->idflycode == (listFlyCode+j)->idflycode) { //Pasajero encuentra su codigo en la lista

						for (int k = 0; k < len_typePassenger; k++)
						{
							if ((list+i)->typePassenger == listTypePassenger[k].idTypePassenger) { // Pasajero encuentra su idTipo en la lista

								printPassenger((list+i), (listFlyCode+j),(listTypePassenger+k));
							}
						}
					}
				}
			}
			retorno=0; // todo ok
		}
	}
	return retorno;
}
/// @brief  print passengers depending on their flight status
///
/// @param statusFlight int [ACTIVO] (0) - [CANCELADO] (-1) - [DEMORADO] (1)
/// @param arrayPassengers
/// @param len_passenger
/// @param arrayFlyCodes
/// @param len_flyCode
/// @param arrayTypePassengers
/// @param len_typePassenger
/// @return int return (-1) if len < 0 or pointer NULL - (-1) if  No passanger load - No flyCode load - No TypePassenger load (0) if OK
int printPassengersByStatusFlight (int statusFlight, Passenger* arrayPassengers,int len_passenger, FlyCode* arrayFlyCodes, int len_flyCode, TypePassenger* arrayTypePassengers,int len_typePassenger)

{

	int retorno=-1; // len < 0 or pointer NULL
	int flag = 0;

	if (	arrayPassengers!=NULL && len_passenger>0 &&
			arrayFlyCodes !=NULL && len_flyCode > 0 &&
			arrayTypePassengers!=NULL && len_typePassenger > 0 )
	{
		retorno = -4; //  No passanger load - No flyCode load - No TypePassenger load
		if (	!pass_checkPassenger(arrayPassengers, len_passenger) &&
				!pass_checkFlyCode(arrayFlyCodes, len_flyCode) &&
				!pass_checkTyPePassenger(arrayTypePassengers, len_typePassenger))
		{
			for (int p = 0; p < len_passenger; p++) {
				for (int u = 0; u < len_flyCode; u++) {

					if ((arrayPassengers+p)->idflycode == (arrayFlyCodes+u)->idflycode && arrayFlyCodes[u].statusFlight == statusFlight) {
						flag  = 1; // There is at least one passenger with flight status entered.
					}
				}
			}

			retorno = -3; // no passenger to print with entered flight status
			if (flag) {

				printfFlyCodes(arrayFlyCodes, len_flyCode);
				printfTypePassenger(arrayTypePassengers, len_typePassenger);

				printCoverListPassenger();
				for (int i = 0; i < len_passenger; i++)
				{
					for (int j = 0; j < len_typePassenger; j++) {

						if (arrayPassengers[i].typePassenger == arrayTypePassengers[j].idTypePassenger ) {

							for (int k = 0; k < len_flyCode; k++) {

								if ((arrayPassengers+i)->idflycode == (arrayFlyCodes+k)->idflycode && arrayFlyCodes[k].statusFlight == statusFlight) {

									printPassenger(&arrayPassengers[i], &arrayFlyCodes[k], &arrayTypePassengers[j]);
								}
							}
						}
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}
/// @brief shows all available options for printing
///
void printfListados ()
{
	printf("\n0) Volver al menu principal\n"
			"1) Listado de todos los pasajeros, codigos de vuelo y tipos de pasajeros disponible \n"
			"2) Listados de los Pasajeros ordenados alfabéticamente por (Apellido) y (Tipo de pasajero).\n"
			"3) Listado de los Pasajeros por  (Código de vuelo)  y estados de vuelos 'Activo', 'Cancelado' y 'Demorado' \n"
			"\n----------------------------------------------\n");
}
void printfAscendeteDescendente ()
{
	printf(	"\n1) Ordenar de la A a la Z\n"
			"2) Ordenar de la Z a la A\n"
			"\n----------------------------------------------\n");
}
void printfPassengerOptionsMenuModificar ()
{
	printf("\n0) Volver Menu\n"
			"1) Nombre\n"
			"2) Apellido\n"
			"3) Precio\n"
			"4) Codigo de Vuelo\n"
			"5) Tipo De Vuelo\n");
}
/*
 * Sub Funciones
 *
 * */

/// @brief forced passenger check-in
///
/// @param arrayPassengersHardcode
/// @param len
/// @param arrayFlyCodes
/// @param len_flyCode
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int AltaForzada (Passenger* arrayPassengersHardcode, int len,int* idPassengers,FlyCode* arrayFlyCodes, int len_flyCode,int* idFlyCode)
{
	int retorno =-1;//Error

	if (arrayPassengersHardcode!=NULL && len>0 && arrayFlyCodes !=NULL && len_flyCode > 0)
	{
		if (!(retorno = pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Si diste de alta un pasajero o codigo de vuelo, vas a sobreescribir los datos ingresados anteriormente\n"
					"Estas seguro que quieres hacer una 'Alta forzada'?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: ")))
		{
			retorno=0;
			pass_HardcodeFlyCodePassenger(arrayFlyCodes, t_flyCodesPass,idFlyCode);
			pass_HardcodePassengers(arrayPassengersHardcode, t_pass,idPassengers);
			printf("\nAlta Forzada Completada!!!..........\n\n");
		}
		else
			printf("\nAlta Forzada Cancelada!!!..........\n\n");
	}
	return retorno;
}



/*
 * Sort
 *
 */

/** \brief Sort the elements in the array of Passengers, the argument order
indicate UP or DOWN order
 *
 * \param list Passenger*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - ( return > 0) if Ok and the swaps it did
 *
 */
int sortPassengersByLastNameTypePassenger(Passenger* lista, int len, int order, TypePassenger* listTypePassengers, int len_typePass)
{
	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	int auxCmp;
	Passenger aux;

	if( lista!=NULL &&  len > 0 && order >0 && !pass_checkPassenger(lista, len) ){

		do{

			flagSwap=0;
			for(i=0; i<len-1 ; i++){

				for (int j = 0; j < len_typePass; j++)
				{
					contador++;
					auxCmp = strncmp((lista+i)->lastName,(lista+i+1)->lastName,pass_MaxLenNameLasName);

					switch (order) {
						case 1:
							if ((lista+i)->isEmpty == VACIO || (lista+i+1)->isEmpty == VACIO )
							{
								continue;
							}

							if (	auxCmp > 0 ||
									(auxCmp == 0  &&
											lista[i].typePassenger == listTypePassengers[j].idTypePassenger &&
											stricmp(listTypePassengers[j].descripcionPassenger,listTypePassengers[j+1].descripcionPassenger ) > 0))  {

								flagSwap=1;
								aux=lista[i];
								lista[i]=lista[i+1];
								lista[i+1]=aux;
								contador++;
							}
							break;
						case 2:
							if ((lista+i)->isEmpty == VACIO || (lista+i+1)->isEmpty == VACIO)
							{
								continue;
							}

							if (	auxCmp < 0 ||
									(auxCmp == 0  &&
											lista[i].typePassenger == listTypePassengers[j].idTypePassenger &&
											stricmp(listTypePassengers[j].descripcionPassenger,listTypePassengers[j+1].descripcionPassenger ) < 0))  {

								flagSwap=1;
								aux=lista[i];
								lista[i]=lista[i+1];
								lista[i+1]=aux;
								contador++;
							}
							break;

					}
				}
			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode (Passenger* lista, int len,int order,FlyCode* listaFlyCodes, int len_flyCode)
{
	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	char codigos[1][10];
	int auxCmp;
	Passenger aux;

	if( lista!=NULL &&  len > 0 && order >0 && !pass_checkPassenger(lista, len) && !pass_checkFlyCode(listaFlyCodes, len_flyCode)){

		do{

			flagSwap=0;
			for(i=0; i<len-1 ; i++){

				for (int j = 0; j < len_flyCode ; j++)
				{
					contador++;

					for (int k = 0; k < len_flyCode; k++)
					{
						if (lista[i].idflycode == listaFlyCodes[k].idflycode) {

							strcpy(codigos[0],listaFlyCodes[k].flycode);
							break;
						}

					}
					for (int l = 0; l < len_flyCode; l++)
					{
						if (lista[i+1].idflycode == listaFlyCodes[l].idflycode) {

							strcpy(codigos[1],listaFlyCodes[l].flycode);
							break;
						}
					}

					auxCmp = stricmp(codigos[0], codigos[1] );

					switch (order)
					{
						case 1:
							if ((lista+i)->isEmpty == VACIO || (lista+i+1)->isEmpty == VACIO)
							{
								continue;
							}

							if ((listaFlyCodes+j)->isEmpty == VACIO || (lista+j+1)->isEmpty== VACIO )
							{
								continue;
							}


							if (auxCmp > 0 )
							{
								flagSwap=1;
								aux=lista[i];
								lista[i]=lista[i+1];
								lista[i+1]=aux;
								contador++;
							}
							break;

						case 2:

							if ((lista+i)->isEmpty == VACIO|| (lista+i+1)->isEmpty == VACIO)
							{
								continue;
							}

							if ((listaFlyCodes+j)->isEmpty == VACIO|| (lista+j+1)->isEmpty== VACIO )
							{
								continue;
							}


							if (auxCmp < 0 )
							{
								flagSwap=1;
								aux=lista[i];
								lista[i]=lista[i+1];
								lista[i+1]=aux;
								contador++;
							}
							break;
					}
				}
			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}

/*__________________________________

	     INFORMAR
_____________________________________
*/
/// @brief Informar Listado Pasajeros
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (2) if Invalid opcion - (0) if Ok
int InformarListarPasajeros (Passenger* list, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int opcion;
	int order;
	int statusFlight;
	int retorno = -1; //NULL pointer or len < 0

	if (listFlyCode != NULL && len_flyCode  > 0 && listTypePass!= NULL &&  len_typePass  > 0) {

		printfListados();

		retorno = 2;// Opcion invalida
		if (!utn_getNumero(&opcion, "Opcion: ", "\nError, opcion invalida\n\n", 0,3, 1))
		{
			switch (opcion) //Opciones de listados
			{
				case 0:
					//Back Menu
					retorno = -2;
					break;

				case 1: //Mostrar todas las listas cargadas

					printfFlyCodes(listFlyCode, len_flyCode);
					printfTypePassenger(listTypePass, len_typePass);
					retorno =printPassengers(list, len, listFlyCode, len_flyCode, listTypePass, len_typePass);
					break;

				case 2: //  Apellido y tipo de pasajero
					printfAscendeteDescendente();

					retorno = 2; //Opcion Invalida
					if(!utn_getNumero(&order,"Opcion: ", "\nError, opcion invalida\n\n", 1, 2, 1))
					{
						if (sortPassengersByLastNameTypePassenger(list, len, order, listTypePass, len_typePass)>0) {

							printfFlyCodes(listFlyCode, len_flyCode);
							printfTypePassenger(listTypePass, len_typePass);
							retorno=printPassengers(list, len,listFlyCode, len_flyCode, listTypePass, len_typePass);
						}
					}
					break;
				case 3: //  Codigo de Vuelo
					printfAscendeteDescendente();

					retorno = 2; //Opcion Invalida
					if(!utn_getNumero(&order,"Opcion: ", "\nError, opcion invalida\n\n", 1, 2, 1))
					{
						printfestadosDeVueloOpciones();

						if (!utn_getNumero(&statusFlight, "Opcion: ", "\nError, opcion invalida\n\n", 1, 3, 1)) {

								//Ordenar por codigo de vuelo
							if (sortPassengersByCode(list, len, order, listFlyCode, len_flyCode)) {

								retorno=printPassengersByStatusFlight(statusFlight, list, len, listFlyCode, len_flyCode, listTypePass, len_typePass);
							}
						}
					}
					break;
			}
		}
	}

	return retorno;
}
/** \brief  Accumulates the price of all the tickets and returns it by reference
 *
 * \param list Passenger*
 * \param int len
 * \param inr order
 * \return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
 */
int pass_pricePassengers (Passenger* list, int len, float* price){

	int retorno=-1; // Pointer NULL or len < 0 or there is not space or no salary
	if (list!=NULL && len>=0 && !pass_checkPassenger(list, len) ) {

		retorno = 0; //Return (0) OK
		for (int i = 0; i < len; i++) {

			if ((list+i)->price > 0 && (list+i)->isEmpty == CARGADO) {

				*price+=list[i].price;
			}
		}
	}
	return retorno;
}
/// @brief  calculates the average of all ticket prices
///
/// @param list
/// @param len
/// @param price
/// @param promedy
/// @return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
int pass_promedyPassengers (Passenger* list, int len, float price,  float* promedio){

	int retorno = -1;// Pointer NULL or len < 0 or there is not space or no salary
	int contador=0;

	if (list!=NULL && len>=0  && !pass_checkPassenger(list, len)) {

		retorno = 0; // ok
		for (int i = 0; i < len; i++) {

			if ((list+i)->isEmpty == CARGADO) {

				contador++; // Si estan cargados en la lista los cuento
			}
		}
		*promedio=price/contador; // !=0 OK
	}
	return retorno;
}
/// @brief print the passengers who exceed the average and how many they are
///
/// @param list
/// @param len
/// @param precio
/// @param promedio
/// @return int Return (-1) if Error [Invalid length or NULL pointer or precio promedio < 0] - (0) if Ok
int printfPasajerosPrecioPromedio (Passenger* list, int len, float precio, float promedio)
{
	int retorno =-1; //Pointer NULL or len, precio, promedio < 0
	int contador = 0;
	if (list!= NULL && len > 0 && precio > 0 && promedio > 0) {

		retorno = 0; // OK
		for (int i = 0; i < len; i++) {
			if (list[i].price>= promedio && list[i].isEmpty == CARGADO  ) {


				contador++;
			}
		}

		printf("\nPrecio de un pasaje promedio: %.2f\n"
				"\nHay %d pasajeros que superan el precio promedio por pasaje\n", promedio, contador);
	}
	return retorno;
}
/// @brief prints the total accumulated price of the passengers and the average of that price
///
/// @param price
/// @param promedio
/// @return int Return (-1) if Precio < 0 or Promedio < 0 - (0) if OK
int printfPasajerosPrecioTotalPromedio (float price, float promedio)
{
	int retorno = -1; // Precio < 0 or Promedio < 0

	if(price>0 && promedio>0)
	{
		printf("\nPrecio total de los pasajes : %.2f\n", price);
		printf("\nPrecio Promedio: %.2f\n", promedio);
		retorno=0; //OK
	}
	return retorno;
}
/// @brief Reports everything related to the price of a Passenger
///
/// @param list
/// @param len
/// @return int (-1) if Error Pointer NULL or len and order <0 or there is not space or - (0) if ok
int InformarPrecioPasajeros (Passenger* list, int len)
{
	int retorno=-1;// Pointer NULL or len and order <0 or there is not space
	float price;
	float promedio;
	int opcion;

	if (list!=NULL && len>=0 && !pass_checkPassenger(list, len)) {

		pass_pricePassengers(list, len,&price);
		pass_promedyPassengers(list, len, price,&promedio);

		printfInformarPrecio();

		retorno =2;// Opcion invalida
		if (!utn_getNumero(&opcion, "Opcion: ", "\nError, opcion invalida \n\n", 0, 2, 1)) {

			switch (opcion)
			{
				case 1:
					retorno = printfPasajerosPrecioTotalPromedio ( price , promedio);
					break;
				case 2:
					retorno = printfPasajerosPrecioPromedio(list, len, price, promedio);
					break;
			}
		}
	}
	return retorno;
}

/// @brief Calculates the different options that the user can enter
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (2) if Invalid opcion - (0) if Ok
int pass_InformarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno=-1;// Pointer NULL or len <0
	int opcionInformar;

	if (list!=NULL && len>=0 && listFlyCode != NULL && len_flyCode  > 0 && listTypePass != NULL && len_typePass > 0)
	{
		retorno = 2; // Opcion Invalida
		printfMenuInformar();
		if(!utn_getNumero(&opcionInformar, "Opcion: ", "\nError, opcion invalida \n\n", 0, 2, 1))
		{

			switch (opcionInformar) {
				case 1: //Listados
					retorno = InformarListarPasajeros(list, len, listFlyCode, len_flyCode, listTypePass, len_typePass);
					break;
				case 2: // informar los precios y sus distintos formas de mostrarlos
					retorno = InformarPrecioPasajeros(list, len);
					break;
				case 0:
					retorno=-2; // Back Menu
					break;

			}
		}
	}
	return retorno;
}
/// @brief Prints the possible messages returned by the function ( pass_InformarPassengers ).
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int InformarPassenger (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno =-1;
	int infomarPassengers;

	if (list != NULL && len > 0 && !pass_checkPassenger(list, len)  && !pass_checkFlyCode(listFlyCode, len_flyCode) && listFlyCode != NULL && len_flyCode  > 0 && listTypePass != NULL && len_typePass > 0 )
	{
		retorno = 0;
		sortPassengersById(list, len);

		infomarPassengers = pass_InformarPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

		switch (infomarPassengers)
		{
			case 0:
				printf("\n\t!!-------INFORMAR COMPLETADO----------!!\n\n");
				break;
			case -1:
				printf("\nError, lenth invalido o NULL pointer\n\n");
				break;
			case -2:
				//Back Menu
				break;
			case -3:
				printf("\nEse estado de vuelo no se encuentra disponible en ningun codigo de vuelo de los pasajeros en la lista\n\n");
				break;
			case 2:
				printf("\nDatos Invalidos, Ingresa correctamente las opciones\n\n");
				break;
		}
	}
	else{
		printf("\n\tNo hay pasajeros cargados en el sistema para informar, Ingresa la opcion 'Alta pasajero` primero ;) \n\n");
	}
	return retorno;
}

/*
 *
 * Baja
 *
 */
/** \brief The main function that remove an Passenger with the call of other functions
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (-3) if it can't get a number or (-2) if can't
find a Passenger - (1) if the usuary does not want to removee the id - (0) if Ok
 *
 */
int pass_BajaPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno=-1; //NULL or len <0
	int idIngresado;

	if (list!=NULL && len>0 && listFlyCode !=NULL && len_flyCode >0  && listTypePass !=NULL && len_typePass > 0)
	{
		retorno=-3; // Its not a number
		printPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);
		if (!utn_getNumero(&idIngresado, "\nId Baja: ", "\n\tError, intentalo de nuevo\n\n", 0, INT_MAX, 1))
		{
			retorno=-2; // Not found id
			if(findPassengerById(list, len, idIngresado)>=0)
			{
				retorno = 1;//Remove cancelled
				if(!(retorno = pass_confirmDecision(
						"\n--------------\n"
						"Confirmar\n"
						"---------------\n"
						"Estas seguro que quieres eliminar este id de la base de datos del sistema?\n"
						"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
						"Decisicion: ")))
				{
					retorno = removePassenger(list, len, idIngresado);
				}
			}
		}
	}
	return retorno;
}
/// @brief Prints the possible messages returned by the function ( pass_BajaPassengers ).
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error NULL pointer or any length < 0 - (0) if Ok
int BajaPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1;
	int VereficarRetornoBajaFuncion;
	int opcion;

	if (list != NULL && len >= 0 && listFlyCode != NULL && len_flyCode >= 0 && listTypePass != NULL && listTypePass!=NULL) {

		if(!pass_checkPassenger(list, len) || !pass_checkFlyCode(listFlyCode, len_flyCode))
		{
			sortPassengersById(list, len);

			if (!utn_getNumero(&opcion, "\n1)Dar de baja un pasajero\n2)Dar de Baja un codigo de vuelo\n\nOpcion: ", "\n\tError, opcion invalida\n\n", 1, 2, 1))
			{
				switch (opcion) {
					case 1:
						VereficarRetornoBajaFuncion = pass_BajaPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

						break;
					case 2:
						VereficarRetornoBajaFuncion = flyCode__BajaCodigoDeVuelo(listFlyCode, len_flyCode);
						break;
				}


				switch (VereficarRetornoBajaFuncion) {
				case  0:
					printf("\n\t!!---------BAJA COMPLETADA----------!!\n\n");
					break;
				case -2:
					printf("\n\t\tNo existe ese id o fue dado antes de baja \n\n");
					break;
				case  1:
					printf("\n\t\tBAJA CANCELADA\n\n");
					break;
				case -1:
					printf("\nError, lenth invalido o NULL pointer\n\n");
					break;
				case -3:
					printf("\nIngreso de datos invalidos\n\n");
					break;
				}
			}
			retorno = 0; //Ok
		}
		else{
			printf("\n\tNo hay Pasajeros o Codigos de Vuelo en el sistema para dar de baja\n\n");
		}
	}

	return retorno;
}


/*
 *
 * Getters
 */


/// @brief load 1 passager into the list
///
/// @param list
/// @param len
/// @return int Return (-1) if Pointer NULL or len < 0 - (0) if Ok
int pass_getPassengerFromStdIn (Passenger* buffer, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1; // Pointer NULL or len < 0
	char name[pass_MaxLenNameLasName];
	char lastname[pass_MaxLenNameLasName];
	float price;
	int flyCode;
	int typePassenger;

	if (buffer!=NULL && listFlyCode !=NULL && len_flyCode >= 0 && listTypePass !=NULL && len_typePass >= 0) {

		retorno = passenger_getNameFromStdIn(name);
		if(!retorno)
		{
			retorno = passenger_getLastNameFromStdIn(lastname);
			if (!retorno)
			{
				retorno= passenger_getPriceFromStdIn(&price);
				if (!retorno)
				{
					retorno= passenger_getFlyCodeFromStdInByInt(&flyCode, listFlyCode, len_flyCode);
					if (!retorno)
					{
						retorno= passenger_getTypePassengerFromStdIn(&typePassenger, listTypePass, len_typePass);
						if (!retorno)
						{
							strcpy(buffer->name,name);
							strcpy(buffer->lastName,lastname);
							buffer->price = price;
							buffer->idflycode = flyCode;
							buffer->typePassenger = typePassenger;
							retorno = 0; // Ok
						}
					}
				}
			}
		}
	}
	return retorno;
}

/*
 * Alta
 *
 */

/** \brief add in a existing list of Passengers the values received as parameters
 * in the first empty position
 * \param list Passenger*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param price float
 * \param typePassenger int
 * \param int flyCode
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (3) if No more space - (-4) if setter error - (0) if Ok
 *
*/
int addPassenger(Passenger* list, int len, int* idPassenger, char name[], char lastName[],float price,
		int  typePassenger, int flycode)
{
	int retorno=-1; // NULL pointer or parameters are invalid
	int index;
	if(list!=NULL && len>0 && name!=NULL && lastName!= NULL &&  price >0 &&  typePassenger>=0){

		retorno = 3; // No more space
		if ((index = pass_findEmptySpace(list, len)) >= 0)
		{
			retorno = -4; //Setter Error
			if (	!passenger_setId(&list[index], *idPassenger) &&
					!passenger_setName(&list[index], name) &&
					!passenger_setLastName(&list[index], lastName) &&
					!passenger_setPrice(&list[index], price) &&
					!passenger_setFlyCodeInt(&list[index], flycode) &&
					!passenger_setTypePassenger(&list[index], typePassenger))
			{
				(*idPassenger)++; //Increase Id number
				list[index].isEmpty = CARGADO;
			}
			retorno=0;
		}
	}
	return retorno;
}
/// @brief loads a passenger to the list passenger
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @param idPassenger
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ]  - (1) if cancelled register -
///  (-3) if Invalid input data - (3) if No more space - (-4) if setter error - (0) if Ok
int pass_loadPassenger (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass, int* idPassenger)
{
	int retorno = -1; //NULL pointer or len <0 cancelled desition
	Passenger buffer;

	if (list!= NULL && len > 0 && listFlyCode !=NULL && len_flyCode >= 0 && listTypePass !=NULL && len_typePass >= 0)
	{
		retorno=pass_getPassengerFromStdIn(&buffer, listFlyCode,len_flyCode,listTypePass,len_typePass);
		if(!retorno)
		{
			buffer.id = *idPassenger;
			buffer.isEmpty = CARGADO;
			printPassengers(&buffer, len, listFlyCode, len_flyCode, listTypePass, len_typePass);

			retorno=1; //Register a passenger cancelled
			if (!(retorno = pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres agregrar los datos de un nuevo pasajero al sistema?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: ")))
			{
				retorno = addPassenger(list, len, idPassenger, buffer.name, buffer.lastName, buffer.price,
						buffer.typePassenger, buffer.idflycode);
				// Add a passenger to the list
				if (!retorno)
				{
					retorno=0; // Ok
				}
			}
		}
	}
	return retorno;
}

/// @brief Sub funcion to registrer a passenger into the list
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (-3) if invalid imput  -
/// (3) if No more space - (-4) if setter error - (2) if invalid id - (-2) if invalid input flyCode - (4) if No flyCode into the list -
/// (1) if Register cancelled - (0) if back menu select - (0) if Ok
int pass_AltaPassengers(Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass, int* idPassenger, int* idFlyCode){

	int retorno=-1;  //NULL pointer or len <0 cancelled desition
	int opcion;


	if (list !=NULL && len >= 0 && listFlyCode !=NULL && len_flyCode >= 0 && listTypePass !=NULL && len_typePass >= 0 )
	{
		printOpcionesAlta ();

		retorno=-3; //invalid input data
		if (!utn_getNumero(&opcion, "Opcion: ", "\nError, intentalo de nuevo\n\n", 0, 2, 1))
		{
			switch (opcion)
			{
				case 1: //Alta Pasajero

					retorno = 3;//No more space
					if (pass_findEmptySpace(list, len)>=0) {

						retorno = pass_loadPassenger(list, len, listFlyCode, len_flyCode, listTypePass, len_typePass, idPassenger);
					}
					break;
				case 2://Alta codigo de vuelo

					retorno = 3;//No more space
					if (pass_findEmptySpaceFlyCode(listFlyCode, len_flyCode)>=0) {

						retorno = pass_loadFlyCode(listFlyCode, len_flyCode, idFlyCode);
					}
					break;
				case 0:
					//Back Menu
					retorno = 5;
					break;
			}
		}

	}
	return retorno;
}
/// @brief Prints the possible messages returned by the function ( pass_AltaPassengers ).
///
/// @param arrayPassengers
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return  int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (0) if Ok
int AltaPassengers (Passenger* arrayPassengers, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass,int* idPassenger, int* idFlyCode)
{
	int retorno=-1; // Invalid lengths or any NULL pointer
	int VereficarRetornoAltaFuncion;

	if(arrayPassengers!=NULL && len>0 && listFlyCode !=NULL && len_flyCode >= 0 && listTypePass !=NULL && len_typePass >= 0   ){


		if (pass_findEmptySpace(arrayPassengers, len) >=0 || pass_findEmptySpaceFlyCode(listFlyCode, len_flyCode)>=0)
		{
			VereficarRetornoAltaFuncion = pass_AltaPassengers(arrayPassengers, len,listFlyCode,len_flyCode,listTypePass,len_typePass,idPassenger,idFlyCode);

			switch (VereficarRetornoAltaFuncion)
			{
				case 0:
					printf("\n\t!--------ALTA COMPLETADA--------!\n\n");
					break;
				case 1:
					printf("\n\t!---------ALTA CANCELADA--------!\n\n");
					break;
				case 2:
					printf("\nNo existe ese id o fue dado antes de baja\n\n");
					break;
				case 3:
					printf("\nNo hay mas espacio disponible para almacenar otro (pasajero/codigo de vuelo), da de Baja uno para poder continuar\n\n");
					break;
				case 4:
					printf("\nIngresa primero un codigo de vuelo para poder dar de Alta un pasajero ;)\n\n");
					break;
				case -1:
					printf("\nError, lenth invalido o NULL pointer \n\n");
					break;
				case -2:
					printf("\nCodigo de vuelo invalido\n\n");
					break;
				case -3:
					printf("\nIngresa bien los datos, volve a intentarlo\n\n");
					break;
				case -4:
					printf("\nFalló una funcion 'Setters', vereficar cual funcion y en donde esta el error\n\n");
					break;
			}
			retorno=0; //OK
		}
		else{

			printf("\n\tNo hay espacio disponible\n\n");
		}
	}

	return retorno;
}

/*
 *
 * Modificar
 *
 */
/// @brief Changes the value of an entity pointer at a specific index
///
/// @param list
/// @param index
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (0) if Ok
int pass_modificarNuevoCodigoDeVuelo (Passenger* list, int index,FlyCode* listFlyCode, int len_flyCode)
{
	int change = -1;
	int flyCode;

	if (list!=NULL && index >= 0 && listFlyCode != NULL && len_flyCode > 0)
	{
		change = passenger_getFlyCodeFromStdInByInt(&flyCode, listFlyCode, len_flyCode);
		if (!change)
		{
			change = 1;// Change cancelled
			if (!pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				change = passenger_setFlyCodeInt(&list[index], flyCode);
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
int pass_modificarNuevoTipoPasajero (Passenger* list, int index, TypePassenger* listTypePass, int len_typePass)
{
	int change = -1;
	int typePassenger;

	if (list!=NULL && index >= 0  && listTypePass != NULL && len_typePass > 0 )
	{
		change = passenger_getTypePassengerFromStdIn(&typePassenger, listTypePass, len_typePass);
		if (!change)
		{
			change = 1;// Change cancelled
			if (!pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres cambiar?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))
			{
				change = passenger_setTypePassenger(&list[index], typePassenger);
			}
		}
	}
	return change;
}
/// @brief From 1 to 6, a new value is get and set to the entity
///
/// @param opcion
/// @param list
/// @param index
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (-3) if invalid imput  -
/// (3) if back menu - (2) if invalid id - (1) if modify canceled - (0) if Ok
int	pass_changePassengerAttribute(int opcion,Passenger* list, int index,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int change = -1;

	if (list!=NULL && index && list[index].isEmpty==CARGADO && listFlyCode != NULL && len_flyCode > 0 && listTypePass != NULL && len_typePass > 0 )
	{
		printf("\n||.........!Ingrese el nuevo dato!.........||\n\n");

		switch (opcion)
		{
			case 0:
				change=3;
				//back menu
				break;
			case 1:
				change= pass_modificarNuevoNombre(list, index);
				break;
			case 2:
				change =pass_modificarNuevoApellido(list, index);
				break;
			case 3:
				change = pass_modificarNuevoPrecio(list, index);
				break;
			case 4:
				change = pass_modificarNuevoCodigoDeVuelo(list, index, listFlyCode, len_flyCode);
				break;
			case 5:
				change = pass_modificarNuevoTipoPasajero(list, index, listTypePass, len_typePass);
				break;
		}
	}

	return change;
}
/// @brief Ask for the necessary data before modifying any field of the entity.
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (-3) if invalid imput  -
/// (3) if back menu - (2) if invalid id - (1) if modify canceled - (0) if Ok
///
int pass_ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno=-3; //Pointer NULL or len <0
	int idIngresado;
	int opcion;
	int index;

	if (list!=NULL && len>0 &&  listFlyCode != NULL && len_flyCode > 0 && listTypePass != NULL && len_typePass > 0)
	{
		printPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

		retorno = -3;//Invalid input data
		if (!utn_getNumero(&idIngresado, "\nId Modificar: ", "\n\tError opcion invalida\n\n", 0, INT_MAX, 1))
		{
			retorno=2; //  Not found Id
			if((index= findPassengerById(list, len, idIngresado))>=0)
			{
				printfPassengerOptionsMenuModificar();

				retorno=-2; //Error Opcion invalida
				if(!utn_getNumero(&opcion,"\nOpcion:  ", "\n\tError, opcion invalida\n\n", 0, 5, 1))
				{

					retorno = pass_changePassengerAttribute(opcion, list, index, listFlyCode, len_flyCode, listTypePass, len_typePass);
				}
			}
		}
	}

	return retorno;
}
/// @brief  Prints the possible messages returned by the function ( pass_ModificarPassengers ).
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (0) if Ok
int ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1;
	int modificarPassengers;
	int opcion;

	if (list != NULL && len > 0 && listFlyCode != NULL && len_flyCode  > 0 && listTypePass != NULL && len_typePass > 0 )
	{

		if (!pass_checkPassenger(list, len) || !pass_checkFlyCode(listFlyCode, len_flyCode))
		{
			sortPassengersById(list, len);

			if (!utn_getNumero(&opcion, "\n1)Modificar Pasajero\n2)Modificar Codigo de Vuelo\n\nOpcion: ", "\n\tError, opcion invalida\n\n", 1, 2, 1))
			{
				switch (opcion)
				{
					case 1:
						modificarPassengers = pass_ModificarPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);
						break;
					case 2:
						modificarPassengers = flyCode_ModifcarCodigoVuelo(listFlyCode, len_flyCode);
						break;
				}
				switch (modificarPassengers)
				{
					case 0:
						printf("\n\t!--------MODIFICAION COMPLETADA---------!\n\n");
						break;
					case 1:
						printf("\n\t!--------MODIFICACION CANCELADA---------!\n\n");
						break;
					case 2:
						printf("\nNo existe ese id o fue dado antes de baja\n\n");
						break;
					case 3:
						//Back Menu
						break;
					case -1:
						printf("\nError, lenth invalido o NULL pointer \n\n");
						break;
					case -2:
						printf("\nCodigo de vuelo invalido\n\n");
						break;
					case -3:
						printf("\nIngresa bien los datos, volve a intentarlo\n\n");
						break;

				}
			}
		}
		retorno = 0;
	}
	else{
		printf("\n\tNo hay Pasajeros o codigos de vuelo en el sistema para modificar :,(\n\n");
	}
	return retorno;
}
