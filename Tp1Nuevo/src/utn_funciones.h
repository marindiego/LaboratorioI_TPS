/*
 * biblioteca.h
 *
 *  Created on: 12 sep. 2021
 *      Author: Usuario
 */

#ifndef UTN_FUNCIONES_H_
#define UTN_FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones_matematicasTP.h"




//Funciones con Strings
//int getString ( char *cadena, int tamMax);
//int getInt(int* pResultado);
//int getChar(char* pResultado, int tam);
//int esNumerica(char* cadena, int limite);
//int esTextoBasico(char* cadena);
//int validarFloat (char *stringRecibido, int largo);
//int getFloat(float* pResultado);
void getStringPractica (char cadena[], char mensaje[], int tam );

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos);
int utn_getCharNombre(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax);
int utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo, float maximo, int reintentos);
int PrimerasLetrasMayuscula(char*mensaje);
int ConcatenarNombreYApellido(char*nombre, char*apellido, char*nombreCompleto, int tam);


#endif /* UTN_FUNCIONES_H_ */
