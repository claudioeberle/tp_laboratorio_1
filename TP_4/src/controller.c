#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "empleado.h"
#include "ioput.h"


int controller_loadFromBinary(char* path , LinkedList* listadoEmpleados)
{
	int retorno = 0;

	if(path != NULL && listadoEmpleados != NULL)
	{
		FILE* file =fopen(path, "rb");

		if(file == NULL)
		{
			system("clear");
			perror("ERROR");
		}
		else
		{
			parser_empleadoFromBinary(file, listadoEmpleados);
			retorno = 1;
		}

		fclose(file);

	}
    return retorno;
}

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
				printf("Actualización exitosa de IDs\n");
			}
		}
		fclose(pFile);

	}
	return retorno;
}

int controller_addEmpleado(LinkedList* listadoEmpleados, int* nextId)
{
	int retorno = 0;
	char confirma;
	int index;

	int id;
	char nombre[20];
	char apellido[20];
	char sexo;
	float sueldo;

	eEmpleado* nuevoEmp = NULL;

	char altaCancelada[30] = "\nALTA CANCELADA\n";

	if(listadoEmpleados != NULL && nextId != NULL)
	{
		printf("ALTA EMPLEADO\n");
		printf("--------------\n\n");

		id = *nextId;

		printf("ID: %d\n", id);

		if(cargaString(nombre, 20, "Ingrese el nombre: ", "Dato incorrecto\n"))
		{
			if(cargaString(apellido, 20, "Ingrese apellido: ", "Dato incorrecto\n"))
			{
				fpurge(stdin);
				if(getCharacter("Ingrese sexo: ", "Dato Incorrecto\n", &sexo) && (sexo == 'm' || sexo == 'f'))
				{
					if(get_float("Ingrese Sueldo: ", "Dato incorrecto\n", 1, 250000, &sueldo))
					{
						printf("SUELDO: %.2f\n", sueldo);
						system("clear");
						printf("\n--------------\n");
						printf("Nuevo Empleado\n");
						printf("--------------\n\n");
						printf("ID: %d\n", id);
						printf("NOMBRE: %s\n", nombre);
						printf("APELLIDO: %s\n", apellido);
						printf("SEXO: %c\n", sexo);
						printf("SUELDO: %.2f\n", sueldo);

						fpurge(stdin);
						getCharacter("\nConfirma la carga? (s): ", "Dato incorrecto\n", &confirma);

						if(confirma == 's')
						{
							nuevoEmp = new_empleadoParam(id, nombre, apellido, sexo, sueldo);

							if(nuevoEmp != NULL)
							{
								printf("Si desea definir el indice donde guardar el empleado escríbalo a continuación\nde lo contrario, escriba -1\n");
								get_int("INDICE: ", "Dato incorrecto\n", -1, 10000, &index);

								if(index == -1)
								{

									ll_add(listadoEmpleados, nuevoEmp);
									retorno = 1;
									system("clear");
									printf("Alta Exitosa\n");
								}
								else
								{
									ll_push(listadoEmpleados, index, nuevoEmp);
									retorno = 1;
									system("clear");
									printf("Alta Exitosa\n");

								}

								(*nextId)++;

							}
						}
					}
				}
			}
		}
		if(!retorno)
		{
			printf("%s", altaCancelada);
		}
	}
	return retorno;
}

