
#ifndef VALIDACIONESTP1_H_
#define VALIDACIONESTP1_H_



#endif /* VALIDACIONESTP1_H_ */

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


