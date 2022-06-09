#include <stdio.h>
#include <stdlib.h>
#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	char id[100];
	char nombre[100];
	char apellido[100];
	char precio[100];
	char codigoVuelo[100];
	char estadoVuelo[100];
	char tipoPasajero[100];

	char falsaLectura[1000];

	Passenger* unPasajero;

	fscanf(pFile, "%s", falsaLectura); // evita la lectura del header

	//printf("3\n");

	while(!feof(pFile))
	{
		fscanf(pFile, "%[^,], %[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

		//printf("4\n");

		unPasajero = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);

		//printf("5\n");

		ll_add(pArrayListPassenger, unPasajero);

	//	printf("6\n");

		retorno = 1;

		//printf("7\n");
	}

	//printf("8\n");


    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