int controller_editEmpleado(LinkedList* listadoEmpleados)
{
	int retorno = 0;
	int opcion;
	int auxId;
	char confirmacion = 'n';

	eEmpleado auxEmp;

	if(listadoEmpleados != NULL)
	{
		listarEmpleados(listadoEmpleados);

		if(get_int("Elija el id del empleado a modificar: ", "Dato incorrecto\n", 1000, 10000, &auxId) &&
			getEmpleadoById(listadoEmpleados, auxId))
		{
			eEmpleado* empleado = getEmpleadoById(listadoEmpleados, auxId);

			do
			{
				mostrarEmpleado(empleado);
				opcion = menuModificar();

				switch(opcion){

					case 1:
						system("clear");
						mostrarEmpleado(empleado);
						printf("-----------------------\n");
						if(cargaString(auxEmp.nombre, 20, "Nuevo nombre: ", "Dato Incorrecto\n"))
						{
							printf("\n---------------\n");
							printf("Nombre anterior: %s\n", empleado->nombre);
							printf("Nombre nuevo: %s\n", auxEmp.nombre);
							getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

							if(confirmacion == 's'){

								strncpy(empleado->nombre, auxEmp.nombre, 20);
								system("clear");
								printf("\n\nMODIFICACIÓN EXITOSA\n");

							}
							else{
								system("clear");
								printf("\nMODIFICACIÓN CANCELADA\n");
							}
						}
						break;
					case 2:
						system("clear");
						mostrarEmpleado(empleado);
						printf("-----------------------\n");
						if(cargaString(auxEmp.apellido, 20, "Nuevo apellido: ", "Dato Incorrecto\n"))
						{
							printf("\n---------------\n");
							printf("Apellido anterior: %s\n", empleado->apellido);
							printf("Apellido nuevo: %s\n", auxEmp.apellido);
							getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

							if(confirmacion == 's'){

								strncpy(empleado->apellido, auxEmp.apellido, 20);
								system("clear");
								printf("\n\nMODIFICACIÓN EXITOSA\n");

							}
							else{
								system("clear");
								printf("\nMODIFICACIÓN CANCELADA\n");
							}

						}
						break;
					case 3:
						system("clear");
						mostrarEmpleado(empleado);
						printf("-----------------------\n");
						if(getCharacter("Nuevo sexo: ", "Dato incorrecto\n", &auxEmp.sexo))
						{
							printf("\n---------------\n");
							printf("Sexo anterior: %c\n", empleado->sexo);
							printf("Sexo nuevo: %c\n", auxEmp.sexo);
							getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

							if(confirmacion == 's'){

								empleado->sexo = auxEmp.sexo;
								system("clear");
								printf("\n\nMODIFICACIÓN EXITOSA\n");

							}
							else{
								system("clear");
								printf("\nMODIFICACIÓN CANCELADA\n");
							}
						}
						break;
					case 4:
						system("clear");
						mostrarEmpleado(empleado);
						printf("-----------------------\n");
						if(get_float("Nuevo sueldo: ", "Dato incorrecto\n", 10000, 250000, &auxEmp.sueldo))
						{
							printf("\n---------------\n");
							printf("Sueldo anterior: %.2f\n", empleado->sueldo);
							printf("Sueldo nuevo: %.2f\n", auxEmp.sueldo);
							getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

							if(confirmacion == 's'){

								empleado->sueldo = auxEmp.sueldo;
								system("clear");
								printf("\n\nMODIFICACIÓN EXITOSA\n");

							}
							else{
								system("clear");
								printf("\nMODIFICACIÓN CANCELADA\n");
							}
						}
						break;

				}

			}while(opcion != 5);
		}
		else
		{
			printf("No hay ningun empleado con ese id\n");
		}
		retorno = 1;
	}
	return retorno;
}

int controller_removeEmpleado(LinkedList* listadoEmpleados)
{
	int retorno = 0;
	int auxId;
	char confirmacion;

	if(listadoEmpleados != NULL)
	{
		listarEmpleados(listadoEmpleados);

		if(get_int("Elija el id del empleado a modificar: ", "Dato incorrecto\n", 1000, 10000, &auxId) &&
			getEmpleadoById(listadoEmpleados, auxId))
		{
			eEmpleado* empleado = getEmpleadoById(listadoEmpleados, auxId);

			mostrarEmpleado(empleado);

			getCharacter("\nConfirmar baja (s): ", "Dato Incorrecto", &confirmacion);

			if(confirmacion == 's'){

				ll_remove(listadoEmpleados, auxId);
				retorno = 1;
				system("clear");
				printf("\n\nBaja Exitosa\n");

			}
			else{
				system("clear");
				printf("\nBaja Cancelada\n");
			}
		}
		else
		{
			printf("No hay ningun empleado con ese id\n");
		}
	}
	return retorno;
}

int controller_sortEmpleado(LinkedList* listadoEmpleados)
{
	int retorno = 0;
	int order;

	if(listadoEmpleados != NULL)
	{
		switch(menuOrdenar())
		{
			case 1:
				get_int("\nascendente 1\ndescendente 0\nElija criterio: ", "", 0, 1, &order);
				ll_sort(listadoEmpleados, empleadoSortByNombre, order);
				break;

			case 2:
				get_int("\nascendente 1\ndescendente 0\nElija criterio: ", "", 0, 1, &order);
				ll_sort(listadoEmpleados, empleadoSortByApellido, order);
				break;

			case 3:
				get_int("\nascendente 1\ndescendente 0\nElija criterio: ", "", 0, 1, &order);
				ll_sort(listadoEmpleados, empleadoSortBySexo, order);
				break;

			case 4:
				get_int("\nascendente 1\ndescendente 0\nElija criterio: ", "", 0, 1, &order);
				ll_sort(listadoEmpleados, empleadoSortBySueldo, order);
				break;

			case 5:
				get_int("\nascendente 1\ndescendente 0\nElija criterio: ", "", 0, 1, &order);
				ll_sort(listadoEmpleados, empleadoSortById, order);
				break;
		}
	}
	return retorno;
}

