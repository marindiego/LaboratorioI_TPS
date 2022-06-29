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
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <windows.h>
#include "funciones_matematicasTP.h"
#include "ValidacionesGenericos.h"

 // Pedir Datos
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos);
int utn_getCharNombre(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax);
int utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getAlphaNumerico(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax);

// Setear una cadena de caracteres
int PrimerasLetrasMayuscula(char*mensaje);
int ConcatenarNombreYApellido(char*nombre, char*apellido, char*nombreCompleto, int tam);


#endif /* UTN_FUNCIONES_H_ */
