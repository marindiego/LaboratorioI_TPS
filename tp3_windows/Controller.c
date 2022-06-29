#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,int*nextId)
{
	FILE* pFile;
	int retorno=-1;


	pFile=fopen(path, "r");

	if(pFile!=NULL && pArrayListPassenger!=NULL )
	{
		ll_clear(pArrayListPassenger);

		if (parser_PassengerFromText(pFile, pArrayListPassenger,nextId)==-3) {

			printf("\n\tUn pasajero en la lista no es valido\n\n");
		}
		else{

			fclose(pFile);
			printf("\n\tCargar archivo exitoso!!!\n\n");
			retorno= 0;
		}
	}

	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* nextId)
{
	FILE *pFile;
	int retorno;

	retorno = -1;
	pFile = fopen(path, "rb");

	ll_clear(pArrayListPassenger);

	if(pFile != NULL && pArrayListPassenger!=NULL )
	{
		if (parser_PassengerFromBinary(pFile,pArrayListPassenger, nextId)==-3) {

			printf("\n\tUn pasajero en la lista no es valido\n\n");
		}
		else{

			fclose(pFile);
			printf("\n\tCargar archivo exitoso!!!\n\n");
			retorno= 0;
		}
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* id)
{
	int retorno = -1; //NULL linkedList
	Passenger* buffer;

	if (pArrayListPassenger!=NULL && !ll_isEmpty(pArrayListPassenger)) {

		retorno = 2;
		buffer = Passenger_addOneFromStdin(id);

		if (buffer!=NULL) {

			retorno=1;
			if (!(Passenger_confirmDecision("\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres agregrar los datos de un nuevo pasajero ?\n"
					"Escribi (1) |Confirmar|  -   Escribi (0)  |Cancelar|\n"
					"Decisicion: "))) {
			}
			ll_add(pArrayListPassenger,buffer);
			(*id)++;
			retorno =0;
		}
	}
	Passenger_printReturnAdd(retorno);
    return 1;
}


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int len_pasajeros = ll_len( pArrayListPassenger);
	int retorno =-1;
	if (pArrayListPassenger != NULL) {

		printf( "\n"
				" \n" // Portada de la lista de pasajeros
				" Id         Nombre              Apellido              Precio            Codigo de vuelo          TipoPasajero            Estado       \n"
				" \n"
				"  \n");

		for (int i = 0; i < len_pasajeros; i++) {

			this = (Passenger*) ll_get( pArrayListPassenger, i);
			Passenger_printOne(this);
		}
		retorno = 0;
	}

    return retorno;
}
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno =-1;
	int idModifcar;
	int index;
	Passenger* buffer;

	if (pArrayListPassenger) {

		controller_ListPassenger(pArrayListPassenger);
		retorno=2;// Datos invalidos
		if (!utn_getNumero(&idModifcar, "\nId Modificar: ", "\n\tError opcion invalida\n\n", 0,INT_MAX, 1)) {

			retorno=-2; // No existe ese id
			if ((index=Passenger_findPassengerById(pArrayListPassenger, idModifcar))>=0) {

				buffer = (Passenger*)ll_get(pArrayListPassenger, index);
				retorno = Passenger_editOneFromStdin (buffer);
			}
		}
	}
	Passenger_printReturnEdit(retorno);
    return 1;
}
/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{

	int retorno=-1;
	int idBaja;
	int index;
	Passenger* buffer;
	Passenger* pAux;

	if (pArrayListPassenger!=NULL && !ll_isEmpty(pArrayListPassenger)) {

		controller_ListPassenger(pArrayListPassenger);
		if (!utn_getNumero(&idBaja, "\nId: ", "\n\tError, Id invalido\n\n", 0, INT_MAX, 1)) {

			retorno=-2; // No existe ese id
			if ((index=Passenger_findPassengerById(pArrayListPassenger, idBaja))>=0) {

				retorno= 1;//Cancel remove
				if (!(Passenger_confirmDecision("\n--------------\n"
						"Confirmar\n"
						"---------------\n"
						"Estas seguro que quieres eliminar este id de la base de datos del sistema?\n"
						"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
						"Decisicion: "))) {

					buffer = (Passenger*)ll_get(pArrayListPassenger, index);

					pAux=(Passenger*) ll_pop(pArrayListPassenger, index);
					Passenger_delete(pAux);

					ll_remove(pArrayListPassenger, index);
					Passenger_delete(buffer);
					retorno=0;
				}
			}
		}
	}
	Passenger_printReturnRemove(retorno);
	return 1;
}



