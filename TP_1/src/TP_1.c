
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1.h"


/*
/// @brief muestra un menú predefinido, valida la respuesta del usuario y devuelve la opción elegida.
///
/// @return int

int menu ();



/// @brief recibe un número , un indicador de operacion ("1" recargo y "0" descuento) y porcentaje.
/// 	   Devuelve el número recibido con descuento o recargo del porcentaje indicado.
///
/// @param numero
/// @param operador
/// @param porcentaje
///
/// @return el resultado de agregar o quitar al numero recibido  el porcentaje indicado
///
float operacionPorcentaje (float, int, float);



/// @brief recibe un precio y la cotizacion de una divisa y devuelve el precio al cambio de moneda.
///
/// @param precio
/// @param cotizacion
///
/// @return el valor de ese precio transformado a la moneda indicada segun cotizacion
///
float divisa (float, float);



/// @brief recibe un valor total, cantidad de unidades y devuelve valor por unidad.
///
/// @param valorTotal
/// @param unidades
///
/// @return valor de cada unidad
///
float valorUnitario (float, float);



/// @brief recibe dos numeros y devuelve la diferencia entre estos priorizando un resultado positivo
///
/// @param numero 1
/// @param numero 2
///
/// @return diferencia entre numero 1 y numero 2
///
float diferencia (float, float);



/// @brief chequea si una variable numérica tiene contenido, devuelve un booleano
///
/// @param variable numérica entregada
///
/// @return devuelve "0" si la variable es igual a cero, o devuelve "1" si la variable es distinta de cero
///
int validacionCarga (float variable);

*/



int main() {

	setbuf(stdout, NULL);


	int opcion=0;
	float kms=0;
	char aerolinea;
	float precioAA;
	float precioLatam;

	int flagCalculos=0;
	float btc=4606954.55;
	float debitoAA;
	float debitoLatam;
	float creditoAA;
	float creditoLatam;
	float bitcoinAA;
	float bitcoinLatam;
	float unitarioAA;
	float unitarioLatam;
	float diferenciaPrecio;


	opcion = menu();

	do{

		switch (opcion){


			case 1: // kilometros
				printf("Ingrese los kilómetros de vuelo: ");
				scanf("%f", &kms);

				opcion = menu();
				break; // break 1 switch gral


			case 2: // precios vuelo x aerolinea

				if (validacionCarga(kms)){

					printf("Kms: %.2f \n\n", kms);

				}else {

					printf("Kms: Información no proporcionada. \n\n");
				}

				do{

				printf("Las opciones de vuelo son Aerolíneas Argentinas (y) y Latam (z).\n");
				printf("Por favor elija una opción: ");
				fpurge(stdin);
				scanf("%c", &aerolinea);

				}while(aerolinea != 'y' && aerolinea != 'z');

				switch (aerolinea){

					case 'y':
						printf("Por favor ingrese el valor del vuelo por Aerolíneas Argentinas: $");
						scanf("%f", &precioAA);


					break; //break AA

					case 'z':
						printf("Por favor ingrese el valor del vuelo por Latam: $");
						scanf("%f", &precioLatam);


					break; // break latam

					} //switch aerolinea

			opcion = menu();
			break; // break 2 switch gral


			case 3: // calcular costos

				if (validacionCarga(kms)){

					printf("Kms: %.2f \n\n", kms);

				}else {

					printf("Para poder realizar los cálculos debe informar los Kilómetros correspondientes al viaje. \n");
					printf("Para dicha tarea utilice la opción \"1\" del Menu de Opciones. \n\n");

					opcion = menu();
					break;
				}

				if (validacionCarga(precioAA)){

					printf("Precio Aerolíneas Argentinas: $%.2f \n\n", precioAA);


				}else {

					printf("Para poder realizar los cálculos debe informar el precio correspondiente al pasaje por Aerolíneas Argentinas. \n");
					printf("Para dicha tarea utilice la opción \"2\" del Menu de Opciones.\n");
					printf("Y luego la opción \"y\" \n");

					opcion = menu();
					break;
				}

				if (validacionCarga(precioLatam)){

					printf("Precio Latam: $%.2f \n\n", precioLatam);


				}else {

					printf("Para poder realizar los cálculos debe informar el precio correspondiente al pasaje por Latam. \n");
					printf("Para dicha tarea utilice la opción \"2\" del Menu de Opciones.\n");
					printf("Y luego la opción \"z\" \n");

					opcion = menu();
					break;
				}



				debitoAA = operacionPorcentaje(precioAA, 0, 10); // descuento 10%
				debitoLatam = operacionPorcentaje(precioLatam, 0, 10); // descuento 10%

				creditoAA = operacionPorcentaje(precioAA, 1, 25); // recargo 25%
				creditoLatam = operacionPorcentaje(precioLatam, 1, 25); // recargo 25%

				bitcoinAA = divisa(precioAA, btc); //valor en Bitcoin
				bitcoinLatam = divisa(precioLatam, btc); // valor en bitcoin

				unitarioAA = valorUnitario(precioAA, kms);
				unitarioLatam = valorUnitario(precioLatam, kms);

				diferenciaPrecio = diferencia(precioAA, precioLatam);

				flagCalculos = 1;

				printf("¡Se han realizado los calculos de costo exitosamente!\n");
				printf("Para consultar los resultados utilice la opción \"4\" del Menu de Opciones.");


			opcion = menu();
			break;

			case 4:

				if (validacionCarga(flagCalculos)){

					printf("Kms Ingresados: %.2f Kms \n\n", kms);

					printf("Precio Aerolineas Argentinas: $%.2f\n", precioAA);
					printf("a) Precio con tarjeta de débito: $%.2f \n", debitoAA);
					printf("b) Precio con tarjeta de crédito: $%.2f \n", creditoAA);
					printf("c) Precio pagando con bitcoin: BTC%.4f \n", bitcoinAA);
					printf("d) Precio unitario: $%.2f \n\n", unitarioAA);
					printf("Precio Latam: $%.2f\n", precioLatam);
					printf("a) Precio con tarjeta de débito: $%.2f \n", debitoLatam);
					printf("b) Precio con tarjeta de crédito: $%.2f \n", creditoLatam);
					printf("c) Precio pagando con bitcoin: BTC%.4f \n", bitcoinLatam);
					printf("d) Precio unitario: $%.2f \n\n", unitarioLatam);

					printf("La diferencia de precio es de $%.2f", diferenciaPrecio );


				}
				else{

					printf("Los datos solicitados son resultado de cálculos que no han sido realizados.\n");
					printf("Para realizar dichos cálculos por favor utilice la opción \"3\" del Menu de Opciones.");

					opcion = menu();
					break;

				}

			opcion = menu();
			break;

			case 5:

				printf("cacona");

			opcion = menu();
			break;

			case 6:

				opcion = 6;

			break;


			}//switch general


	}while(opcion != 6);

	printf("¡Hasta Luego!");
	printf("Gracias por utilizar el Sistema.");

	return 0;

}//main





/*



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



float divisa (float precio, float cotizacion){

	float divisa;

	divisa = precio / cotizacion;
	return divisa;

} //



float valorUnitario (float valorTotal, float unidades){

	float valorUnitario;

	valorUnitario = valorTotal / unidades;
	return valorUnitario;
}



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



*/



















