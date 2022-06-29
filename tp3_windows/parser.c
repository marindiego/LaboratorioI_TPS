#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int (-1) NULL pointer/file
 *			   (-2) Exceso de caracteres de un atributo de la entidad
 *			   (-3) Campo invalido
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, int*nextId)
{
	char id[100];
	char nombre[100];
	char apellido[100];
	char precio[100];
	char codigoVuelo[100];
	char tipoPasajero[100];
	char estadoVuelo[100];
	int retorno =-1;

	Passenger* buffer;

	if ( pFile!=NULL &&  pArrayListPassenger!=NULL) {
		//falsa lectura
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		do{

			retorno = -2;// No pudo parsear correctamente desde el archivo
			if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo)==7) {

				//printf("%s %s %s %s %s %s %s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

				retorno = -3;// No pudo contruir un pasajero en memoria
				 buffer = Passenger_newParametrosTxt(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
				 if (buffer==NULL) {
					 break;
				 }
				 if (buffer!=NULL) {

					 retorno = 1; //OK
					 ll_add(pArrayListPassenger, buffer);

					 if (atoi(id) >= *nextId) {
						 *nextId = atoi(id)+1;
					 }
				}
			}

		}while(!feof(pFile));
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger,int*nextId)
{
	Passenger *buffer;
	int retorno=-1;
	int id;

	if (pFile!=NULL && pArrayListPassenger!=NULL && nextId!=NULL ) {

		do {
			buffer = Passenger_new();
			if (buffer != NULL) {

				fread(buffer, sizeof(Passenger), 1, pFile);

				if (feof(pFile)) {
					break;
				}
				else{
					ll_add( pArrayListPassenger, buffer);
					Passenger_getId(buffer, &id);

					if (id >= *nextId) {
						*nextId = id++;
					}
					retorno = 0;
				}
			}
			else
				retorno =-3;
		} while (!feof(pFile));
	}

    return retorno;
}
