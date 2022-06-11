#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "ioput.h"
#include "parser.h"


/*
 * PROFES, SOLO QUIERO COMENTARLES QUE AL HACER LOS SORT DE LA OPCION 7
 * PARECE QUE SE CUELGA EL CODIGO PERO NO ES ASÍ
 * SOLO TARDA EN PROCESAR, QUIZÁS SEA SOLO MI COMPU
 * PERO LES AVISO POR LAS DUDAS XQ YO ESTUVE VOLVIENDOME LOCO INTENTANDO DESCIFRAR
 * POR QUÉ ROMPÍA HASTA QUE ME DI CUENTA DE QUE SI ESPERABA APROX 10/15 SEG
 * TERMINA DE ORDENAR Y VUELVE A LA VIDA SOLITO!!!
 */



int main()
{
	setbuf(stdout, NULL);

	char option = 'n';

	int nextId = 1001;

	int flagReadTxt = 0;
	int flagReadBin = 0;

	int flagCambios = 1;



    LinkedList* listaPasajeros = ll_newLinkedList();

    if(listaPasajeros == NULL)
    {
    	printf("No se pudo conseguir memoria.\n");
    	exit(1);
    }

    if(!controller_loadIdFromBinary("./nextId.bin", &nextId))
    {
    	exit(1);
    }

    system("clear");
    do{


        switch(menu())
        {
            case 1:
            	if(flagReadTxt || flagReadBin)
            	{
            		system("clear");
            		printf("Ya han sido cargados los pasajeros de archivo.\n");
            	}
            	else
            	{

					if(!controller_loadFromText("./data.csv",listaPasajeros))
					{
						system("clear");
						printf("\n\nHubo un error en la lectura del archivo\n");
					}
					else
					{
						flagReadTxt = 1;
						flagCambios = 1;
					}
            	}
                break;

            case 2:
            	if(flagReadTxt || flagReadBin)
				{
            		system("clear");
					printf("Ya han sido cargados los pasajeros de archivo.\n");
				}
				else
				{
					if(!controller_loadFromBinary("./data.bin" , listaPasajeros))
					{
						system("clear");
						printf("\n\nHubo un error en la lectura del archivo\n");
					}
					else
					{
						flagReadBin = 1;
						flagCambios = 1;
					}
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

            	controller_ListPassenger(listaPasajeros);
            	break;

            case 7:

            	controller_sortPassenger(listaPasajeros);
            	break;

            case 8:

            	flagCambios = 0;

            	controller_saveAsText("data.csv", listaPasajeros);
            	break;

            case 9:

            	flagCambios = 0;

            	controller_saveAsBinary("data.bin", listaPasajeros);
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
            			controller_saveNextId("nextId.bin", &nextId);
            			ll_deleteLinkedList(listaPasajeros);
            		}
            	}

            	break;
        }

    }while(option != 's');
    return 0;
}
