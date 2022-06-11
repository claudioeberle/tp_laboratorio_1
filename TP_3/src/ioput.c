#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ioput.h"
#include "LinkedList.h"


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

	if(code != NULL)
	{
		for(int i = 0; *(code + i) != '\0'; i++)
		{
			if( (i >= 0 && i <= 1 && !isalpha(*(code + i))) ||
				(i == 6 && !isalpha(*(code + i))) ||
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

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int definirId(LinkedList* listaPasajeros)
{
	int nextId = -1;
	int mayor;

	if(listaPasajeros != NULL)
	{
		buscarMayorId(listaPasajeros, &mayor);

		nextId = mayor + 1;
	}
	return nextId;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarPrecio(float* precio){

	int retorno = 0;

	if(precio != NULL){

		if(get_float("\nPrecio de Vuelo: $", "Dato incorrecto. \n", 0, 99999999, precio)){

			retorno = 1;
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarCodigoVuelo(char* codigo, int tam_codigos){
	int retorno = 0;

	if(codigo != NULL && tam_codigos > 0){

		printf("\nRespete el formato: 'AB1234C' (7 digitos)");
		if(get_code("\nCódigo de Vuelo: ", "Dato incorrecto\n", codigo, tam_codigos) && validateCode(codigo)){

			retorno = 1;
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarTipoPasajero(int* tipoPasajero){

	int retorno = 0;
	int reintentos = 2;

	if(tipoPasajero != NULL){

		listarTipos();
		do{
			if(get_int("\nSeleccione e ingrese un ID\nTipo de Pasajero: ", "Ingrese un dato válido",1, 3, tipoPasajero))
			{
				retorno = 1;
				break;
			}
			reintentos--;

		}while(reintentos > 0);
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void listarTipos()
{
	printf("\n Tipos de Pasajero  \n");
	printf("----------------------\n");
	printf(" ID     Nombre        \n");
	printf("----------------------\n");
	printf("  1    FirstClass     \n");
	printf("  2    ExecutiveClass \n");
	printf("  3    EconomyClass   \n");
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void listarEstadosVuelo()
{
	printf("\n  Estados de Vuelo  \n");
	printf("----------------------\n");
	printf(" ID     Nombre        \n");
	printf("----------------------\n");
	printf("  1    Aterrizado     \n");
	printf("  2    Demorado       \n");
	printf("  3    En Horario     \n");
	printf("  4    En Vuelo       \n");
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
int cargarEstadoVuelo(int* estadoVuelo){

	int retorno = 0;
	int reintentos = 2;

	if(estadoVuelo != NULL)
	{
		listarEstadosVuelo();

		printf("\nSeleccione e ingrese un ID");
		do{
			if(get_int("\nEstado de Vuelo: ", "Ingrese un dato válido",1, 4, estadoVuelo))
			{
				retorno = 1;
				break;
			}
			reintentos--;

		}while(reintentos > 0);
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarPasajero(Passenger* pasajero){

	int retorno = 0;
	char descTipo[50];
	char descEstadoVuelo[50];

	if(pasajero != NULL)
	{
		if(descripcionTipoPasajero(pasajero->tipoPasajero, descTipo) &&
		   descripcionEstadoVuelo(pasajero->estadoVuelo, descEstadoVuelo))
		{

			printf("\nID: %d\n", pasajero->id);
			printf("Nombre: %s\n", pasajero->nombre);
			printf("Apellido: %s\n", pasajero->apellido);
			printf("Precio Vuelo: $%.2f\n", pasajero->precio);
			printf("Codigo de Vuelo: %s\n", pasajero->codigoVuelo);
			printf("Tipo de Pasajero: %s\n", descTipo);
			printf("Estado de Vuelo: %s\n", descEstadoVuelo);

			retorno = 1;
		}
	}
	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int mostrarPasajeroFila(Passenger* pasajero)
{

	int retorno = 0;
	char descTipo[50];
	char descEstadoVuelo[50];
	//int cant = 0;

	if(pasajero != NULL)
	{
		//printf("%d\n", descripcionTipoPasajero(pasajero->tipoPasajero, descTipo));
		//printf("%d\n", descripcionEstadoVuelo(pasajero->estadoVuelo, descEstadoVuelo));

		if(descripcionTipoPasajero(pasajero->tipoPasajero, descTipo) &&
		   descripcionEstadoVuelo(pasajero->estadoVuelo, descEstadoVuelo))
		{
			//printf("MOSTRAR PASAJEOR FILA %d\n", cant++);

			printf(" %4d %-20s %-20s  $%7.2f      %7s     %-14s    %-10s \n",

																						   pasajero->id,
																						   pasajero->nombre,
																						   pasajero->apellido,
																						   pasajero->precio,
																						   pasajero->codigoVuelo,
																						   descTipo,
																						   descEstadoVuelo
																						   );

			retorno = 1;
		}
	}
	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int descripcionTipoPasajero(int tipoPasajero, char* descTipoPasajero)
{
	int retorno = 0;

	if(descTipoPasajero != NULL)
	{
		switch(tipoPasajero)
		{
			case 1:
				strcpy(descTipoPasajero, "FirstClass");
				retorno = 1;
				break;

			case 2:
				strcpy(descTipoPasajero, "ExecutiveClass");
				retorno = 1;
				break;

			case 3:
				strcpy(descTipoPasajero, "EconomyClass");
				retorno = 1;
				break;
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int indiceTipoPasajero(char* tipoPasajero, int* indiceTipoPasajero)
{
	int retorno = 0;

	if(tipoPasajero != NULL && indiceTipoPasajero != NULL)
	{
		if(strcmp("FirstClass", tipoPasajero) == 0)
		{
			*indiceTipoPasajero = 1;
			retorno = 1;
		}
		else if(strcmp("ExecutiveClass", tipoPasajero) == 0)
		{
			*indiceTipoPasajero = 2;
			retorno = 1;
		}
		else if(strcmp("EconomyClass", tipoPasajero) == 0)
		{
			*indiceTipoPasajero = 3;
			retorno = 1;
		}

	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int descripcionEstadoVuelo(int estadoVuelo, char* descEstadoVuelo)
{
	int retorno = 0;

	if(descEstadoVuelo != NULL)
	{
		switch(estadoVuelo)
		{
			case 1:
				strcpy(descEstadoVuelo, "Aterrizado");
				retorno = 1;
				break;

			case 2:
				strcpy(descEstadoVuelo, "Demorado");
				retorno = 1;
				break;

			case 3:
				strcpy(descEstadoVuelo, "En Horario");
				retorno = 1;
				break;

			case 4:
				strcpy(descEstadoVuelo, "En Vuelo");
				retorno = 1;
				break;

			retorno = 1;
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int indiceEstadoVuelo(char* estadoVuelo, int* indiceEstadoVuelo)
{
	int retorno = 0;
	char* aterrizado = "Aterrizado";
	char* demorado = "Demorado";
	char* enHorario = "En Horario";
	char* enVuelo = "En Vuelo";

	if(estadoVuelo != NULL && indiceEstadoVuelo != NULL)
	{
		if(strcmp(aterrizado, estadoVuelo) == 0)
		{
			//printf("%d\n", strcmp(aterrizado, estadoVuelo));
			*indiceEstadoVuelo = 1;
			retorno = 1;
		}
		else if(strcmp(demorado, estadoVuelo) == 0)
		{
			//printf("%d\n", strcmp(demorado, estadoVuelo));
			*indiceEstadoVuelo = 2;
			retorno = 1;
		}
		else if(strcmp(enHorario, estadoVuelo) == 0)
		{
			//printf("%d\n", strcmp(enHorario, estadoVuelo));
			*indiceEstadoVuelo = 3;
			retorno = 1;
		}
		else if(strcmp(enVuelo, estadoVuelo) == 0)
		{
			//printf("%d\n", strcmp(enVuelo, estadoVuelo));
			*indiceEstadoVuelo = 4;
			retorno = 1;
		}
		else
		{
			printf("aterrizado: %d\n", strcmp(aterrizado, estadoVuelo));
			printf("demorado: %d\n", strcmp(demorado, estadoVuelo));
			printf("en horario: %d\n", strcmp(enHorario, estadoVuelo));
			printf("en vuelo: %d\n", strcmp(enVuelo, estadoVuelo));

			*indiceEstadoVuelo = 1;
			retorno = 1;
			//printf("error en carga de estado de vuelo\n");

		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int salir(char* var)
{
	int retorno = 0;
	char opcion;

	if(var != NULL){

		printf("Confirmar salida.\n");
		printf("Ingrese 's' para salir: ");
		fpurge(stdin);
		scanf("%c", &opcion);
		system("clear");

		if(opcion == 's' || opcion == 'S'){

			*var = opcion;
			retorno = 1;
			despedir();
		}
	}
	else{

		printf("*ERROR* - Reinicie e intente nuevamente.");
	}


	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void saludar ()
{

	printf("\n''''''''''''''''''''''''''''''' \n");
	printf("    Bienvenido  a SISPAS®        \n");
	printf("\n''''''''''''''''''''''''''''''' \n");

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void despedir ()
{

	system("clear");
	printf("¡Hasta Luego!\n\n\n\n");
	printf("\n''''''''''''''''''''''''''''''' \n");
	printf("Gracias por utilizar SISPAS®. \n\n");
	printf("\n''''''''''''''''''''''''''''''' \n");


}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarPasajeroPorId(LinkedList* listadoPasajeros, int* posicionId, int id)
{
    int retorno = 0;
    int idAux = 0;
    Passenger* auxPas = NULL;

    if(listadoPasajeros != NULL && posicionId != NULL && *posicionId >= 0 && id >= 1)
    {
        for(int i = 0; i < ll_len(listadoPasajeros); i++)
        {
            auxPas = ll_get(listadoPasajeros, i);

            if(auxPas != NULL)
            {
                pasajeroBuscarId(auxPas, &idAux);

                if(id == idAux)
                {
                    *posicionId = i;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int pasajeroBuscarId(Passenger* this,int* resultado)
{
    int retorno = 0;

    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;

        retorno = 1;
    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuModificar()
{

	int retorno = 6;
	int opcion = 0;
	int check = 0;
	int reintentos = 2;

	do
	{

		printf("\n--------------------------------\n");
		printf("   MODIFICACIÓN DE PASAJERO      \n");
		printf("-------------------------------- \n\n");
		printf("1. Nombre\n");
		printf("2. Apellido\n");
		printf("3. Precio\n");
		printf("4. Código de Vuelo\n");
		printf("5. Tipo de Pasajero\n");
		printf("6. Salir\n");

		printf("\n¿Qué desea modificar?: ");
		fpurge(stdin);
		check = scanf("%d", &opcion);
		printf("\n\n");


		if(!check || opcion < 1 || opcion > 6){

			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
			reintentos--;

		}
		else{
				retorno = opcion;
				break;
		}


	}while(reintentos > 0);

	return retorno;
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarMayorId(LinkedList* pArrayListPassenger, int* id)
{
	int retorno = 0;
	Passenger* auxPas = NULL;
	int mayor;

	if(pArrayListPassenger != NULL && id != NULL)
	{

		if(ll_len(pArrayListPassenger))
		{

			for(int i=0; i < ll_len(pArrayListPassenger); i++)
			{
				auxPas = (Passenger*) ll_get(pArrayListPassenger, i);

				if(i == 0 || auxPas->id > mayor)
				{
					mayor = auxPas->id;
				}
			}
			*id = mayor + 1;
			retorno = 1;
		}
	}


	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarId(LinkedList* pArrayListPassenger, int id)
{
	int retorno = 0;
	int aux = 0;
	Passenger* auxPas = NULL;

	if(pArrayListPassenger != NULL)
	{
		for(int i=0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPas = (Passenger*) ll_get(pArrayListPassenger, i);

			aux = auxPas->id;

			if(aux == id)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuOrdenar ()
{

	int opcion = 0;
	int check = 0;


	do{

		printf("\n--------------------------------\n");
		printf("            ORDENAR             \n");
		printf("-------------------------------- \n\n");
		printf("1. ID\n");
		printf("2. APELLIDO\n");
		printf("3. TIPO Y CODIGO DE VUELO\n");
		printf("4. CODIGO DE VUELO Y ID\n");

		printf("\nOPCION: ");
		fpurge(stdin);
		check = scanf("%d", &opcion);
		printf("\n\n");


		if(check != 1 || opcion <1 || opcion >4)
		{

			system("clear");
			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
		}


		}while(check != 1 || opcion <1 || opcion >4);

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

