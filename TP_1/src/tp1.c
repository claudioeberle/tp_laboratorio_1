
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1.h"


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menu(){

	int opcion;

	do{
		printf("\n\n MENÚ DE OPCIONES \n\n");
		printf("1. Ingresar Kilómetros\n");
		printf("2. Ingresar Precios de Vuelos\n");
		printf("3. Calcular Costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga Forzada de Datos\n");
		printf("6. Salir\n\n");

		printf("Elija una opción: ");
		scanf("%d", &opcion);
		printf("\n\n");


		if(opcion <1 || opcion >6){

			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.");
		}


		}while(opcion<1 || opcion>6);

		return opcion;
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

float diferencia (float num1, float num2){

	float diferencia;

	if (num1 > num2){

		diferencia = num1 - num2;
	}
	else{

		diferencia = num2 - num1;
	}

	return diferencia;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validacionCarga (float variable){

	int validacionCarga;

	if (variable == 0){

		validacionCarga = 0;
	}
	else{

		validacionCarga = 1;
	}
	return validacionCarga;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/








