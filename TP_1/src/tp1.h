/*
 * tp1.h
 *
 *  Created on: 2 abr. 2022
 *      Author: mistereberle
 */

#ifndef TP1_H_
#define TP1_H_



#endif /* TP1_H_ */


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief muestra un menú predefinido, valida la respuesta del usuario y devuelve la opción elegida.
///
/// @return int

int menu ();

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


/// @brief recibe un número , un indicador de operacion ("1" recargo y "0" descuento) y porcentaje.
/// 	   Devuelve el número recibido con descuento o recargo del porcentaje indicado.
///
/// @param numero
/// @param operador
/// @param porcentaje
///
/// @return el resultado de agregar o quitar al numero recibido  el porcentaje indicado
///
float operacionPorcentaje (float, int, float);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief recibe un precio y la cotizacion de una divisa y devuelve el precio al cambio de moneda.
///
/// @param precio
/// @param cotizacion
///
/// @return el valor de ese precio transformado a la moneda indicada segun cotizacion
///
float divisa (float, float);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief recibe un valor total, cantidad de unidades y devuelve valor por unidad.
///
/// @param valorTotal
/// @param unidades
///
/// @return valor de cada unidad
///
float valorUnitario (float, float);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief recibe dos numeros y devuelve la diferencia entre estos priorizando un resultado positivo
///
/// @param numero 1
/// @param numero 2
///
/// @return diferencia entre numero 1 y numero 2
///
float diferencia (float, float);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief chequea si una variable numérica tiene contenido, devuelve un booleano
///
/// @param variable numérica entregada
///
/// @return devuelve "0" si la variable es igual a cero, o devuelve "1" si la variable es distinta de cero
///
int validacionCarga (float variable);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

