
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "empleado.h"
#include "ioput.h"
#include "controller.h"


int main(void)
{
	setbuf(stdout, NULL);
	/*
	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort */

	/*
	 *
	 *Para la app se utilizaron las funciones:
	 *
	 * ll_newLinkedList
	 * ll_add
	 * ll_remove
	 * ll_len
	 * ll_get
	 * ll_clear
	 * ll_deleteLinkedLink
	 * ll_sort
	 * ll_push
	 * ll_sublist
	 * ll_clone
	 * ll_indexOf
	 *
	 *

	LinkedList* listadoEmpleados = ll_newLinkedList();

	if(listadoEmpleados == NULL)
	{
		perror("No se pudo iniciar el programa correctamente: ");
		exit(1);
	}

	char salida = 'n';
	int nextId = 1025;
	controller_loadIdFromBinary("nextId.bin", &nextId);
	controller_loadFromBinary("empleados.bin", listadoEmpleados);

	//altaForzadaEmpleados(listadoEmpleados, 25);

	do{

		switch(menu())
		{
			case 1:
				controller_addEmpleado(listadoEmpleados, &nextId);
				break;

			case 2:
				controller_editEmpleado(listadoEmpleados);
				break;

			case 3:
				controller_removeEmpleado(listadoEmpleados);
				break;

			case 4:
				controller_sortEmpleado(listadoEmpleados);
				break;

			case 5:
				controller_ListEmpleado(listadoEmpleados);
				break;

			case 6:
				controller_backup(listadoEmpleados);
				break;

			case 7:
				ll_sort(listadoEmpleados, empleadoSortById, 1);
				controller_saveAsBinary("empleados.bin", listadoEmpleados);
				controller_saveNextId("nextId.bin", &nextId);
				ll_deleteLinkedList(listadoEmpleados);
				salida = 's';
				break;
		}

	}while(salida != 's');
	*/

	printf("\n\n*************************************************************************************************\n");
		printf("   TESTEO DE FUNCIONES DE LINKED LIST");
		printf("\n*************************************************************************************************\n\n");
		LinkedList* listadoEmpleados = NULL;

		listadoEmpleados = ll_newLinkedList(); //utilizo el ll_newLinkedList para alta de una nueva linked list

		if(listadoEmpleados == NULL)
		{
			printf("\nNo se ha obtenido memoria\n");
			exit(1);
		}
		else
		{
			printf("\n\n*************************************************************************************************\n");
			printf("Dí de alta la Linked List \"listadoEmpleados\" \nUtilizando la función ll_newLinkedList");
			printf("\n*************************************************************************************************\n\n");

		}

		if(!altaForzadaEmpleados(listadoEmpleados, 25))
		{
			printf("\n\n*************************************************************************************************\n");
			printf("No se ha podido dar de alta los usuarios");
			printf("\n*************************************************************************************************\n\n");
		}
		else
		{
			printf("\n\n*************************************************************************************************\n");
			printf("Forcé el alta de 25 usuarios\nUtilizando la función ll_add\nLa cual a su vez utiliza la funcion ll_addNode");
			printf("\n*************************************************************************************************\n\n");
		}

		printf("\n\n*************************************************************************************************\n");
		printf("Listo todos los usuario de listadoEmpleados utilizando ll_get y ll_len");
		printf("\n*************************************************************************************************\n\n");

		listarEmpleados(listadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("declaro un nuevo puntero a LinkedList \"copiaListadoEmpleados\"");
		printf("\n*************************************************************************************************\n\n");

		LinkedList* copiaListadoEmpleados = NULL;

		printf("\n\n*************************************************************************************************\n");
		printf("Clono la linkedList listadoEmpleados y asigno la copia a copiaListadoEmpleados \ncon ll_clone (Esta utiliza ll_sublist)");
		printf("\n*************************************************************************************************\n\n");

		copiaListadoEmpleados = ll_clone(listadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("Me aseguro que ambas listas sean iguales con ll_containsAll");
		printf("\n*************************************************************************************************\n\n");

		if(ll_containsAll(listadoEmpleados, copiaListadoEmpleados))
		{
			printf("\nTodos los empleados de copiaListaEmpleados están en listadoEmpleados\n\n");
		}
		else
		{
			printf("Hay empleados en copiaListaEmpleados que no estan en listadoEmpleados\n\n");
		}

		printf("\n\n*************************************************************************************************\n");
		printf("Elijo dar de baja el usuario con id 1020 de la copiaListaEmpleados\n");
		printf("busco el usuario con la funcion buscarEmpleadoPorId\n(esta utiliza ll_get y ll_len)\n");
		printf("Se lo paso a ll_indexOf\n");
		printf("Y el indice se lo paso a ll_pop\n(esta utiliza ll_remove para quitarlo de la lista)\ny me devuelve la direccion del usuario eliminado\n");
		printf("La direccion se la paso a mostrarEmpleadoP para mostrar el usuario que elimino");
		printf("\n*************************************************************************************************\n\n");
		printf("\nEmpleado eliminado:\n\n");

		mostrarEmpleado(ll_pop(copiaListadoEmpleados, ll_indexOf(copiaListadoEmpleados, getEmpleadoById(copiaListadoEmpleados, 1020))));

		printf("\n\n*************************************************************************************************\n");
		printf("Vuelvo a listar los usuarios de copiaListaEmpleados sin el usuario 1020");
		printf("\n*************************************************************************************************\n\n");

		listarEmpleados(copiaListadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("Listo los usuarios de listaEmpleados que SÍ debería tener el empleado 1020");
		printf("\n*************************************************************************************************\n\n");

		listarEmpleados(listadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("Ahora voy a comparar listadoEmpleados con copiaListadoEmpleados con ll_containsAll\n");
		printf("Lo esperable es que me diga que listadoEmpleados no está contenida en copiaListadoEmpleados");
		printf("\n*************************************************************************************************\n\n");

		if(ll_containsAll(copiaListadoEmpleados, listadoEmpleados))
		{
			printf("\nTodos los empleados de listaEmpleados están en copiaListaEmpleados\n");
		}
		else
		{
			printf("Hay empleados en listaEmpleados que no estan en copiaListaEmpleados\n");
		}

		printf("\n\n*************************************************************************************************\n");
		printf("Voy a consultar la direccion de memoria del empleado con id 1020 de listadoEmpleados\n");
		printf("Y luego voy a consultar con ll_contains si ese elemento está en copiaListadoEmpleados");
		printf("\n*************************************************************************************************\n\n");

		if(ll_contains(copiaListadoEmpleados, getEmpleadoById(listadoEmpleados, 1020)))
		{
			printf("El empleado con ID 1020 se encuentra en la lista copiaListadoEmpleados\n");
		}
		else
		{
			printf("El empleado con ID 1020 NO se encuentra en la lista copiaListadoEmpleados\n");
		}

		printf("\n\n*************************************************************************************************\n");
		printf("Voy a agregar con ll_push el empleado de ID 1020 en copiaListadoEmpleados");
		printf("\n*************************************************************************************************\n\n");

		ll_push(copiaListadoEmpleados, ll_indexOf(listadoEmpleados, getEmpleadoById(listadoEmpleados, 1020)), getEmpleadoById(listadoEmpleados, 1020));

		printf("\n\n*************************************************************************************************\n");
		printf("Listo los usuarios de copiaListaEmpleados, que ahora SÍ debería tener el empleado 1020");
		printf("\n*************************************************************************************************\n\n");

		listarEmpleados(copiaListadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("Ahora voy a eliminar todos los elementos en copiaListadoEmpleados con ll_clear");
		printf("\n*************************************************************************************************\n\n");

		ll_clear(copiaListadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("con la funcion ll_isEmpty chequeo que haya quedado vacía");
		printf("\n*************************************************************************************************\n\n");

		if(ll_isEmpty(copiaListadoEmpleados))
		{
			printf("La lista \"copiaListadoEmpleados\" está vacía\n");
		}
		else
		{
			printf("La lista \"copiaListadoEmpleados\" NO está vacía\n");
		}

		printf("\n\n*************************************************************************************************\n");
		printf("Voy a pisar la primera posicion de listadoEmpleados con una nueva empleada Susana Gimenez");
		printf("\n*************************************************************************************************\n\n");

		printf("Empleada actualmente en primera posicion: \n\n");

		mostrarEmpleado(ll_get(listadoEmpleados, 0));

		ll_set(listadoEmpleados, 0, new_empleadoParam(1000, "Susana", "Gimenez", 'f', 123000));

		printf("\n\n*************************************************************************************************\n");
		printf("muestro listadoEmpleados y en la primera posicion debería estar la nueva empleada");
		printf("\n*************************************************************************************************\n\n");

		listarEmpleados(listadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("Ahora voy a ordenar a los empleados por Apellido ascendente con ll_sort + empleadoSortByApellido");
		printf("\n*************************************************************************************************\n\n");

		ll_sort(listadoEmpleados, empleadoSortByApellido, 1);

		listarEmpleados(listadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("Ahora voy a ordenar a los empleados por Sueldo descendente con ll_sort + empleadoSortBySueldo");
		printf("\n*************************************************************************************************\n\n");

		ll_sort(listadoEmpleados, empleadoSortBySueldo, 0);

		listarEmpleados(listadoEmpleados);

		printf("\n\n*************************************************************************************************\n");
		printf("Finalmente elimino las dos LinkedList con ll_deleteLinkedList");
		printf("\n*************************************************************************************************\n\n");

		ll_deleteLinkedList(copiaListadoEmpleados);
		ll_deleteLinkedList(listadoEmpleados);

    return 0;
}

