#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "ioput.h"




int controller_loadIdFromBinary(char* path , int* nextId)
{
	int retorno = 0;

	if(path != NULL && nextId != NULL)
	{

		FILE* pFile = fopen(path, "rb");

		if(pFile == NULL)
		{
			perror("Error al leer el archivo de IDs\n");
		}
		else
		{
			fread(nextId, sizeof(int), 1, pFile);
			retorno = 1;
		}
	}
	return retorno;


}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* file = fopen(path, "r");

		if(file == NULL)
		{
			perror("No se pudo conseguir memoria\n");
		}
		else
		{
			parser_PassengerFromText(file, pArrayListPassenger);
			retorno = 1;
		}
		fclose(file);
	}

    return retorno;
}



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* file =fopen(path, "rb");

		if(file == NULL)
		{
			system("clear");
			perror("ERROR");
		}
		else
		{
			parser_PassengerFromBinary(file, pArrayListPassenger);
			retorno = 1;
		}

		fclose(file);

	}
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param pIndex int*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* nextId)
{
	int retorno = 0;
	char confirmacion;

	Passenger* newPassenger = Passenger_new();

	if(newPassenger == NULL && nextId)
	{
		printf("No se pudo obtener memoria\n");
	}
	else
	{
		if( pArrayListPassenger != NULL)
		{
			system("clear");
			printf("\n--------------------------");
			printf("\n    ALTA DE PASAJERO      ");
			printf("\n--------------------------\n");

			newPassenger->id = *nextId;

			printf("Id: %d\n", newPassenger->id);

			if( cargaString (newPassenger->nombre, 50, "\nNombre: ", "Dato Incorrecto. \n"))
			{
				if(cargaString (newPassenger->apellido, 50, "\nApellido: ", "Dato Incorrecto. \n"))
				{
					if(cargarPrecio(&newPassenger->precio))
					{
						if(cargarCodigoVuelo(newPassenger->codigoVuelo, 10))
						{
							if(cargarTipoPasajero(&newPassenger->tipoPasajero))
							{
								if(cargarEstadoVuelo(&newPassenger->estadoVuelo))
								{

									system("clear");
									printf("\n--------------------------");
									printf("\n     NUEVO  PASAJERO      ");
									printf("\n--------------------------");

									mostrarPasajero(newPassenger);

									if( getCharacter("\nConfirmar carga de nuevo pasajero (s): ","Dato Incorrecto", &confirmacion))
									{
										if(confirmacion == 's' || confirmacion == 'S')
										{

											ll_add(pArrayListPassenger, newPassenger);

											(*nextId)++;

											system("clear");
											printf("\n********************\n");
											printf("\n   CARGA EXITOSA   \n\n");
											printf("********************\n");

											retorno = 1;
										}
										else{

											system("clear");
											printf("\n********************\n");
											printf("\n  CARGA CANCELADA \n\n");
											printf("********************\n");

										}
									}
								}
								else
								{
									system("clear");
									printf("Error en la carga.-\n\n\n********************\n\n  CARGA CANCELADA \n\n********************\n");
								}

							}
							else
							{
								system("clear");
								printf("Error en la carga.-\n\n\n********************\n\n  CARGA CANCELADA \n\n********************\n");
							}
						}
						else
						{
							system("clear");
							printf("Error en la carga.-\n\n\n********************\n\n  CARGA CANCELADA \n\n********************\n");
						}
					}
					else
					{
						system("clear");
						printf("Error en la carga.-\n\n\n********************\n\n  CARGA CANCELADA \n\n********************\n");
					}
				}
				else
				{
					system("clear");
					printf("Error en la carga.-\n\n\n********************\n\n  CARGA CANCELADA \n\n********************\n");
				}
			}
			else
			{
				system("clear");
				printf("Error en la carga.-\n\n\n********************\n\n  CARGA CANCELADA \n\n********************\n");
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char salir;
	int opcion;
	char confirmacion = 'n';
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char descTipo[25];
	char descTipoNuevo[25];
	char codigoVuelo[10];
	Passenger* pasajero = NULL;
	int index = 0;

	if(pArrayListPassenger != NULL)
	{
		system("clear");
		printf("\n--------------------------------\n");
		printf("   MODIFICACI??N  DE  PASAJERO      \n");
		printf("-------------------------------- \n");

		if(controller_ListPassenger(pArrayListPassenger))
		{

			if(get_int("\nElija el ID del pasajero que quiere modificar: ", "Dato incorrecto", 1, 10000, &id) &&
				buscarPasajeroPorId(pArrayListPassenger, &index, id))
			{

				do{
					pasajero = (Passenger*) ll_get(pArrayListPassenger, index);

					if(pasajero == NULL)
					{
						printf("Pasajero no encontrado\n");
					}
					else
					{
						mostrarPasajero(pasajero);

						opcion = menuModificar();

						switch(opcion)
						{

								case 1:

									system("clear");
									mostrarPasajero(pasajero);
									printf("-------------------------------- \n\n");
									if(cargaString (nombre, 50, "\nNuevo nombre: ", "Dato incorrecto\n") == 1){
										printf("\n---------------\n");
										printf("Nombre anterior: %s\n", pasajero->nombre);
										printf("Nombre nuevo: %s\n", nombre);
										getCharacter("\nConfirmar modificaci??n (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											strncpy(pasajero->nombre, nombre, 50);
											system("clear");
											printf("\n\n->->-> MODIFICACI??N EXITOSA <-<-<-\n");

										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACI??N CANCELADA <-<-<-\n");
										}
									}
									break;

								case 2:

									system("clear");
									mostrarPasajero(pasajero);
									printf("-------------------------------- \n\n");
									if(cargaString (apellido, 50, "\nNuevo apellido: ", "Dato incorrecto\n") == 1){
										printf("\n---------------\n");
										printf("Apellido anterior: %s\n", pasajero->apellido);
										printf("Apellido nuevo: %s\n", apellido);
										getCharacter("\nConfirmar modificaci??n (s): ", "Dato Incorrecto", &confirmacion);
										if(confirmacion == 's'){

											strncpy(pasajero->apellido, apellido, 50);
											system("clear");
											printf("\n\n->->-> MODIFICACI??N EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACI??N CANCELADA <-<-<-\n");
										}
									}

									break;

								case 3:

									system("clear");
									mostrarPasajero(pasajero);
									printf("-------------------------------- \n\n");
									if(get_float("Nuevo precio: $", "Dato incorrecto\n", 0, 9999999, &precio) == 1){
										printf("\n---------------\n");
										printf("Precio anterior: $%.2f\n", pasajero->precio);
										printf("Precio nuevo: $%.2f\n", precio);
										getCharacter("\nConfirmar modificaci??n (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											pasajero->precio = precio;
											system("clear");
											printf("\n\n->->-> MODIFICACI??N EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACI??N CANCELADA <-<-<-\n");
										}
									}
									break;

								case 4:

									system("clear");
									mostrarPasajero(pasajero);
									printf("-------------------------------- \n\n");
									if(get_code("\nNuevo c??digo: ", "Dato incorrecto\n", codigoVuelo, 10) == 1){
										printf("\n---------------\n");
										printf("C??digo anterior: %s\n", pasajero->codigoVuelo);
										printf("C??digo nuevo: %s\n", codigoVuelo);
										getCharacter("\nConfirmar modificaci??n (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											strcpy(pasajero->codigoVuelo, codigoVuelo);
											system("clear");
											printf("\n\n->->-> MODIFICACI??N EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACI??N CANCELADA <-<-<-\n");
										}
									}

									break;

								case 5:

									system("clear");
									mostrarPasajero(pasajero);
									printf("-------------------------------- \n\n");
									if(cargarTipoPasajero(&tipoPasajero) == 1){

										descripcionTipoPasajero(pasajero->tipoPasajero, descTipo);
										descripcionTipoPasajero(tipoPasajero, descTipoNuevo);

										printf("\n---------------\n");

										printf("Categor??a anterior: %s\n", descTipo);

										printf("Categor??a nueva: %s\n", descTipoNuevo);

										getCharacter("\nConfirmar modificaci??n (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											pasajero->tipoPasajero = tipoPasajero;
											system("clear");
											printf("\n\n->->-> MODIFICACI??N EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACI??N CANCELADA <-<-<-\n");
										}
									}

									break;

								case 6:

									salir = 's';
									system("clear");
									break;
						}
					}

				}while(salir != 's' && salir != 'S');

				retorno = 1;
			}
			else
			{
				system("clear");
				printf("\n\nRevise el dato ingresado y vuelva a intentar\n.");
			}
		}


	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char confirmacion = 'n';
	int pasId;
	int index;
	Passenger* pasajero = NULL;
	int indexPas;


	if(pArrayListPassenger != NULL)
	{
		system("clear");
		printf("\n--------------------------------\n");
		printf("      BAJA   DE   PASAJERO       \n");
		printf("-------------------------------- \n");

		if(controller_ListPassenger(pArrayListPassenger))
		{
		   if(get_int("\nElija el ID del pasajero que quiere dar de baja: ", "Dato incorrecto", 1, 10000, &pasId) &&
		   buscarPasajeroPorId(pArrayListPassenger, &indexPas, pasId))
		   {
				pasajero = (Passenger*) ll_get(pArrayListPassenger, indexPas);

				if(pasajero == NULL)
				{
					printf("Pasajero no encontrado\n");
				}
				else
				{

					system("clear");
					printf("\n--------------------------------\n");
					printf("      BAJA   DE   PASAJERO       \n");
					printf("-------------------------------- \n\n");

					mostrarPasajero(pasajero);

					printf("\nPor favor confirmar la baja (s): ");
					fpurge(stdin);
					scanf("%c", &confirmacion);

					if(confirmacion == 's')
					{
						index = ll_indexOf(pArrayListPassenger, pasajero);
						ll_remove(pArrayListPassenger, index);
						system("clear");
						printf("\n->->-> Baja exitosa <-<-<-\n\n");
						retorno = 1;
					}
					else
					{
						system("clear");
						printf("\n->->-> Baja cancelada <-<-<-\n\n");

					}
				}
		   }
		   else
		   {
				system("clear");
				printf("\n\nRevise el dato ingresado y vuelva a intentar\n.");
		   }
		}
	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	if(pArrayListPassenger != NULL)
	{
		if(ll_len(pArrayListPassenger))
		{
			printf("\n LISTADO DE PASAJEROS      \n");
			printf("--------------------------------------------------------------------------------------------------------------\n");
			printf("  ID  Nombre             Apellido                 Precio         C??digo        Tipo             Estado     \n");
			printf("--------------------------------------------------------------------------------------------------------------\n");

			for(int i=0; i < ll_len(pArrayListPassenger); i++)
			{
				mostrarPasajeroFila((Passenger*)ll_get(pArrayListPassenger, i));
				retorno = 1;
			}
		}
		else
		{
			system("clear");
			printf("\nNo hay pasajeros en el sistema\n");
		}
	}
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int criterio;

	if(pArrayListPassenger != NULL)
	{
		if(ll_len(pArrayListPassenger) > 1)
		{
			switch(menuOrdenar()){

					case 1:

						printf("Criterios:\n\nASCENDENTE: 1\nDESCENDENTE: 0\n\n");
						if(get_int("Criterio: ", "**Dato Incorrecto**\n", 0, 1, &criterio))
						{
							ll_sort(pArrayListPassenger, passengerSortById, criterio);
						}
						break;

					case 2:

						printf("Criterios:\n\nASCENDENTE: 1\nDESCENDENTE: 0\n\n");
						if(get_int("Criterio: ", "**Dato Incorrecto**\n", 0, 1, &criterio))
						{
							ll_sort(pArrayListPassenger, passengerSortByApellido, criterio);
						}
						break;

					case 3:

						printf("Criterios:\n\nASCENDENTE: 1\nDESCENDENTE: 0\n\n");
						if(get_int("Criterio: ", "**Dato Incorrecto**\n", 0, 1, &criterio))
						{
							ll_sort(pArrayListPassenger, passengerSortByTipo, criterio);
							ll_sort(pArrayListPassenger, passengerSortByCodigo, criterio);
						}
						break;
					case 4:

						printf("Criterios:\n\nASCENDENTE: 1\nDESCENDENTE: 0\n\n");
						if(get_int("Criterio: ", "**Dato Incorrecto**\n", 0, 1, &criterio))
						{
							ll_sort(pArrayListPassenger, passengerSortByTipo, criterio);
							ll_sort(pArrayListPassenger, passengerSortByCodigo, criterio);
						}
						break;

			}
		}
		else
		{
			system("clear");
			printf("\nNo hay suficientes Pasajeros ingresados en sistema para la acci??n seleccionado.\n");
		}


	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	if( path != NULL && pArrayListPassenger != NULL)
	{
		FILE* file = fopen(path, "w");

		if(file == NULL)
		{
			perror("No se pudo conseguir memoria\n");
		}
		else if(passengerToText(file, pArrayListPassenger))
		{
			retorno = 1;
			system("clear");
			printf("\n Archivo de texto guardado con ??xito\n");

		}

		fclose(file);
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		//printf("CONTROLLER A BINARIO 0\n");

		FILE* file = fopen(path, "wb");

		//printf("CONTROLLER A BINARIO 1\n");

		if(file == NULL)
		{
			perror("No se pudo conseguir memoria\n");
		}
		else
		{
			if(passengerToBinary(file, pArrayListPassenger))
			{
				retorno = 1;
				system("clear");
				printf("\n Archivo de binario guardado con ??xito.\n");
			}
		}

		fclose(file);
	}
    return retorno;
}

int controller_saveNextId(char* path, int* nextId)
{
	int retorno = 0;

	if(path != NULL && nextId != NULL)
	{
		FILE* pFile = fopen(path, "wb");
		if(pFile != NULL)
		{
			if(nextIdToBinary(pFile, nextId))
			{
				printf("Actualizaci??n exitosa de IDs\n");
			}
		}
		fclose(pFile);

	}
	return retorno;
}

int controller_backup(LinkedList* listado)
{
	int retorno = 0;
	char path[25];
	char completo = 's';
	int FirstId;
	int LastId;

	if(listado != NULL)
	{
		printf("\n------------\n");
		printf("  BACKUP\n");
		printf("------------\n\n");

		cargaString(path, 25, "Ingrese la ruta y nombre de archivo de backup: ", "Dato incorrecto\n");

		FILE* fbackup = fopen(path, "wb");

		if(fbackup == NULL)
		{
			printf("No se pudo crear el archivo\n");
		}
		else
		{
			getCharacter("Desea copiar el listado completo? (s/n): ", "Dato incorrecto", &completo);

			if(completo != 's')
			{
				printf("A continuaci??n, ingrese los IDs de INICIO y CORTE del listado");

			}

		}





		retorno = 1;
	}
	return retorno;
}

