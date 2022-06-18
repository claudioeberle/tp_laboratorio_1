#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "ioput.h"



/*/////////////////////////////////////////////////////////////////////////////*/

void mostrarEmpleado(eEmpleado* unEmpleado)
{
	printf("ID: %d\n", unEmpleado->id);
	printf("NOMBRE: %s\n", unEmpleado->nombre);
	printf("APELLIDO: %s\n", unEmpleado->apellido);
	printf("SEXO: %c\n", unEmpleado->sexo);
	printf("SUELDO: %.2f\n", unEmpleado->sueldo);

}

/*/////////////////////////////////////////////////////////////////////////////*/

void mostrarEmpleadoFila(eEmpleado* pEmpleado)
{
	if(pEmpleado != NULL)
	{
		printf("%4d   %-15s   %-15s   %c   %10.f\n", pEmpleado->id,
											 pEmpleado->nombre,
											 pEmpleado->apellido,
											 pEmpleado->sexo,
											 pEmpleado->sueldo);
	}
}

/*/////////////////////////////////////////////////////////////////////////////*/

int listarEmpleados(LinkedList* listado)
{
	int retorno = 0;
	if(listado != NULL)
	{
		printf("EMPLEADOS\n");
		printf("-------------------------------------------------------------\n");
		printf(" ID    NOMBRE           APELLIDO          SEXO      SUELDO\n");
		printf("-------------------------------------------------------------\n");

		for( int i = 0; i < ll_len(listado); i++)
		{
			mostrarEmpleadoFila(ll_get(listado, i));
		}
		printf("\n");
		retorno = 1;
	}
	return retorno;
}
/*/////////////////////////////////////////////////////////////////////////////*/

eEmpleado* new_empleado()
{
	eEmpleado* nuevoEmpleado = NULL;

	nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

	if(nuevoEmpleado != NULL)
	{
		nuevoEmpleado->id = 0;
		strcpy(nuevoEmpleado->nombre, "nn");
		strcpy(nuevoEmpleado->apellido, "nn");
		nuevoEmpleado->sexo = 'n';
		nuevoEmpleado ->sueldo = 0;
	}

	return nuevoEmpleado;
}

/*/////////////////////////////////////////////////////////////////////////////*/

