
#ifndef OPERACIONESTP1_H_
#define OPERACIONESTP1_H_



#endif /* OPERACIONESTP1_H_ */

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief recibe un número , un indicador de operacion y porcentaje.
/// 	   Devuelve el número recibido con descuento o recargo del porcentaje indicado.
///
/// @param numero
/// @param operador ("1" recargo y "0" descuento)
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

/// @brief recibe dos numeros y asigna por referencia a la variable indicada la diferencia entre estos, priorizando un resultado positivo.
///
/// @param numero 1
/// @param numero 2
///	@param puntero a variabel donde se alojará el resultado de la operacion
///
void diferencia (float, float, float*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief asigna a cada variable el resultado de calculos de pago debito, pago credito, pago bitcoin, precio por km
///
/// @param variable con valor kilometros
/// @param variable con valor precio pasaje
/// @param variable con cotizacion del bitcoin
/// @param puntero a variable pago con Debito
/// @param puntero a variable pago con credito
/// @param puntero a variable pago con bitcoin
/// @param puntero a variable precio unitario
///
void calcularCostos(float, float, float, float*, float*, float*, float*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

