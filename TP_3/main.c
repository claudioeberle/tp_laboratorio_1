#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"
#include "parser.h"
#include "abm_passenger.h"


int main()
{
	setbuf(stdout, NULL);

	char option = 'n';

    LinkedList* listaPasajeros = ll_newLinkedList();

    //Passenger*  unPasajero;

    if(listaPasajeros == NULL)
    {
    	printf("No se pudo conseguir memoria.\n");
    	exit(1);
    }

    //FILE* pFile = fopen("data.csv", "r");

    //parser_PassengerFromText(pFile, listaPasajeros);




    do{

        switch(menu())
        {
            case 1:
                controller_loadFromText("/Users/mistereberle/desktop/workspace_1/tp3_mac/data.csv",listaPasajeros);
                break;

            case 2:
            	controller_loadFromBinary("data.bin" , listaPasajeros);
				break;

            case 3:
            	controller_addPassenger(listaPasajeros);
            	break;

            case 4:

            	controller_editPassenger(listaPasajeros);
            	break;

            case 5:
            	controller_removePassenger(listaPasajeros);
            	break;

            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;

            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;

            case 8:
            	controller_saveAsText("datos.csv", listaPasajeros);
            	break;

            case 9:
            	controller_saveAsBinary("datos.bin", listaPasajeros);
            	break;

            case 10:
            	salir(&option);
            	break;
        }

    }while(option != 's');
    return 0;
}