eEmpleado* new_empleadoParam(int id, char* nombre, char* apellido, char sexo, float sueldo)
{

	eEmpleado* nuevoEmpleado = new_empleado();

	if( !(empleadoSetId(nuevoEmpleado, id) &&
		 empleadoSetNombre(nuevoEmpleado, nombre) &&
		 empleadoSetApellido(nuevoEmpleado, apellido) &&
		 empleadoSetSexo(nuevoEmpleado, sexo) &&
		 empleadoSetSueldo(nuevoEmpleado, sueldo)))
	{
		free(nuevoEmpleado);
		nuevoEmpleado = NULL;
	}

	return nuevoEmpleado;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSetId(eEmpleado* emp, int id)
{
	int retorno = 0;

	if(emp != NULL && id > 999)
	{
		emp->id =id;
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSetNombre(eEmpleado* emp, char* nombre)
{
	int retorno = 0;
	if(emp != NULL && nombre != NULL && strlen(nombre) < 20 && strlen(nombre) > 2)
	{
		strcpy(emp->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSetApellido(eEmpleado* emp, char* apellido)
{
	int retorno = 0;
	if(emp != NULL && apellido != NULL && strlen(apellido) < 20 && strlen(apellido) > 2)
	{
		strcpy(emp->apellido, apellido);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSetSexo(eEmpleado* emp, char sexo)
{
	int retorno = 0;

	if(emp != NULL && (sexo == 'f' || sexo == 'm'))
	{
		emp->sexo =sexo;
		retorno = 1;
	}

	return retorno;
}
/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSetSueldo(eEmpleado* emp, float sueldo)
{
	int retorno = 0;

	if(emp != NULL && sueldo > 0)
	{
		emp->sueldo =sueldo;
		retorno = 1;
	}

	return retorno;

}

/*/////////////////////////////////////////////////////////////////////////////*/

void EmpleadoDestroy(eEmpleado* emp)
{
	free(emp);
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoGetId(eEmpleado* emp, int* id)
{
	int retorno = 0;

	if(emp != NULL && id != NULL)
	{
		*id = emp->id;
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoGetNombre(eEmpleado* emp, char* nombre)
{
	int retorno = 0;
	if(emp != NULL && nombre != NULL)
	{
		strcpy(nombre, emp->nombre);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoGetApellido(eEmpleado* emp, char* apellido)
{
	int retorno = 0;
	if(emp != NULL && apellido != NULL)
	{
		strcpy(apellido, emp->apellido);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoGetNombreCompleto(eEmpleado* emp, char* nombreCompleto)
{
	int retorno = 0;
	if(emp != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto, emp->nombre);
		strcat(nombreCompleto, " ");
		strcat(nombreCompleto, emp->apellido);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoGetSexo(eEmpleado* emp, char* sexo)
{
	int retorno = 0;

	if(emp != NULL && sexo != NULL)
	{
		*sexo = emp->sexo;
		retorno = 1;
	}

	return retorno;
}
/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoGetSexoFull(eEmpleado* emp, char* sexo)
{
	int retorno = 0;

	if(emp != NULL && sexo != NULL)
	{
		if(emp->sexo == 'm')
		{
			strcpy(sexo, "Masculino");
		}
		else
		{
			strcpy(sexo, "Femenino");
		}
		retorno = 1;
	}

	return retorno;
}
/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoGetSueldo(eEmpleado* emp, float* sueldo)
{
	int retorno = 0;

	if(emp != NULL && sueldo != NULL)
	{
		*sueldo = emp->sueldo;
		retorno = 1;
	}

	return retorno;

}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSortBySueldo(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		eEmpleado* emp1 = (eEmpleado*)a;
		eEmpleado* emp2 = (eEmpleado*)b;

		if(emp1->sueldo == emp2->sueldo)
		{
			retorno = 0;
		}
		else if(emp1->sueldo > emp2->sueldo)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSortById(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		eEmpleado* emp1 = (eEmpleado*)a;
		eEmpleado* emp2 = (eEmpleado*)b;

		if(emp1->id == emp2->id)
		{
			retorno = 0;
		}
		else if(emp1->id > emp2->id)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/
int empleadoSortBySexo(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		eEmpleado* emp1 = (eEmpleado*)a;
		eEmpleado* emp2 = (eEmpleado*)b;

		if(emp1->sexo == emp2->sexo)
		{
			retorno = 0;
		}
		else if(emp1->sexo > emp2->sexo)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSortByNombre(void* a, void* b)
{
	int retorno = -1;

	if(a != NULL && b != NULL)
	{
		eEmpleado* emp1 = (eEmpleado*)a;
		eEmpleado* emp2 = (eEmpleado*)b;

		if(strcmp(emp1->nombre, emp2->nombre) == 0)
		{
			retorno = 0;
		}
		else if(strcmp(emp1->nombre, emp2->nombre) > 0)
		{
			retorno = 1;
		}

	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int empleadoSortByApellido(void* a, void* b)
{
	int retorno = -1;

	if(a != NULL && b != NULL)
	{
		eEmpleado* emp1 = (eEmpleado*)a;
		eEmpleado* emp2 = (eEmpleado*)b;

		if(strcmp(emp1->apellido, emp2->apellido) == 0)
		{
			retorno = 0;
		}
		else if(strcmp(emp1->apellido, emp2->apellido) > 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int altaForzadaEmpleados(LinkedList* listado, int cantidadEmpleados)
{
	int retorno = 0;

	if(listado != NULL && cantidadEmpleados > 0 && cantidadEmpleados <= 25)
	{
		eEmpleado listadoAux[25] =
		{

			{1000, "Julia", "Gallo", 'f', 89000},
			{1001, "Jimena", "Villa", 'f', 80000},
			{1002, "Jose", "Alarcon", 'm', 66000},
			{1003, "Patricia", "Gomez", 'f', 99000},
			{1004, "Andrea", "Rosalia", 'f', 59000},
			{1005, "Roberto", "Mansela",  'm', 70000},
			{1006, "Monica", "Guido",  'f', 77000},
			{1007, "Ariel", "Bermudez",  'm', 67000},
			{1008, "German", "Kraus",  'm', 120000},
			{1009, "Franco", "Jimenez", 'm', 60000},
			{1010, "Julian", "Gomez",  'm', 93000},
			{1011, "Fabiana", "Cantilo",  'f', 78000},
			{1012, "Hugo", "Moyano",  'm', 92000},
			{1013, "Sabrina", "Fernandez",  'f', 88000},
			{1014, "German", "Fernandez",  'm', 102000},
			{1015, "German", "Gomez",  'm', 77000},
			{1016, "Rodrigo", "Gomez",  'm', 71000},
			{1017, "Patricia", "Fernandez",  'f', 55000},
			{1018, "Florencia", "Fernandez",  'f', 50000},
			{1019, "Cristina", "Morena",  'f', 91000},
			{1020, "Franco Anibal", "Gimenez",  'm', 86000},
			{1021, "Tristan", "Mosser",  'm', 100000},
			{1022, "Julian", "Assange",  'm', 99000},
			{1023, "Romina", "Ricci",  'f', 98000},
			{1024, "Felicitas", "Wan",  'f', 89000}
		};

		for( int i = 0; i < cantidadEmpleados; i++)
		{

			eEmpleado* empleado = new_empleadoParam(listadoAux[i].id, listadoAux[i].nombre, listadoAux[i].apellido, listadoAux[i].sexo, listadoAux[i].sueldo);

			if(empleado != NULL)
			{
				ll_add(listado, empleado);
			}
		}
		retorno = 1;

	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

eEmpleado* getEmpleadoById(LinkedList* lista, int id)
{
	eEmpleado* auxEmp = NULL;
	int flag = 0;

	if(lista != NULL)
	{
		for( int i = 0; i < ll_len(lista); i++)
		{
			auxEmp = (eEmpleado*)ll_get(lista, i);

			if(auxEmp->id == id)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			auxEmp = NULL;
		}
	}
	return auxEmp;
}

/*/////////////////////////////////////////////////////////////////////////////*/


int busquedaPorId(LinkedList* listado)
{
	int retorno = 0;
	int id;
	eEmpleado* empleado = NULL;


	if(listado != NULL)
	{
		if(get_int("Ingrese el ID: ", "Dato incorrecto\n", 1000, 10000, &id))
		{
			empleado = getEmpleadoById(listado, id);

			if(empleado == NULL)
			{
				printf("No se encontró el empleado\n");
			}
			else
			{
				mostrarEmpleado(empleado);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/


int busquedaPorNombre(LinkedList* listadoAux)
{
	int retorno = 0;
	char nombre[20];

	if(listadoAux != NULL)
	{
		if(cargaString(nombre, 20, "Nombre de empleado: ", "Dato incorrecto\n"))
		{
			ll_sort(listadoAux, empleadoSortById, 1);
			filtrarNombre(listadoAux, nombre);

			retorno = 1;
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int filtrarNombre (LinkedList* listadoAux, char* nombre)
{
	int cant;
	int tam = cant = ll_len(listadoAux);

	eEmpleado* empleado = NULL;

	if(listadoAux != NULL && nombre != NULL)
	{
		for (int i = 0; i < tam ; i++)
		{
			empleado = ll_get(listadoAux, i);

			printf("%d\n", i);
			printf("%d\n", tam);
			printf("%d\n", cant);
			printf("%d\n", empleado->id);
			printf("%s\n", nombre);
			printf("%s\n", empleado->nombre);
			printf("%d\n\n", strcmp(empleado->nombre, nombre));
			listarEmpleados(listadoAux);

			if(strcmp(empleado->nombre, nombre) != 0)
			{
				ll_remove(listadoAux, i);
				cant--;
			}
		}
	}
	return cant;
}

/*/////////////////////////////////////////////////////////////////////////////*/


int busquedaPorApellido(LinkedList* listadoAux)
{
	int retorno = 0;
	char apellido[20];

	if(listadoAux != NULL)
	{
		if(cargaString(apellido, 20, "Apellido de empleado: ", "Dato incorrecto\n"))
		{
			filtrarNombre(listadoAux, apellido);
			retorno = 1;
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int filtrarApellido (LinkedList* listadoAux, char* apellido)
{
	int cant;
	int tam = cant = ll_len(listadoAux);

	eEmpleado* empleado = NULL;

	if(listadoAux != NULL && apellido != NULL)
	{
		for (int i = 0; i < tam ; i++)
		{
			empleado = ll_get(listadoAux, i);

			if(strcmp(empleado->apellido, apellido) != 0)
			{
				ll_remove(listadoAux, i);
				cant--;
			}
		}
	}
	return cant;
}

/*/////////////////////////////////////////////////////////////////////////////*/


int busquedaPorSexo(LinkedList* listadoAux)
{
	int retorno = 0;
	char sexo;

	if(listadoAux != NULL)
	{
		if(getCharacter("Sexo del empleado: ", "Dato incorrecto\n", &sexo))
		{
			filtrarSexo(listadoAux, sexo);
			retorno = 1;
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int filtrarSexo (LinkedList* listadoAux, char sexo)
{
	int cant;
	int tam = cant = ll_len(listadoAux);

	eEmpleado* empleado = NULL;

	if(listadoAux != NULL)
	{
		for (int i = 0; i < tam ; i++)
		{
			empleado = ll_get(listadoAux, i);

			if(empleado->sexo != sexo)
			{
				ll_remove(listadoAux, i);
				cant--;
			}
		}
	}
	return cant;
}

/*/////////////////////////////////////////////////////////////////////////////*/



int busquedaPorSueldo(LinkedList* listadoAux)
{
	int retorno = 0;
	float sueldo;

	if(listadoAux != NULL)
	{
		if(get_float("Sueldo del empleado: ", "Dato incorrecto\n", 0, 900000, &sueldo))
		{
			filtrarSueldo(listadoAux, sueldo);
			retorno = 1;
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int filtrarSueldo (LinkedList* listadoAux, float sueldo)
{
	int cant;
	int tam = cant = ll_len(listadoAux);

	eEmpleado* empleado = NULL;

	if(listadoAux != NULL)
	{
		for (int i = 0; i < tam ; i++)
		{
			empleado = ll_get(listadoAux, i);

			if(empleado->sueldo != sueldo)
			{
				ll_remove(listadoAux, i);
				cant--;
			}
		}
	}
	return cant;
}

/*/////////////////////////////////////////////////////////////////////////////*/