/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int opcion;
	int order;

	LinkedList* ll_aux = ll_clone(pArrayListPassenger);

	if (pArrayListPassenger!=NULL) {

		retorno =0;
		Passenger_printOpcionsSort();
		if (!utn_getNumero(&opcion, "Opcion: ", "\tError, Opcion Invalida\n\n", 1, 7, 0)) {

			//1 = A-Z - 0 = Z-A
			switch (opcion) {
				case 1:
					Passenger_printOpcionMayorMenor();
					if (!utn_getNumero(&order, "Opcion: ", "\tError, opcion Invalida\n\n", 0, 1, 0)) {

						printf("\n\tEspera 1 minuto");
						ll_sort(ll_aux, Passenger_compareByName, order);
						controller_ListPassenger(ll_aux);
					}
					break;
				case 2:
					Passenger_printOpcionMayorMenor();
					if (!utn_getNumero(&order, "Opcion: ", "\tError, opcion Invalida\n\n", 0, 1, 0)) {

						printf("\n\tEspera 1 minuto");
						ll_sort(ll_aux, Passenger_compareByLastName, order);
						controller_ListPassenger(ll_aux);
					}
					break;
				case 3:
					Passenger_printOpcionMayorMenor();
					if (!utn_getNumero(&order, "Opcion: ", "\tError, opcion Invalida\n\n", 0, 1, 0)) {

						printf("\n\tEspera 1 minuto");
						ll_sort(ll_aux, Passenger_compareByPrice, order);
						controller_ListPassenger(ll_aux);
					}
					break;
				case 4:
					Passenger_printOpcionMayorMenor();
					if (!utn_getNumero(&order, "Opcion: ", "\tError, opcion Invalida\n\n", 0, 1, 0)) {

						printf("\n\tEspera 1 minuto");
						ll_sort(ll_aux, Passenger_compareByFlyCode, order);
						controller_ListPassenger(ll_aux);
					}
					break;
				case 5:
					Passenger_printOpcionMayorMenor();
					if (!utn_getNumero(&order, "Opcion: ", "\tError, opcion Invalida\n\n", 0, 1, 0)) {

						printf("\n\tEspera 1 minuto");
						ll_sort(ll_aux, Passenger_compareByTipoPasajero, order);
						controller_ListPassenger(ll_aux);
					}
					break;
				case 6:
					Passenger_printOpcionMayorMenor();
					if (!utn_getNumero(&order, "Opcion: ", "\tError, opcion Invalida\n\n", 0, 1, 0)) {

						printf("\n\tEspera 1 minuto");
						ll_sort(ll_aux, Passenger_compareByEstadoVuelo, order);
						controller_ListPassenger(ll_aux);
					}
					break;
			}
			printf("\n\tSort Exitoso\n\n");
		}
	}
	return retorno ;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* this;
	int id;
	char nombre[100];
	char apellido[100];
	float precio;
	char codigoVuelo[100];
	char tipoPasajero[100];
	char estadoVuelo[100];
	int len_passenger=ll_len(pArrayListPassenger);

	if ((pFile = fopen(path,"w"))!=NULL && !ll_isEmpty(pArrayListPassenger) ) {

		fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for (int i = 0; i < len_passenger; i++) {

			this= (Passenger*) ll_get(pArrayListPassenger, i);

			Passenger_getId(this, &id);
			Passenger_getNombre(this, nombre);
			Passenger_getApellido(this, apellido);
			Passenger_getPrecio(this, &precio);
			Passenger_getCodigoVuelo(this, codigoVuelo);
			Passenger_getTipoPasajero(this, tipoPasajero);
			Passenger_getEstadoVuelo(this, estadoVuelo);

			fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",
					id,
					nombre,
					apellido,
					precio,
					codigoVuelo,
					tipoPasajero,
					estadoVuelo);
		}
		fclose(pFile);

		printf("\n\tGuardar Exitoso!!!\n\n");
	}
	else
		printf("\n\tAgrega un pasajero a la lista :,)\n\n");
    return  1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{

	Passenger* this;
	FILE* bin;
	int len_passenger = ll_len(pArrayListPassenger);

	if ((bin = fopen(path,"wb"))!=NULL && !ll_isEmpty(pArrayListPassenger)) {

		for (int index = 0; index < len_passenger; ++index) {

			this = (Passenger*) ll_get(pArrayListPassenger, index);

			fwrite(this,sizeof(Passenger),1,bin);
		}
		fclose(bin);

		printf("\n\tGuardar Exitoso!!!\n\n");
	}
	else
			printf("\n\tAgrega un pasajero a la lista :,)\n\n");
    return 1;
}