int controller_ListEmpleado(LinkedList* listadoEmpleados)
{
	int retorno = 0;
	if(listadoEmpleados != NULL)
	{
		listarEmpleados(listadoEmpleados);
	}
	return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* listado)
{
	int retorno = 0;

	if(path != NULL && listado != NULL)
	{

		FILE* file = fopen(path, "wb");

		if(file == NULL)
		{
			perror("No se pudo conseguir memoria\n");
		}
		else
		{
			if(empleadoToBinary(file, listado))
			{
				retorno = 1;
				system("clear");
				printf("\nArchivo binario guardado con éxito.\n");
			}
		}

		fclose(file);
	}
    return retorno;
}

int controller_backup(LinkedList* listado)
{
	int retorno = 0;
	char auxPath[25];
	char path[40] = "backup_";
	char completo = 's';
	int firstId;
	int lastId;
	int indexInicio;
	int indexCorte;
	LinkedList* listaAux = NULL;

	if(listado != NULL)
	{
		printf("\n------------\n");
		printf("  BACKUP\n");
		printf("------------\n\n");

		if(cargaPath(auxPath, 25, "Ingrese el nombre de archivo: ", "Dato incorrecto\n"))
		{
			strcat(path, auxPath);

			getCharacter("Desea copiar el listado completo? (s/n): ", "Dato incorrecto", &completo);

			if(completo != 's')
			{
				ll_sort(listado, empleadoSortById, 1);
				listarEmpleados(listado);

				printf("A continuación, ingrese los IDs de INICIO y CORTE del listado\n");
				get_int("Inicio: ", "Dato incorreto\n", 1000, 10000, &firstId);
				get_int("Corte: ", "Dato incorrecto\n", 1000, 10000, &lastId);

				indexInicio = ll_indexOf(listado, getEmpleadoById(listado, firstId));
				indexCorte = ll_indexOf(listado, getEmpleadoById(listado, lastId));

				listaAux = ll_subList(listado, indexInicio, indexCorte);

			}
			else
			{
				listaAux = ll_clone(listado);
			}

			if(listaAux == NULL)
			{
				perror("No se logró crear la nueva lista\n");
			}
			else
			{
				if(controller_saveAsBinary(path, listaAux))
				{
					printf("\nBackup creado con exito\n");
					retorno = 1;
				}
				else
				{
					perror("No se logró crear el archivo backup\n");
				}
			}
		}
	}
	return retorno;
}

int controller_buscarEmpleado(LinkedList* listado)
{
	int retorno = 0;
	int opcion = 6;
	char refinar;

	LinkedList* listadoAux = NULL;

	if (listado != NULL)
	{
		listadoAux = ll_clone(listado);

		if (listadoAux == NULL)
		{
			perror("Hubo un error. Vuelva a intentarlo\n");
		}
		else
		{
			printf("\n--------------------------------\n");
			printf("            BUSCAR             \n");
			printf("-------------------------------- \n\n");

			do
			{

				opcion = menuBusqueda();

				switch(opcion){

						case 1:

							busquedaPorId(listadoAux);
							opcion = 6;
							break;

						case 2:

							busquedaPorNombre(listadoAux);
							listarEmpleados(listadoAux);
							getCharacter("\n\nDesea refinar la búsqueda por otro campo? (s): ", "Dato incorrecto\n", &refinar);

							if(refinar != 's')
							{
								opcion = 6;
							}
							break;

						case 3:

							busquedaPorApellido(listadoAux);
							listarEmpleados(listadoAux);
							getCharacter("\n\nDesea refinar la búsqueda por otro campo? (s): ", "Dato incorrecto\n", &refinar);

							if(refinar != 's')
							{
								opcion = 6;
							}
							break;

						case 4:

							busquedaPorSexo(listadoAux);
							listarEmpleados(listadoAux);
							getCharacter("\n\nDesea refinar la búsqueda por otro campo? (s): ", "Dato incorrecto\n", &refinar);

							if(refinar != 's')
							{
								opcion = 6;
							}
							break;

						case 5:

							busquedaPorSueldo(listadoAux);
							listarEmpleados(listadoAux);
							getCharacter("\n\nDesea refinar la búsqueda por otro campo? (s): ", "Dato incorrecto\n", &refinar);

							if(refinar != 's')
							{
								opcion = 6;
							}
							break;

						case 6:

							ll_deleteLinkedList(listadoAux);
							break;
				}
			}while(opcion != 6);
		}
	}
	return retorno;
}
