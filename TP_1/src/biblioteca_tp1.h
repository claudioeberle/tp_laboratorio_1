#ifndef BIBLIOTECA_TP1_H_
#define BIBLIOTECA_TP1_H_



#endif /* BIBLIOTECA_TP1_H_ */

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief muestra un menú predefinido, valida la respuesta del usuario, muestra valor de variables kms, precioAA y precioLatam; y devuelve la opción elegida.
///
///	@param kilometros correspondientes al viaje
/// @param precio del viaje por Aerolineas Argentinas
/// @param precio del viaje por Latam
///
/// @return el valor de la opcion elegida por el usuario
int menu (float, float, float);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief solicita datos de kms al usuario y los asigna a la variable por referencia
///
///@param puntero a la variable kms
///
/// @return '1' si la operacion se pudo completar con éxito, '0' si hubo un error que no permitió ejecutar la funcion
int ingresoKms (float*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief le da la opción al usuario de reingresar el valor de la variable kms
///
/// @param puntero a la variable kms
///
/// @return '1' si la operacion se pudo completar con éxito, '0' si hubo un error que no permitió ejecutar la funcion
int reIngresoKms (float*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


/// @brief presenta al usuario un submenu con las aerolineas disponibles
///
/// @return 'y' Aerolineas Argentinas, 'z' Latam.
char submenuAerolinea ();

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief recibe la aerolinea sobre la cual va a operar, pide precio al usuario y lo asigna por referencia a la variable correspondiente
///
/// @param 'y' si va a operar sobre Aerolineas Argentinas, 'z' si va a operar sobre Latam.
/// @param puntero a variable precioAA
/// @param puntero a variable precioLatam
/// @param puntero a variable flag que marca si la variable ya tiene precio asignado
///
/// @return '1' si la operacion se pudo completar con éxito, '0' si hubo un error que no permitió ejecutar la funcion
int ingresoPrecios (char, float*, float*, int*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief le da la opcion al usuario de reingresar el valor de las variables precioAA y precioLatam
///
/// @param valor de aerolinea elegida por el usuario para operar
/// @param puntero a variable precioAA
/// @param puntero a variable precioLatam
///
/// @return '1' si la operacion se pudo completar con éxito, '0' si hubo un error que no permitió ejecutar la funcion
int reingresoPrecios(char, float*, float*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief muestra lista de resultados de calculos hechos en opcion 3 del menu de opciones.
///
/// @param kilometros
/// @param precio ticket Aerolineas Argentinas
/// @param precio ticket Latam
/// @param valor pago con debito de Aerolineas Argentinas
/// @param valor pago con debito de Latam
/// @param valor pago con credito de Aerolineas Argentinas
/// @param valor pago con credito de Latam
/// @param valor pago con bitcoins de Aerolineas Argentinas
/// @param valor pago con bitcoins de Latam
/// @param precio unitario Aerolineas Argentinas
/// @param precio unitario Latam
/// @param diferencia de precio entre Aerolineas Argentinas y Latam
///
void informes (float,  float, float, float, float, float, float, float, float, float, float, float);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief consulta al usuario si quiere continuar o salir del sistema
///
/// @return '0' si continua || '6' si sale del sistema
int continuar();

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief chequea si una variable numérica tiene contenido, devuelve un booleano
///
/// @param variable numérica entregada
///
/// @return devuelve "0" si la variable es igual a cero, o devuelve "1" si la variable es distinta de cero
///
int validacionCarga (float variable);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief valida que los datos necesarios para hacer los calculos hayan sido ingresados
///
/// @param variable de kms
/// @param variable precio Aerolineas Argentinas
/// @param variable precio Latam
///
/// @return '1' si todos los datos fueron ingresados, '0' si falta ingresar algún dato necesario
///
int validarDatosParaCalculo(float kms, float precioAA, float precioLatam);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief valida que los calculos del punto 3 ya hayan sido realizados antes de ejecutar el punto 4
///
/// @param flagCalculos
/// @return
int validacionCalculos(int flagCalculos);

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
///	@param puntero a variable donde se alojará el resultado de la operacion
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
/// @brief muestra por consola saludo de despedida
///
void saludo (void);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

