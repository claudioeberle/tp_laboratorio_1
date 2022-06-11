#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "ioput.h"
#include "parser.h"



int main()
{
	setbuf(stdout, NULL);

	char option = 'n';

	int nextId = 0;

	int flagReadTxt = 0;
	int flagReadBin = 0;

	int flagCambios = 1;



    LinkedList* listaPasajeros = ll_newLinkedList();

    if(listaPasajeros == NULL)
    {
    	printf("No se pudo conseguir memoria.\n");
    	exit(1);
    }

    if(!controller_loadIdFromBinary("/Users/mistereberle/eclipse-workspace-GENERAL/TP_3/nextId.bin", &nextId))
    {
    	exit(1);
    }

    do{


        switch(menu())
        {
            case 1:

            	if(!controller_loadFromText("/Users/mistereberle/eclipse-workspace-GENERAL/TP_3/data.csv",listaPasajeros))
				{
					system("clear");
					printf("\n\nHubo un error en la lectura del archivo\n");
				}
				else
				{
					flagReadTxt = 1;
					flagCambios = 1;
				}
                break;

            case 2:

				if(!controller_loadFromBinary("/Users/mistereberle/eclipse-workspace-GENERAL/TP_3/data.bin" , listaPasajeros))
				{
					system("clear");
					printf("\n\nHubo un error en la lectura del archivo\n");
				}
				else
				{
					flagReadBin = 1;
					flagCambios = 1;
				}
				break;

            case 3:

            	flagCambios = 1;

            	controller_addPassenger(listaPasajeros, &nextId);
            	break;

            case 4:

            	flagCambios = 1;

            	controller_editPassenger(listaPasajeros);
            	break;

            case 5:

            	flagCambios = 1;

            	controller_removePassenger(listaPasajeros);
            	break;

            case 6:

            	flagCambios = 1;

            	controller_ListPassenger(listaPasajeros);
            	break;

            case 7:

            	flagCambios = 1;

            	controller_sortPassenger(listaPasajeros);
            	break;

            case 8:

            	flagCambios = 0;

            	controller_saveAsText("/Users/mistereberle/eclipse-workspace-GENERAL/TP_3/data.csv", listaPasajeros);
            	break;

            case 9:

            	flagCambios = 0;

            	controller_saveAsBinary("/Users/mistereberle/eclipse-workspace-GENERAL/TP_3/data.bin", listaPasajeros);
            	break;

            case 10:

            	if(flagCambios)
            	{
            		system("clear");
            		printf("Antes de salir debe guardar los cambios efectuados en un archivo.\n");
            	}
            	else
            	{
            		salir(&option);

            		if(option == 's')
            		{
            			controller_saveNextId("/Users/mistereberle/eclipse-workspace-GENERAL/TP_3/nextId.bin", &nextId);

            		}
            	}

            	break;
        }

    }while(option != 's');
    return 0;
}
