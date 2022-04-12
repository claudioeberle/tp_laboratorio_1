
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "InOutTp1.h"
#include "ValidacionesTp1.h"
#include "OperacionesTp1.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarDatosParaCalculo(float kms, float precioAA, float precioLatam){

	int check = 1;

	if (!validacionCarga(kms)){

		printf("Para poder realizar los cálculos debe informar los Kilómetros correspondientes al viaje. \n");
		printf("Para dicha tarea utilice la opción \"1\" del Menu de Opciones. \n\n");

		check = 0;
		return check;

		}else if (!validacionCarga(precioAA)){

			printf("Para poder realizar los cálculos debe informar el precio correspondiente al pasaje por Aerolíneas Argentinas. \n");
			printf("Para dicha tarea utilice la opción \"2\" del Menu de Opciones.\n");
			printf("Y luego la opción \"y\" \n");

			check = 0;
			return check;

			}else if (!validacionCarga(precioLatam)){

				printf("Para poder realizar los cálculos debe informar el precio correspondiente al pasaje por Latam. \n");
				printf("Para dicha tarea utilice la opción \"2\" del Menu de Opciones.\n");
				printf("Y luego la opción \"z\" \n");

				check = 0;
				return check;

			}
			else{

				return check;

			}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validacionCalculos(int flagCalculos){

	int check = 0;

	if (validacionCarga(flagCalculos)){

		check = 1;
		return check;
	}
	else{

		printf("Los datos solicitados son resultado de cálculos que aún no han sido realizados.\n");
		printf("Para realizar dichos cálculos por favor utilice la opción \"3\" del Menu de Opciones.");
		return check;
	}
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


