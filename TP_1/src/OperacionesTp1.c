
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "InOutTp1.h"
#include "ValidacionesTp1.h"
#include "OperacionesTp1.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void calcularCostos(float kms, float precio, float btc, float* pDebito, float* pCredito, float* pBitcoin, float* pUnitario){

	*pDebito = operacionPorcentaje(precio, 0, 10);
	*pCredito = operacionPorcentaje(precio, 1, 25);
	*pBitcoin = divisa(precio, btc);
	*pUnitario = valorUnitario(precio, kms);

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float operacionPorcentaje (float numero, int operador, float porcentaje){

	float operacionPorcentaje;


	if (operador != 0 && operador != 1){

		printf("Parámetro de operación incorrecto. Ingrese \"0\" para descuento o \"1\" para recargo.");

	} //if
	else{

		switch (operador){

				case 0:
				porcentaje = (100-porcentaje) /100;
				break;


				case 1:
				porcentaje = (porcentaje /100)+1;
				break;

		}// switch
	}// else

	operacionPorcentaje = numero * porcentaje;
	return operacionPorcentaje;

} //operacionPorcentaje

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float divisa (float precio, float cotizacion){

	float divisa;

	divisa = precio / cotizacion;
	return divisa;

} //

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float valorUnitario (float valorTotal, float unidades){

	float valorUnitario;

	valorUnitario = valorTotal / unidades;
	return valorUnitario;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void diferencia (float num1, float num2, float* pDiferencia){

	if (num1 > num2){

		*pDiferencia = num1 - num2;
	}
	else{

		*pDiferencia = num2 - num1;
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

