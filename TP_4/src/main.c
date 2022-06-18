
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
	 */
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


    return 0;
}

