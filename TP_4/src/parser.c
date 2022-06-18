#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include"parser.h"
#include"LinkedList.h"

int parser_empleadoFromBinary(FILE* pFile , LinkedList* listadoEmpleados)
{
	int retorno = 0;
	int total = 0;

	eEmpleado* auxEmp = NULL;
	int cant = 0;

	if(pFile != NULL && listadoEmpleados != NULL)
	{

		while(!feof(pFile))
		{
			auxEmp = new_empleado();

			if(auxEmp == NULL)
			{
				printf("No se consiguió memoria\n");
			}
			else
			{
				cant = fread(auxEmp, sizeof(eEmpleado), 1, pFile);

				if(cant < 1)
				{
					break;
				}

				ll_add(listadoEmpleados, auxEmp);
				total++;
				retorno = 1;
			}
		}
	}
	system("clear");
	//printf("\n Se agregaron %d pasajeros al Sistema.\n", total);
    return retorno;
}

int empleadoToBinary(FILE* pFile , LinkedList* listadoEmpleados)
{
	int retorno = 0;
	eEmpleado* auxEmp = NULL;

	if(pFile != NULL && listadoEmpleados != NULL)
	{

		for(int i = 0; i < ll_len(listadoEmpleados); i++)
		{

			auxEmp = (eEmpleado*)ll_get(listadoEmpleados, i);

			fwrite(auxEmp, sizeof(eEmpleado), 1, pFile);

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
