#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tp2.h"
#include "categorias.h"
#include "estadosVuelo.h"
#include "input.h"

#define MAX_PASAJEROS 2000
#define MAX_NOMBRE 30
#define MAX_APELLIDO 30
#define MAX_CODIGOS 10
#define MAX_CATEGORIAS 3
#define MAX_ESTADOS 3


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int main() {

	setbuf(stdout, NULL);

	ePas pasajeros[MAX_PASAJEROS];
	inicilizarPasajeros(pasajeros, MAX_PASAJEROS);
	eCategoria categorias[MAX_CATEGORIAS] = {
			{101, "First"},
			{102, "Business"},
			{103, "Turista"}
	};

	eEstado estados[MAX_ESTADOS] = {

			{1, "ACTIVO"},
			{2, "DEMORADO"},
			{3, "CANCELADO"}

	};

	char salida = 'n';
	int proximoId = 1000;


	bienvenida();
	do{

			switch (menu()){

				case 1:

					altaPasajero(pasajeros, MAX_PASAJEROS, MAX_NOMBRE, MAX_APELLIDO, MAX_CODIGOS, categorias, MAX_CATEGORIAS, estados, MAX_ESTADOS, &proximoId);

					break;

				case 2:

					modificarPasajero(pasajeros, MAX_PASAJEROS, MAX_NOMBRE, MAX_APELLIDO, MAX_CODIGOS, categorias, MAX_CATEGORIAS, estados, MAX_ESTADOS);

					break;

				case 3:

					bajaPasajero(pasajeros, MAX_PASAJEROS, MAX_NOMBRE, MAX_APELLIDO, MAX_CODIGOS, categorias, MAX_CATEGORIAS, estados, MAX_ESTADOS);

					break;

				case 4:


					break;

				case 5:

					hardcodearPasajeros (pasajeros, MAX_PASAJEROS, &proximoId);

					break;

				case 6:

					salir(&salida);
					break;

				}


		}while(salida != 's');


	return 0;
}
