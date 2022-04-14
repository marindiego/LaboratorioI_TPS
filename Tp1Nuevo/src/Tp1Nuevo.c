/*
 ============================================================================
 Name        : Menu.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "utn_funciones.h"

#define DESCUENTO 10
#define INTERESES 15

#define KILOMETROS 7090


int main(void) {

	setbuf(stdout, NULL);

	// Color de la consola en la carpeta
	system("color 70");

	int opcion;
	float diferenciaPrecio;

	//Kilometros
	float kilometros = 0;

	//Variables  A = ( Aerolíneas )
	float precioA = 0;
	float descuentoA;
	float aumentoA;
	float convercionBitcoinA;
	float precioUnitarioA;

	//Variables L = ( Latam )
	float precioL = 0;
	float descuentoL;
	float aumentoL;
	float convercionBitcoinL;
	float precioUnitarioL;

	// Portada del programa
	printf( "\t\t									\n"
			"\t\t\t								 	\n"
			"\t\t\tDiego Marin						\n"
			"\t\t\t1(c)								\n"
			"\t\t\tSistema de precios				\n"
			"\t\t\tpara agencias de vuelo 			\n"
			"\t\t								  \n\n");

    do
	{
    	if (kilometros == 0)
    	{
    		printf(" 1) Ingresar Kilómetros:\n");
    	}

    	if (kilometros != 0 ) {

    		printf(" 1) Ingresar Kilómetros: (  %.2f Kms )\n", kilometros);
		}

    	if (precioA == 0 || precioL == 0) {

    		printf(" 2) Ingresar Precio de Vuelos: ( Aerolíneas  , Latam )\n");
		}
    	else{

    		printf(" 2) Ingresar Precio de Vuelos: ( Aerolíneas = $%.2f , Latam = $%.2f )\n", precioA, precioL );
    	}




    	if (!utn_getNumero(    &opcion,
    						   " 3) Calcular todas las operaciones\n"
    						   " 4) Informar resultados           \n"
    						   " 5) Carga forzada de datos        \n"
    						   " 6) Salir 						  \n"
    						   "\n"
    						   "Opcion: ",
							   "\nError#404: opcion invalida         \n\n",
				 			   1, 6,      // Minimo, Maximo
							   0))  //Reintentos
    	{

    		switch(opcion)
    		{
			case 1:

				// Pedir Kilometros

				if(!utn_getFloat(&kilometros,
						"Kilometros: ",
						"Error#405: solo kilometros\n",
						0,10000000000000000.00, // Minimo, Maximo
						INT_MAX))  //Reintentos
				{
					printf("\nIngresar Kilómetros Completado!!!\n\n");
				}
				break;

			case 2:

				// Pedir los 2 precios

				if (!utn_getFloat(&precioA,
						"Precio Aerolineas: ",
						"Error#404: opcion invalida\n",
						0,10000000000000000.00,  // Minimo, Maximo
						INT_MAX)    //Reintentos
						&&
						!utn_getFloat(&precioL,
						"Precio Latam: ",
						"Error#405: opcion invalida\n",
						0,10000000000000000.00, // Minimo, Maximo
						INT_MAX))  //Reintentos
				{
					printf("\nIngresar Precios de Vuelos Completado!!!\n\n");
				}


				break;

			case 3:

				// Calcular todos los costos

				if(
						!CalcularCostosAgencia("Latam", precioL, kilometros, DESCUENTO, INTERESES, &descuentoL, &aumentoL, &convercionBitcoinL, &precioUnitarioL)
						&&
						!CalcularCostosAgencia("Aerolíneas", precioA, kilometros, DESCUENTO, INTERESES, &descuentoA, &aumentoA, &convercionBitcoinA, &precioUnitarioA)
				  )

				{
					//Mostrar las opciones a calcular

					InformarOpcionesCostosAgencia(DESCUENTO, INTERESES, "Latam","Aerolíneas" );
				}
				else{

					printf("\nError#410: Ingrese KMs o el precio de las agencias de viaje.\n\n");
				}

				break;

			case 4:

				if (kilometros > 0) {

					printf("\nKMs Ingresados: %0.2fkm\n\n", kilometros);

					if (
							!printfCostosAgencia("Latam", precioL,  descuentoL, aumentoL, convercionBitcoinL, precioUnitarioL)
							&&
							!printfCostosAgencia("Aerolíneas", precioA,  descuentoA, aumentoA,convercionBitcoinA, precioUnitarioA)
					   )
					{
						diferenciaPrecio = precioA - precioL;

						printf("La diferencia de precio es : $ %0.2f\n", diferenciaPrecio);
						printf("\nInformar Resultados Completado!!!\n\n");
					}
					else{
						printf("\nERROR#400, Ingrese la opcion 3 primero para informar resultados\n\n");
					}
				}



				 break;
			case 5:

				printf("\nKMs Ingresados: %0dkm\n\n", KILOMETROS);

				if (
						!HardcodearDatosAgenciasDeVuelo("Latam", 7090, 1350000.76, DESCUENTO, INTERESES)
						&&
						!HardcodearDatosAgenciasDeVuelo("Aerolíneas", 7090, 1335000.66,DESCUENTO, INTERESES))
				{
					printf("\nForzar Datos Completado!!!\n\n");
				}
				else{
					printf("\nOcurrio un error, vuelva a intentarlo\n\n");
				}

				break;

			case 6:
				printf("\nSalir completado\n");
				printf("Gracias por operar !\n");
				system("pause");
				break;

			} //Switch end

		} // main if end


	}while(opcion!=6);


	return EXIT_SUCCESS;
}


