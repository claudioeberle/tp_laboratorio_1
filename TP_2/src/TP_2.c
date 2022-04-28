#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}ePasajeros;

void bienvenida (void);
int menu(void);
int altaPasajero (void);
int modificarPasajero(void);
int bajaPasajero(void);
int informar(void);
int salir(char*);
void despedida (void);


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int main() {

	setbuf(stdout, NULL);

	char salida = 'n';


	bienvenida();
	do{

			switch (menu()){

				case 1:

					altaPasajero ();
					break;

				case 2:

					modificarPasajero();
					break;

				case 3:

					bajaPasajero();
					break;

				case 4:

					informar();
					break;

				case 5:

					salir(&salida);
					break;

				}


		}while(salida != 's');


	return 0;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menu(void){

	int opcion;
	int check;

	do{

		printf("\n-------------------------------\n");
		printf(" Sistema de Carga de Pasajeros \n");
		printf("------------------------------- \n\n");
		printf("1. ALTA\n\n");
		printf("2. MODIFICAR\n\n");
		printf("3. BAJA\n\n");
		printf("4. INFORMES\n\n");
		printf("5. SALIR\n\n");

		printf("Elija una opción: ");
		fpurge(stdin);
		check = scanf("%d", &opcion);
		printf("\n\n");


		if(opcion <1 || opcion >5){

			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
		}


		}while(check == 0 && (opcion<1 || opcion>5));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int altaPasajero (void){

	int todoOK = 0;


	return todoOK;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int modificarPasajero(void){

	int todoOK = 0;


	return todoOK;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bajaPasajero(void){

	int todoOK = 0;


	return todoOK;
}


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int informar(void){

	int todoOK = 0;


	return todoOK;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int salir(char* var){

	int todoOK = 0;

	if(var != NULL){

		printf("Confirmar salida.\n");
		printf("Ingrese 's' para salir o 'n' para quedarse: ");
		fpurge(stdin);
		scanf("%c", var);

		if(!isalpha(*var) || (*var != 's' && *var != 'n')){

			do{

				printf("Opción inválida.\n");
				printf("Ingrese 's' para salir o 'n' para seguir operando: ");
				fpurge(stdin);
				scanf("%c", var);

			}while(!isalpha(*var) || (*var != 's' && *var != 'n'));

		}

		if(*var == 's'){

			despedida();
		}

		todoOK = 1;
	}
	else{

		printf("*ERROR* - Reinicie e intente nuevamente.");
	}


	return todoOK;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void bienvenida (){

	printf("\n''''''''''''''''''''''''''''''' \n");
	printf("    Bienvenido  a SISPAS®        \n");
	printf("\n''''''''''''''''''''''''''''''' \n");

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void despedida (){

	printf("\n\nGracias por utilizar SISPAS®. \n\n");
	printf("¡Hasta Luego!\n\n");

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


