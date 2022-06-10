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

		//printf("%s\n", estadoVuelo);

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
	int retorno = 0;
	Passenger* auxPas = NULL;
	int cant = 0;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		while(!feof(pFile))
		{
			auxPas = Passenger_new();

			if(auxPas == NULL)
			{
				printf("No se consiguió memoria\n");
			}
			else
			{
				cant = fread(auxPas, sizeof(Passenger), 1, pFile);

				if(cant < 1)
				{
					break;
				}

				ll_add(pArrayListPassenger, auxPas);
				retorno = 1;
			}
		}
	}

    return retorno;
}

int passengerToText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	char buffer[7][100];

	Passenger* auxPas = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		for(int i=0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPas = (Passenger*) ll_get(pArrayListPassenger, i);

			if(Passenger_getIdStr(auxPas, buffer[0]) &&
			   Passenger_getNombre(auxPas, buffer[1]) &&
			   Passenger_getApellido(auxPas, buffer[2]) &&
			   Passenger_getPrecioStr(auxPas, buffer[3]) &&
			   Passenger_getTipoStr(auxPas, buffer[4]) &&
			   Passenger_getCodigoVuelo(auxPas, buffer[5]) &&
			   Passenger_getEstadoVueloStr(auxPas, buffer[6]))
			{

				fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s\n", buffer[0],
														 buffer[1],
														 buffer[2],
														 buffer[3],
														 buffer[4],
														 buffer[5],
														 buffer[6]);
			}
			else
			{
				Passenger_delete(auxPas);
			}
		}
		retorno = 1;
	}

	return retorno;
}

int passengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger* auxPas = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			mostrarPasajeroFila((Passenger*)ll_get(pArrayListPassenger, i));

			auxPas = (Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(auxPas, sizeof(Passenger), 1, pFile);

			retorno = 1;
		}

	}
	return retorno;
}

int nextIdToBinary(FILE* pFile, int* nextId)
{
	int retorno = 0;

	if(pFile != NULL && nextId != NULL)
	{
		fwrite(nextId, sizeof(int), 1, pFile);

		retorno = 1;
	}

	return retorno;
}
