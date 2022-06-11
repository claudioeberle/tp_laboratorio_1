#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "ioput.h"


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
	char codigoVuelo[8];
	char tipoPasajero[100];
	char estadoVuelo[100];

	char falsaLectura[1000];

	Passenger* unPasajero;

	fscanf(pFile, "%s", falsaLectura); // evita la lectura del header

	while(!feof(pFile))
	{
		fscanf(pFile, "%[^,], %[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);


		unPasajero = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);

		if(unPasajero == NULL)
		{
			printf("falló la carga del usuario con id: %s\n", id);
		}

		ll_add(pArrayListPassenger, unPasajero);

		retorno = 1;

	}
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

		fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");

		for(int i=0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPas = (Passenger*) ll_get(pArrayListPassenger, i);

			if(Passenger_getIdStr(auxPas, buffer[0]) &&
			   Passenger_getNombre(auxPas, buffer[1]) &&
			   Passenger_getApellido(auxPas, buffer[2]) &&
			   Passenger_getPrecioStr(auxPas, buffer[3]) &&
			   Passenger_getCodigoVuelo(auxPas, buffer[4]) &&
			   Passenger_getTipoStr(auxPas, buffer[5]) &&
			   Passenger_getEstadoVueloStr(auxPas, buffer[6]))
			{
				/*
				printf("debbug PassengerToText parser:\n");
				printf("idStr: %s\n", buffer[0]);
				printf("nombre: %s\n", buffer[1]);
				printf("apellido: %s\n", buffer[2]);
				printf("precio: %s\n", buffer[3]);
				printf("codigo: %s\n", buffer[4]);
				printf("tipo: %s\n", buffer[5]);
				printf("estado: %s\n", buffer[6]);
				*/


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
	//int cont=0;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			//mostrarPasajeroFila((Passenger*)ll_get(pArrayListPassenger, i));

			//printf("PASER A BINARIO 1\n");
			//printf("%d\n", cont++);

			auxPas = (Passenger*)ll_get(pArrayListPassenger, i);

			//printf("%x\n", auxPas);

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
