#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estadosVuelo.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarEstadoId(eEstado estados[], int max_estados, int id){

	int retorno = 0;
	int flag = 0;

	if(estados != NULL && max_estados > 0){

		for(int i = 0; i < max_estados; i++){

			if(estados[i].id == id){

				retorno = 1;
				flag = 1;
				break;
			}
		}
		if(flag == 0){

			printf("No existe ningún Estado con el ID informado.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarEstadoIndice(eEstado estados[], int max_estados, int posicion){

	int retorno = 0;

	if(estados != NULL && max_estados > 0 && posicion >= 0 &&
	validarEstadoId(estados, max_estados, estados[posicion].id)){

		printf("%2d    %s\n", estados[posicion].id, estados[posicion].descripcion);
		retorno = 1;
	}
	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarEstados (eEstado estados[], int max_estados){

	int retorno = 0;

	if(estados != NULL && max_estados > 0){

		printf("\n Estados de Vuelo     \n");
		printf("--------------------\n");
		printf(" ID      Nombre    \n");
		printf("--------------------\n");
		for (int i = 0; i < max_estados; i++){

			mostrarEstadoIndice(estados, max_estados, i);
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarDescripcionEstado(eEstado estados[], int max_estados, int idEstado, char descEstado[]){

    int todoOk = 0;
    if(estados != NULL && descEstado != NULL && max_estados > 0){

         for(int i= 0; i < max_estados; i++){

            if( estados[i].id == idEstado){

                strncpy(descEstado, estados[i].descripcion, 10);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}
