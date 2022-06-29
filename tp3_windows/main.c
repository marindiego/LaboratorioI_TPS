#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int nextId = 1;
    int flagRead=1;;

    LinkedList* listaPasajeros = ll_newLinkedList();


    do{


    	Passenger_printfPassengerOptionsMenu();

    	if (!utn_getNumero(&option, "\nOpcion: ", "Error, numero invalido\n", 1, 10, INT_MAX)) {


			switch(option)
			{
				case 1:
					if (flagRead) {

						controller_loadFromText("data.csv",listaPasajeros, &nextId);
						flagRead=0;
					}
					break;
				case 2:
					if (flagRead) {
						controller_loadFromBinary("data.bin", listaPasajeros, &nextId);
					}
					break;
				case 4:
					controller_editPassenger(listaPasajeros);
					break;
				case 3:
					controller_addPassenger(listaPasajeros,&nextId);
					break;
				case 5:
					controller_removePassenger(listaPasajeros);
					break;
				case 6:
					controller_ListPassenger(listaPasajeros);
					break;
				case 7:
					controller_sortPassenger(listaPasajeros);
					break;
				case 8:
					if (!flagRead) {

						controller_saveAsText("data.csv", listaPasajeros);
					}
					else
						printf("\n\tCarga primero un archivo\n\n");
					break;
				case 9:
					if (!flagRead) {
						controller_saveAsBinary("data.bin", listaPasajeros);
					}
					else
						printf("\n\tCarga primero un archivo\n\n");
					break;
				case 10:
					printf("\nSalir Completado\n");
					break;
			}
		}

    }while(option != 10);

    return 0;
}

