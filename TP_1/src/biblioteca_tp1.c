
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca_tp1.h"

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

	int todoOK;
	int check;

	todoOK = 0;
	check = 0;

	if(pKms != NULL){

		do{
		printf("Ingrese los kilómetros de vuelo: ");
		fpurge(stdin);
		check = scanf("%f", pKms);

		}while(!check);

		todoOK = 1;

	}

	return todoOK;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int reIngresoKms (float* pKms){

	int todoOK;
	int check;
	char seleccion;

	todoOK = 0;
	check = 0;

	if(pKms != NULL){

		printf("Los kilómetros ya han sido ingresados.\n\n");
		printf("Kilómetros ingresados: %.2f\n\n", *pKms);

		do{

			printf("¿Desea ingresar nuevamente el valor? (s/n): ");
			fpurge(stdin);
			check = scanf("%c", &seleccion);

		}while(!check || (seleccion != 's' && seleccion != 'n'));


		if (seleccion == 's'){

			do{

				printf("Ingrese los kilómetros de vuelo: ");
				fpurge(stdin);
				check = scanf("%f", pKms);

			}while(!check);

		} // if reingreso

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
	int check;

	do{

		printf("Las opciones de vuelo son Aerolíneas Argentinas (y) y Latam (z).\n");
		printf("Por favor elija una opción: ");
		fpurge(stdin);
		check = scanf("%c", &aerolinea);

		}while(!check || (aerolinea != 'y' && aerolinea != 'z'));

	return aerolinea;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int ingresoPrecios (char aerolinea, float* pPrecioAA, float* pPrecioLatam, int* pFlagReingreso){

	int todoOK;
	int check;

	todoOK = 0;
	check = 0;


	if (pPrecioAA !=NULL && pPrecioLatam !=NULL){


		switch (aerolinea){

				case 'y':

						if (!*pPrecioAA){

							do{
								printf("Por favor ingrese el valor del vuelo por Aerolíneas Argentinas: $");
								fpurge(stdin);
								check = scanf("%f", pPrecioAA);

							}while(!check);

							break;
						}
						else{

							*pFlagReingreso= 1;
							break;
						}


				case 'z':

						if (!*pPrecioLatam){

							do{

								printf("Por favor ingrese el valor del vuelo por Latam: $");
								fpurge(stdin);
								check = scanf("%f", pPrecioLatam);

							}while(!check);

							break;
						}
						else{

							*pFlagReingreso = 1;
							break;
						}

		}//switch

		todoOK = 1;

	}// if todoOK

	else{

		printf("ERROR - Operación Inválida");

	} // else todoOK


	return todoOK;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int reingresoPrecios(char aerolinea, float* pPrecioAA, float* pPrecioLatam){

	int todoOK;
	int check;
	char seleccion;

	todoOK = 0;
	check = 0;

	if (pPrecioAA !=NULL && pPrecioLatam !=NULL){

		switch (aerolinea){

					case 'y':

								printf("El precio de Aerolíneas Argentinas ya ha sido ingresado.\n\n");
								printf("Aerolíneas= $%.2f\n\n", *pPrecioAA);

								do{

									printf("¿Desea ingresar nuevamente el valor? (s/n): ");
									fpurge(stdin);
									check = scanf("%c", &seleccion);

								}while(!check || (seleccion != 's' && seleccion != 'n'));


								if (seleccion == 's'){

									do{

										printf("Por favor ingrese el valor del vuelo por Aerolíneas Argentinas: $");
										fpurge(stdin);
										check = scanf("%f", pPrecioAA);

									}while(!check);

								break;

								} // if reingreso

								else{

									break;
								} // else reingreso


					case 'z':

								printf("El precio de Latam ya ha sido ingresado.\n\n");
								printf("Latam= $%.2f\n\n", *pPrecioLatam);

								do{

									printf("¿Desea ingresar nuevamente el valor? (s/n): ");
									fpurge(stdin);
									check = scanf("%c", &seleccion);

								}while(!check || (seleccion != 's' && seleccion != 'n'));

								if (seleccion == 's'){

									do{

										printf("Por favor ingrese el valor del vuelo por Latam: $");
										fpurge(stdin);
										check = scanf("%f", pPrecioLatam);

									}while(!check);

									break;

								} // if reingreso

								else{

									break;

								} // else reingreso

		}//switch

		todoOK = 1;

	}// if todoOK

	else{

		printf("ERROR - Operación Inválida");

	} // else todoOK

	return todoOK;

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

	int opcion;
	int check;
	char seleccion;

	opcion = 6;

	do{
	printf("¿Desea volver a empezar o desea terminar?\n\n");
	printf("Ingrese 's' para volver a empezar o ingrese 'n' para terminar: ");
	fpurge(stdin);
	check = scanf("%c", &seleccion);

	}while(!check || (seleccion != 's' && seleccion != 'n'));

	if(seleccion == 's'){

		opcion = 1;
	}

	return opcion;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int validarDatosParaCalculo(float kms, float precioAA, float precioLatam){

	int check;

	check = 1;

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

	int check;

	check = 0;

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

	*pDiferencia = num1 - num2;

	printf ("Los Calculos se realizaron con Éxito.\n\n");
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void saludo (void){

	printf("\n\n¡Hasta Luego!\n\n");
	printf("Gracias por utilizar el Sistema. \n\n");
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

