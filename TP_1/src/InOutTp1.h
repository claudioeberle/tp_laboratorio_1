
#ifndef INPUTTP1_H_
#define INPUTTP1_H_



#endif /* INPUTTP1_H_ */

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
/// @return '1' si la operacion se pudo completar con éxito, '0' si hubo un error que no permitió ejecutar la funcion
int ingresoKms (float*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief presenta al usuario un submenu con las aerolineas disponibles
///
/// @return 'y' Aerolineas Argentinas, 'z' Latam.
char submenuAerolinea ();

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief recibe la aerolinea sobre la cual va a operar, pide precio al usuario y lo asigna por referencia a la variable correspondiente
///
/// @param 'y' si va a operar sobre Aerolineas Argentinas, 'z' si va a operar sobre Latam.
/// @param direccion de memoria de variable de precio de Aerolineas Argentinas.
/// @param direccion de memoria de variable de precio de Latam.
///
/// @return '1' si la operacion se pudo completar con éxito, '0' si hubo un error que no permitió ejecutar la funcion
int ingresoPrecios (char, float*, float*);

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

