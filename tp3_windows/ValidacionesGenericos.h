/*
 * ValidacionesGenericos.h
 *
 *  Created on: 9 may. 2022
 *      Author: Usuario
 */

#ifndef VALIDACIONESGENERICOS_H_
#define VALIDACIONESGENERICOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <windows.h>
#include "utn_funciones.h"

int isValidAlfaNumerico(char str[]);
int isValidNumerica(char* cadena, int limite);
int isValidFlotante (char *stringRecibido, int largo);
int isValidTextoBasico(char* cadena, int longitud);

#endif /* VALIDACIONESGENERICOS_H_ */
