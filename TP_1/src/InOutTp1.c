
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "InOutTp1.h"
#include "ValidacionesTp1.h"
#include "OperacionesTp1.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menu(float kms, float precioAA, float precioLatam){

	int opcion;
	int check;

	do{
		printf("\n\n MENÚ DE OPCIONES \n\n");
		printf("1. Ingresar Kilómetros: (Kms= %.2f)\n\n", kms);
		printf("2. Ingresar Precios de Vuelos: (Aerolíneas= $%.2f, Latam= $%.2f)\n\n", precioAA, precioLatam);
		printf("3. Calcular Costos\n\n");
		printf("4. Informar Resultados\n\n");
		printf("5. Carga Forzada de Datos\n\n");
		printf("6. Salir\n\n");

		printf("Elija una opción: ");
		fpurge(stdin);
		check = scanf("%d", &opcion);
		printf("\n\n");


		if(opcion <1 || opcion >6){

			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.");
		}


		}while(check == 0 && (opcion<1 || opcion>6));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int ingresoKms (float* pKms){

	int todoOK = 0;

	if(pKms != NULL){

	printf("Ingrese los kilómetros de vuelo: ");
	scanf("%f", pKms);

	todoOK = 1;

	return todoOK;

	}
	else{

	return todoOK;

	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

char submenuAerolinea (){

	char aerolinea;
	int cant;

	do{

		printf("Las opciones de vuelo son Aerolíneas Argentinas (y) y Latam (z).\n");
		printf("Por favor elija una opción: ");
		fpurge(stdin);
		cant = scanf("%c", &aerolinea);

		}while(cant == 0 || (aerolinea != 'y' && aerolinea != 'z'));

	return aerolinea;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int ingresoPrecios (char aerolinea, float* pPrecioAA, float* pPrecioLatam){

	char seleccion;
	int check = 0;

	if (pPrecioAA !=NULL && pPrecioLatam !=NULL){

	switch (aerolinea){

				case 'y':

					if (*pPrecioAA != 0){

						printf("El precio de Aerolíneas Argentinas ya ha sido ingresado.\n");
						printf("Aerolíneas= $%.2f", *pPrecioAA);

						printf("¿Desea ingresar nuevamente el valor?: s/n");
						fpurge(stdin);
						scanf("%c", &seleccion);

						if (seleccion == 's'){

							printf("Por favor ingrese el valor del vuelo por Aerolíneas Argentinas: $");
							scanf("%f", pPrecioAA);

						} // if seleccion

						else{

							break;

						} // else seleccion

					}// if reingreso

					else{

						printf("Por favor ingrese el valor del vuelo por Aerolíneas Argentinas: $");
						scanf("%f", pPrecioAA);

					}//else

				break; //case y


				case 'z':

					if (*pPrecioLatam != 0){

						printf("El precio de Latam ya ha sido ingresado.\n");
						printf("Latam= $%.2f", *pPrecioLatam);

						printf("¿Desea ingresar nuevamente el valor?: s/n");
						fpurge(stdin);
						scanf("%c", &seleccion);

							if (seleccion == 's'){

											printf("Por favor ingrese el valor del vuelo por Latam: $");
											scanf("%f", pPrecioLatam);

											} // if seleccion

						}// if reingreso

						else{

								printf("Por favor ingrese el valor del vuelo por Latam: $");
								scanf("%f", pPrecioLatam);

								}//else

				break; //case z
	} // switch

	check = 1;

	} // if todoOK

	else{

		printf("ERROR - Operación Inválida");
	}

	return check;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


void informes (float kms,  float precioAA, float precioLatam, float debitoAA, float debitoLatam, float creditoAA, float creditoLatam, float bitcoinAA, float bitcoinLatam, float unitarioAA, float unitarioLatam, float diferenciaPrecio){

		printf("Kms Ingresados: %.2f Kms \n\n", kms);
		printf("Precio Aerolineas Argentinas: $%.2f\n", precioAA);
		printf("a) Precio con tarjeta de débito: $%.2f \n", debitoAA);
		printf("b) Precio con tarjeta de crédito: $%.2f \n", creditoAA);
		printf("c) Precio pagando con bitcoin: BTC %.4f \n", bitcoinAA);
		printf("d) Precio unitario: $%.2f \n\n", unitarioAA);
		printf("Precio Latam: $%.2f\n", precioLatam);
		printf("a) Precio con tarjeta de débito: $%.2f \n", debitoLatam);
		printf("b) Precio con tarjeta de crédito: $%.2f \n", creditoLatam);
		printf("c) Precio pagando con bitcoin: BTC %.4f \n", bitcoinLatam);
		printf("d) Precio unitario: $%.2f \n\n", unitarioLatam);
		printf("La diferencia de precio es de $%.2f \n\n", diferenciaPrecio );

}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int continuar(){

	int opcion = 6;
	int check;
	char seleccion;


	do{
	printf("¿Desea volver a empezar o desea terminar?\n");
	printf("Ingrese 's' para volver a empezar o ingrese 'n' para terminar: ");
	fpurge(stdin);
	check = scanf("%c", &seleccion);

	}while(seleccion != 's' && seleccion != 'n');

	if(seleccion == 's'){

		opcion = 1;
		return opcion;
	}
	else{

		return opcion;
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

