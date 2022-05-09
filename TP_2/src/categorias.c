#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "categorias.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarCategoriaId(eCategoria categorias[], int max_categorias, int id){

	int retorno = 0;
	int flag = 0;

	if(categorias != NULL && max_categorias > 0){

		for(int i = 0; i < max_categorias; i++){

			if(categorias[i].id == id){

				retorno = 1;
				flag = 1;
				break;
			}
		}
		if(flag == 0){

			printf("No existe ninguna categoria con el ID informado.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarCategoriaIndice(eCategoria categorias[], int max_categorias, int posicion){

	int retorno = 0;

	if(categorias != NULL && max_categorias > 0 && posicion >= 0 &&
	validarCategoriaId(categorias, max_categorias, categorias[posicion].id)){

		printf("%2d  %10s\n", categorias[posicion].id, categorias[posicion].descripcion);
		retorno = 1;
	}
	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarCategoriaId(eCategoria categorias[], int max_categorias, int id){

	int retorno = 0;

	if(categorias != NULL && max_categorias > 0 && id >= 0){

		if(validarCategoriaId(categorias, max_categorias, id)){
			for(int i = 0; i < max_categorias; i++){

				if(categorias[i].id == id){

					printf("%s\n", categorias[i].descripcion);
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;

}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarCategorias (eCategoria categorias[], int max_categorias){

	int retorno = 0;

	if(categorias != NULL && max_categorias > 0){

		printf("\n    Categorias    \n");
		printf("------------------\n");
		printf(" ID     Nombre    \n");
		printf("------------------\n");
		for (int i = 0; i < max_categorias; i++){

			mostrarCategoriaIndice(categorias, max_categorias, i);
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarDescripcionCategoria(eCategoria categorias[], int max_categorias, int idCategoria, char descCategoria[])
{
	int retorno = 0;
	if(categorias != NULL && descCategoria != NULL && max_categorias > 0){

		 for(int i= 0; i < max_categorias; i++){

			if( categorias[i].id == idCategoria){

				strncpy(descCategoria, categorias[i].descripcion, max_categorias);
				retorno = 1;
				break;
			}

		 }
	}
	return retorno;
}
