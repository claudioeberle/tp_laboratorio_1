#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargaString (char* string, int tam_string, char* mensaje, char* mensajeError){
	int retorno = 0;
	int reintentos = 3;
	int flag = 0;
	char aux[tam_string];

	if(string != NULL && mensaje != NULL && mensajeError != NULL && tam_string > 0){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(aux, tam_string, stdin);

			if(quitarEnter(aux, tam_string)){

				flag = 0;

				for(int i = 0; *(aux + i) != '\0'; i++){

					if(i != 0 && *(aux + i) == ' '){

						continue;
					}

					if(!isalpha(*(aux + i))){

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
		}while(reintentos > 0);

	}

	if (!reintentos){

		printf("\nNo se ha podido ingresar el dato.");
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

int get_code(char* mensaje, char* mensajeError, char codigo[], int max_codigos){

	int retorno = 0;
	int flag = 0;
	int reintentos = 3;
	char string[max_codigos];

	if(codigo != NULL && max_codigos > 0){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(string, max_codigos, stdin);

			if(quitarEnter (string, max_codigos) && validateCode(string))
			{

				for(int i = 0; string[i] != '\0'; i++)
				{

					if(isalpha(string[i]))
					{

						string[i] = toupper(string[i]);
					}
				}
				strncpy(codigo, string, max_codigos);
				retorno = 1;
				break;
			}
			else
			{
				flag = 1;
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos > 0);

		if(!reintentos){

			printf("\nNo se ha podido ingresar el dato.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validateCode(char* code)
{
	int retorno = 0;

	if(code != NULL && strlen(code) == 7)
	{
		for(int i = 0; *(code + i) != '\0'; i++)
		{
			if( (i >= 0 && i <= 1 && !isalpha(*(code + i))) ||
				(i >= 6 && i <= 7 && !isalpha(*(code + i))) ||
				(i >= 2 && i <= 5 && !isdigit(*(code + i))))
			{
				retorno = 0;
				break;
			}
			else
			{
				retorno = 1;
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

int menu(void){

	int opcion;
	int check;

	do{

		printf("\n---------------------------------\n");
		printf(" SISTEMA DE GESTIÓN DE PASAJEROS \n");
		printf("--------------------------------- \n\n");
		printf("1.  Cargar los datos de los pasajeros en el archivo data.csv (MODO TEXTO)\n\n");
		printf("2.  Cargar los datos de los pasajeros desde el archivo data.bin (MODO BINARIO)\n\n");
		printf("3.  ALTA DE PASAJERO\n\n");
		printf("4.  MODIFICAR PASAJERO\n\n");
		printf("5.  BAJA DE PASAJERO\n\n");
		printf("6.  LISTAR PASAJEROS\n\n");
		printf("7.  ORDENAR PASAJEROS\n\n");
		printf("8.  Guardar los datos de los pasajeros en el archivo data.csv (MODO TEXTO)\n\n");
		printf("9.  Guardar los datos de los pasajeros en el archivo data.bin (MODO BINARIO)\n\n");
		printf("10. SALIR\n\n");

		printf("Elija una opción: ");
		fpurge(stdin);
		check = scanf("%d", &opcion);
		printf("\n\n");


		if(check != 1 || (opcion <1 && check == 1) || (opcion >10 && check == 1)){

			system("clear");
			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
		}


		}while(check != 1 && (opcion <1 || opcion >10));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
