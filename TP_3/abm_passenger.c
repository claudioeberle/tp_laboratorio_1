#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abm_passenger.h"
#include "Passenger.h"
#include "input.h"
#include "LinkedList.h"


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
		if(get_code("\nCódigo de Vuelo: ", "Dato incorrecto\n", codigo, tam_codigos)){

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
		//printf("%d", descripcionTipoPasajero(pasajero->tipoPasajero, descTipo));
		//printf("%d", descripcionEstadoVuelo(pasajero->estadoVuelo, descEstadoVuelo));

		if(descripcionTipoPasajero(pasajero->tipoPasajero, descTipo) &&
		   descripcionEstadoVuelo(pasajero->estadoVuelo, descEstadoVuelo))
		{
			//printf("MOSTRAR PASAJEOR FILA %d\n", cant++);

			printf(" %4d %-17s %-20s     $%9.2f      %7s      %14s    %8s \n",

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
		if(strcmp(aterrizado, estadoVuelo) == -13)
		{
			//printf("%d\n", strcmp(aterrizado, estadoVuelo));
			*indiceEstadoVuelo = 1;
			retorno = 1;
		}
		else if(strcmp(demorado, estadoVuelo) == -13)
		{
			//printf("%d\n", strcmp(demorado, estadoVuelo));
			*indiceEstadoVuelo = 2;
			retorno = 1;
		}
		else if(strcmp(enHorario, estadoVuelo) == -13)
		{
			//printf("%d\n", strcmp(enHorario, estadoVuelo));
			*indiceEstadoVuelo = 3;
			retorno = 1;
		}
		else if(strcmp(enVuelo, estadoVuelo) == -13)
		{
			//printf("%d\n", strcmp(enVuelo, estadoVuelo));
			*indiceEstadoVuelo = 4;
			retorno = 1;
		}
		else
		{
			/*printf("aterrizado: %d\n", strcmp(aterrizado, estadoVuelo));
			printf("demorado: %d\n", strcmp(demorado, estadoVuelo));
			printf("en horario: %d\n", strcmp(enHorario, estadoVuelo));
			printf("en vuelo: %d\n", strcmp(enVuelo, estadoVuelo));
			*/
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

int menuModificar(){

int retorno = 6;
int opcion = 0;
int check = 0;
int reintentos = 2;

do{

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

/*
int cargarCategoriaPasajero(int* pCategoria, eCategoria categorias[], int max_categorias);
int cargarCodigoVuelo(char* codigo, int max_codigos);
int cargarPrecio(float* pPrecio);
int cargaString (char string[], int max_string, char* mensaje, char* mensajeError);
int cargarEstadoVuelo(int* pEstadoVuelo, eEstado estados[], int max_estados);
void mostrarPasajero(ePas pasajero, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
void mostrarPasajeroFila(ePas pasajero, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
int salir(char*);
void despedida (void);
int hardcodearPasajeros (ePas pasajeros[], int max_pasajeros, int* pProximoId);
int modificarPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
int menuModificar(void);
int buscarPasajeroId(ePas pasajeros[], int max_pasajeros, int idPasajero, int* pIndice);
int bajaPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
*/
