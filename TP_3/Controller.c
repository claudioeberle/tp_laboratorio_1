#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "input.h"
#include "abm_passenger.h"


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

			system("clear");
			printf("\n Se agregaron %d pasajeros al Sistema\n", ll_len(pArrayListPassenger));

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
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param pIndex int*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char confirmacion;


	Passenger* newPassenger = Passenger_new();

	if(newPassenger == NULL)
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

			if(ll_len(pArrayListPassenger) == 0)
			{
				newPassenger->id = 1;
			}
			else
			{
				proximoId(pArrayListPassenger, &newPassenger->id);
			}

			if( cargaString (newPassenger->nombre, 50, "\nNombre: ", "Dato Incorrecto. \n") &&
				cargaString (newPassenger->apellido, 50, "\nApellido: ", "Dato Incorrecto. \n") &&
				cargarPrecio(&newPassenger->precio) &&
				cargarCodigoVuelo(newPassenger->codigoVuelo, 10) &&
				cargarTipoPasajero(&newPassenger->tipoPasajero) &&
				cargarEstadoVuelo(&newPassenger->estadoVuelo))
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
				{	system("clear");
					printf("Error en la carga.-\n\n");
					printf("\n********************\n");
					printf("\n  CARGA CANCELADA \n\n");
					printf("********************\n");
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

	if(pArrayListPassenger != NULL)
	{
		system("clear");
		printf("\n--------------------------------\n");
		printf("   MODIFICACIÓN  DE  PASAJERO      \n");
		printf("-------------------------------- \n");

		if(controller_ListPassenger(pArrayListPassenger))
		{

			if(get_int("\nElija el ID del pasajero que quiere modificar: ", "Dato incorrecto", 1, ll_len(pArrayListPassenger), &id))
			{

				do{

					pasajero = buscarPasajeroPorId(pArrayListPassenger, id);

					/*
					 * No logré descifrar por qué solo me permite encontrar pasajeros hasta el id 93
					 * del 94 en adelante se pincha el programa
					 * pero si busco ese pasajero por indice con el ll_get me lo trae y muestra sin problemas
					 */

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
										getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											strncpy(pasajero->nombre, nombre, 50);
											system("clear");
											printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");

										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
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
										getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);
										if(confirmacion == 's'){

											strncpy(pasajero->apellido, apellido, 50);
											system("clear");
											printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
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
										getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											pasajero->precio = precio;
											system("clear");
											printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
										}
									}
									break;

								case 4:

									system("clear");
									mostrarPasajero(pasajero);
									printf("-------------------------------- \n\n");
									if(get_code("\nNuevo código: ", "Dato incorrecto\n", codigoVuelo, 10) == 1){
										printf("\n---------------\n");
										printf("Código anterior: %s\n", pasajero->codigoVuelo);
										printf("Código nuevo: %s\n", codigoVuelo);
										getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											strncpy(pasajero->codigoVuelo, codigoVuelo, 10);
											system("clear");
											printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
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

										printf("Categoría anterior: %s\n", descTipo);

										printf("Categoría nueva: %s\n", descTipoNuevo);

										getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

										if(confirmacion == 's'){

											pasajero->tipoPasajero = tipoPasajero;
											system("clear");
											printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
										}
										else{
											system("clear");
											printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
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


	if(pArrayListPassenger != NULL)
	{
		system("clear");
		printf("\n--------------------------------\n");
		printf("      BAJA   DE   PASAJERO       \n");
		printf("-------------------------------- \n");

		if(controller_ListPassenger(pArrayListPassenger) &&
		   get_int("\nElija el ID del pasajero que quiere dar de baja: ", "Dato incorrecto", 1, 10000, &pasId))
		{
			pasajero = buscarPasajeroPorId(pArrayListPassenger, pasId);

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
	int flag = 1;
	//int cant = 0;

	//printf("LISTADO 1\n");
	if(pArrayListPassenger != NULL)
	{

		printf("\n LISTADO DE PASAJEROS      \n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf("  ID       Nombre              Apellido              Precio          Código          Tipo           Estado     \n");
		printf("--------------------------------------------------------------------------------------------------------------\n");

		//printf("LISTADO 2\n");

		if(ll_len(pArrayListPassenger))
		{
			//printf("LISTADO 3\n");

			for(int i=0; i < ll_len(pArrayListPassenger); i++)
			{
				mostrarPasajeroFila((Passenger*)ll_get(pArrayListPassenger, i));
				//cant++;
				//printf("LISTADO pasajero %d\n", cant);
				flag = 0;
				retorno = 1;
			}
		}
		else
		{
			printf("No hay pasajeros en el sistema\n");
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
    return 1;
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

	FILE* file = fopen(path, "w");

	if(file == NULL)
	{
		perror("No se pudo conseguir memoria\n");
	}
	else
	{

		retorno = 1;

		system("clear");
		printf("\n Se agregaron %d pasajeros al Sistema\n", ll_len(pArrayListPassenger));

	}

	fclose(file);

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
    return 1;
}
