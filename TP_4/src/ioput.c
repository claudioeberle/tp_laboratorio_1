#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ioput.h"

int menu()
{
	int opcion = 6;
	int check;

	do{

			printf("\n---------------------------------\n");
			printf(" SISTEMA DE GESTIÓN DE EMPLEADOS \n");
			printf("--------------------------------- \n\n");
			printf("1.  ALTA DE EMPLEADO\n\n");
			printf("2.  MODIFICAR EMPLEADO\n\n");
			printf("3.  BAJA DE EMPLEADO\n\n");
			printf("4.  ORDENAR EMPLEADOS\n\n");
			printf("5.  LISTAR EMPLEADOS\n\n");
			printf("6.  BACKUP\n\n");
			printf("7.  SALIR\n\n");

			printf("Elija una opción: ");
			fpurge(stdin);
			check = scanf("%d", &opcion);
			printf("\n\n");


			if(check != 1 || (opcion <1 && check == 1) || (opcion >7 && check == 1)){

				system("clear");
				printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
			}


		}while(check != 1 && (opcion <1 || opcion >7));
		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuModificar()
{
	int opcion = 5;
	int check;

	do{

			printf("\n-----------------------\n");
			printf(" MODIFICACION USUARIO \n");
			printf("-----------------------\n\n");
			printf("1.  NOMBRE\n\n");
			printf("2.  APELLIDO\n\n");
			printf("3.  SEXO\n\n");
			printf("4.  SUELDO\n\n");
			printf("5. SALIR\n\n");

			printf("Elija una opción: ");
			fpurge(stdin);
			check = scanf("%d", &opcion);
			printf("\n\n");


			if(check != 1 || (opcion <1 && check == 1) || (opcion >5 && check == 1)){

				system("clear");
				printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
			}


		}while(check != 1 && (opcion <1 || opcion >5));
		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargaString (char* string, int tam_string, char* mensaje, char* mensajeError){
	int retorno = 0;
	int reintentos = 3;
	int flag = 0;
	char aux[tam_string];

	if(string != NULL && mensaje != NULL && mensajeError != NULL && tam_string > 2){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(aux, tam_string, stdin);

			if(quitarEnter(aux, tam_string) && strlen(aux) > 2)
			{
				flag = 0;

				for(int i = 0; *(aux + i) != '\0'; i++)
				{

					if(i != 0 && *(aux + i) == ' '){

						continue;
					}

					if(!isalpha(*(aux + i)))
					{

						flag = 1;
						reintentos --;
						printf("%s", mensajeError);
						break;
					}
				}

				if(!flag){

					retorno = 1;
					capitalString (aux);
					strncpy(string, aux, tam_string);
					break;
				}
			}
			else
			{
				reintentos --;
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);

	}

	if (!reintentos){

		printf("\nNo se ha podido ingresar el dato.");
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargaPath (char* string, int tam_string, char* mensaje, char* mensajeError)
{
	int retorno = 0;
	int reintentos = 3;
	int flag = 0;
	char aux[tam_string];

	if(string != NULL && mensaje != NULL && mensajeError != NULL && tam_string > 2){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(aux, tam_string, stdin);

			if(quitarEnter(aux, tam_string) && strlen(aux) > 2)
			{
				flag = 1;

				for(int i = 0; *(aux + i) != '\0'; i++)
				{

					if(*(aux + i) == ' ')
					{
						flag = 0;
						break;
					}
				}
			}

			if(flag)
			{

				retorno = 1;
				capitalString (aux);
				strncpy(string, aux, tam_string);
				break;
			}
			else
			{
				reintentos --;
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
int get_int(char* mensaje, char* mensajeError, int min, int max, int* pNumero){

	int retorno = 0;
	int reintentos = 2;
	char string[10];
	int auxNum;

	if(pNumero != NULL){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(string, 10, stdin);

			for(int i = 0; i < 10; i++){

				if(string[i] == '\n'){

					string[i] = '\0';
					break;
				}
			}

			if(esNumero(string, 10) == 1){

				auxNum = atoi(string);

				if(auxNum >= min && auxNum <= max){

					*pNumero = auxNum;
					retorno = 1;
					break;
				}
				else{
					printf("Dato inválido. Reintente.\n");
					reintentos--;
				}
			}
			else{
			printf("Dato inválido. Reintente.\n");
			reintentos--;
			}


		}while(reintentos > 0);


	}


	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int esNumero(char string[], int max_string){

	int retorno = 1;

	if (string != NULL && max_string > 0){

		for(int i = 0; string[i] != '\0'; i ++){

			if( i==0 && (string[i] == '+' || string[i] == '-')){

				continue;
			}
			if(string[i] > '9' || string[i] < '0'){

				retorno = 0;
			}

		}

	}

	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int get_float(char* mensaje, char* mensajeError, int min, int max, float* pNumero){

	int retorno = 0;
	int reintentos = 3;
	char string[100];
	float auxNum;

	if(pNumero != NULL){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(string, 100, stdin);

			if(quitarEnter (string, 100) && esFloat(string, 100)){

				auxNum = atof(string);

				if(auxNum > min && auxNum < max){

					*pNumero = auxNum;
					retorno = 1;
					break;
				}
				else{
					printf("Dato inválido. Reintente.\n");
					reintentos--;
				}
			}
			else{
			printf("Dato inválido. Reintente.\n");
			reintentos--;
			}


		}while(reintentos > 0);


	}


	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int esFloat(char string[], int max_string){

	int retorno = 1;
	int flag = 0;

	if (string != NULL && max_string > 0){

		for(int i = 0; string[i] != '\0'; i ++){

			if( i==0 && (string[i] == '+' || string[i] == '-')){

				continue;
			}
			if(flag == 1 && string[i] == '.'){

				retorno = 0;
				break;
			}

			if(string[i] == '.'){

				flag = 1;
				continue;
			}

			if(string[i] > '9' || string[i] < '0'){

				retorno = 0;
				break;
			}

		}

	}

	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int quitarEnter (char string[], int max_string){

	int retorno = 0;
	char aux[max_string];

	strncpy(aux, string, max_string);

	if(string != NULL && max_string > 0){

		for(int i = 0; i < max_string; i++){

			if(aux[i] == '\n'){

				aux[i] = '\0';
				strncpy(string, aux, max_string);
				retorno = 1;

				break;
			}
		}

		if(!retorno){

			printf("No se ha podido procesar la solicitud. Dato demasiado largo.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int capitalString (char* string){

		int retorno = 0;

		if( string != NULL){

			for (int i = 0; *(string + i) != '\0'; i++)
			{


					*(string + i) = tolower(*(string + i));
			}

			string [0] = toupper(string[0]);

			for (int i = 0; *(string + i) != '\0'; i++)
			{

				if ((*(string + i)) == ' '){

					*(string + (i + 1)) = toupper(*(string + (i + 1)));
				}
			}

			retorno = 1;
		}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int getCharacter(char* mensaje, char* mensajeError, char* character){

	int retorno = 0;
	char opcion;
	int check;
	int reintentos = 2;

	if(character != NULL)
	{
		do{
		printf("%s", mensaje);
		fpurge(stdin);
		check = scanf("%c", &opcion);

		opcion = tolower(opcion);

		if(isalpha(opcion))
		{
			*character = opcion;
			retorno = 1;
			break;
		}
		else{

			printf("%s", mensajeError);
			reintentos--;
		}
		}while(reintentos > 0);
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuOrdenar()
{

	int opcion = 0;
	int check = 0;

	printf("\n--------------------------------\n");
	printf("            ORDENAR             \n");
	printf("-------------------------------- \n\n");
	printf("1. NOMBRE\n");
	printf("2. APELLIDO\n");
	printf("3. SEXO\n");
	printf("4. SUELDO\n");
	printf("5. ID\n");

	printf("\nOPCION: ");
	fpurge(stdin);
	check = scanf("%d", &opcion);
	printf("\n\n");


	if(check != 1 || opcion <1 || opcion >4)
	{

		system("clear");
		printf("OPCIÓN INCORRECTA.\n\n");
	}
	return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuBusqueda()
{
	int opcion;
	int check = 0;

	printf("1. ID\n");
	printf("2. NOMBRE\n");
	printf("3. APELLIDO\n");
	printf("4. SEXO\n");
	printf("5. SUELDO\n");
	printf("6. SALIR\n\n");

	printf("\nOPCION: ");
	fpurge(stdin);
	check = scanf("%d", &opcion);
	printf("\n\n");

	if(check != 1 || opcion <1 || opcion >6)
	{
		system("clear");
		printf("OPCIÓN INCORRECTA.\n\n");
	}
	return opcion;
}


