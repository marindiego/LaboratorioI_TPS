/*
 * funciones_matematicasTP.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Usuario
 */

#ifndef FUNCIONES_MATEMATICASTP_H_
#define FUNCIONES_MATEMATICASTP_H_

#include <stdio.h>
#include "utn_funciones.h"


 // Funciones del Tp1 (Nuevo)
/// @param precio
/// @param descuento
/// @param resultado donde se va guardar el nuevo precio
/// @return Return -1 ( ERROR ) or Return 0 Ok
int CalcularDescuento (float precio, int porcentaje, float* resultado );
/// @param precio
/// @param aumento
/// @param resultado donde se va guardar el nuevo precio
/// @return Return -1 ( ERROR ) or Return 0 Ok
int CalcularAumento (float precio, int porcentaje, float* resultado );
/// @param pesosArg Recibe pesos argentinos
/// @param resultado Lo devuelve con un puntero
/// @return -1 No se pudo usar la funcion - 0 Todo bien
int DePesosAbitcoin (float pesosArg, float* resultado);
/// @param dividendo
/// @param divisor
/// @param resultado
/// @return -1 No se pudo usar la funcion - 0 Todo bien
int CalcularPrecioUnitario (float dividendo, float divisor, float* resultado );



// Funciones Matematicas
/// @param operando1 Recibe el primer operando
/// @param operando2 Recibe un segundo operando
/// @return me duevuelve el resultado
float Multiplicar (float operando1, float operando2);
/// @param operando1 Recibe el primer operando
/// @param operando2 Recibe un segundo operando
/// @return me devuleve la division
int Dividir (float operando1, float operando2, float* pResultado);
/// @param operador1 Recibe el primer operando
/// @param operador2 Recibe el segundo operando
/// @return me devuelve el resultado de la resta
float Restar (float operando1, float operando2);
/// @param a Recibe el primer operando
/// @param b Recibe el segundo operando
/// @return me devuelve el resultado de la suma a la funcion
float Sumar (float operando1, float operando2);
/// @param numeroIngresado recibe comom argumento el numero ingresado ya validado
/// @return me devuelve el factorail del numero ingresado
int CalcularFactorial (int numeroIngresado);
/// @param numeroIngresado recibe un flotante y se resta el mismo con un int
 /// @return si el resultado es 1 es flotante si es 0 es entero
int ValidarEntero (float numeroIngresado);
int ValidarRangoEntero (int numeroEnteroIngresado, int minimo, int maximo, char mensaje[], char mensajeError[]);
/// @param mensaje "ingrese si o si un numero entero"
/// @param mensajeError "en caso de no ser entero la cualquier numero y l oasigna a una varible
int IngresarNumeroEntero (char* mensaje, char *mensajeError, int minimo, int maximo);
float ValidacionTemperaturaFyC (float temperaturaF);
/// @param temperaturaC Recibe temperatura en Celsius
/// @return me devuelve la temperatura que no pase el rango minimo de congelacion y el maximo de ebullicion
int ValidacionTemperaturaCyF (float temperaturaC);
/// @param mensaje se le debe informar que no pase de de 0 y 100
void PedirTemperaturaC (char mensaje[]);
/// @param mensaje se le debe informar que no pase de de 0 y 210
void PedirTemperaturaF (char mensaje[]);
float IngresarNumeroFloat (char* mensaje, char *mensajeError, int minimo, int maximo);
void InicializarVectorEnteroExcluyente (int listadoEnteros [], int tam, int numeroExcluyente);
void CargarNumerosEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo);
void CargarEnterosNoSecuencial (int listaEnteros[], int tam, char mensaje[], char mensajeError[],  int minimo, int maximo);
void MonstrarCantidadNegativosPositivos (int listaEnteros[], int tam);
int VereficarParidad (int numeroIngresado);
int VereficarSigno (int numeroIngresado);
void SumarParidad (int listaEnteros[], int tam, int *pAcumuladorPares, int *pAcumuladorImpares);
void CalcularMayorImpares (int listaEnteros [], int tam);
void MostrarNumerosEnteros (int listaEnteros[], int tam, int numeroExcluyenteArray);
void MostrarEnteroAleatorio (int listaEnteros[], int tam);
void MostrarNumerosEnterosPares (int listaEnteros[], int tam);
void MostrarPosicionEnterosImpares (int listadoEnteros[], int tam);
void ContarNumerosRepetidos (int listaValores[], int tam);
int OrdenarNumerosEnterosDecrecienteNegativos (int listaEnteros[], int tam);
int OrdenarNumerosEnterosCreciente (int listaEnteros[], int tam);
int OrdenarNumerosEnterosDecreciente (int listaEnteros[], int tam);
int PromedearVectorEnteroPositivos (int listaEnteros[], int tam, float *pPromedioPositivos);
void SumarEnterosNegativos (int listaEnteros[], int tam, float *pSumaNegativos);
int CalcularMaximoArray (int listaEnteros[], int tam, int *pMaximo);
void MenuEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo, int numeroExcluyenteArray);
int BuscarUnNumero (int listaVectores[], int tam, int valorBusqueda );
#endif /* FUNCIONES_MATEMATICASTP_H_ */
