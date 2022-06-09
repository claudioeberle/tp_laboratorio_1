#include "pasajeros.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "categorias.h"
#include "estadosVuelo.h"
#include "input.h"
#include "linkedList.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menu(void){

	int opcion;
	int check;

	do{

		printf("\n---------------------------------\n");
		printf(" SISTEMA DE GESTIÓN DE PASAJEROS \n");
		printf("--------------------------------- \n\n");
		printf("1. ALTA\n\n");
		printf("2. MODIFICAR\n\n");
		printf("3. BAJA\n\n");
		printf("4. INFORMES\n\n");
		printf("5. HARCODEAR VALORES\n\n");
		printf("6. SALIR\n\n");

		printf("Elija una opción: ");
		fpurge(stdin);
		check = scanf("%d", &opcion);
		printf("\n\n");


		if(check != 1 || (opcion <1 && check == 1) || (opcion >6 && check == 1)){

			system("clear");
			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
		}


		}while(check != 1 && (opcion <1 || opcion >6));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int inicializarPasajeros(ePas pasajeros[], int max_pasajeros){

	int retorno = 0;

	if(pasajeros != NULL && max_pasajeros > 0){
		for (int i = 0; i < max_pasajeros; i++){

			pasajeros[i].isEmpty = 1;
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarLibre(ePas pasajeros[], int max_pasajeros, int* pIndice){
	int retorno = 0;
	int flag = 0;

	if(pasajeros != NULL && pIndice != NULL && max_pasajeros > 0){

		for(int i = 0; i < max_pasajeros; i++){

			if(pasajeros[i].isEmpty == 1){

				*pIndice = i;
				flag = 1;
				retorno = 1;
				break;
			}
		}

		if(!flag){

			*pIndice = -1;

			printf("No hay espacio disponible para cargar nuevos pasajeros.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int altaPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados, int* pProximoId){

	int retorno = 0;
	int indice = 0;
	char confirmacion;

	if(pasajeros != NULL && categorias != NULL && estados != NULL && max_pasajeros > 0 && pProximoId != NULL &&
		max_nombre > 0 && max_apellido > 0 && max_codigos > 0 && max_categorias > 0 && max_estados > 0 &&
		buscarLibre(pasajeros, max_pasajeros, &indice))
	{

		system("clear");
		printf("\n--------------------------");
		printf("\n    ALTA DE PASAJERO      ");
		printf("\n--------------------------\n");

		ePas nuevoPasajero;

		nuevoPasajero.id = *pProximoId;

		if( (cargaString (nuevoPasajero.nombre, max_nombre, "\nNombre: ", "Dato Incorrecto. \n")) &&
			(cargaString (nuevoPasajero.apellido, max_apellido, "\nApellido: ", "Dato Incorrecto. \n")) &&
			(cargarPrecio(&nuevoPasajero.precio)) &&
			(cargarCodigoVuelo(nuevoPasajero.codigoVuelo, max_codigos)) &&
			(cargarCategoriaPasajero(&nuevoPasajero.tipoPasajero, categorias, max_categorias)) &&
			(cargarEstadoVuelo(&nuevoPasajero.estadoVuelo, estados, max_estados)))
			{

				nuevoPasajero.isEmpty = 0;

				system("clear");
				printf("\n--------------------------");
				printf("\n     NUEVO  PASAJERO      ");
				printf("\n--------------------------");

				mostrarPasajero(nuevoPasajero, categorias, max_categorias, estados, max_estados);

				if( getCharacter("\nConfirmar carga de nuevo pasajero (s): ","Dato Incorrecto", &confirmacion, 's', 's'))
				{
					if(confirmacion == 's' || confirmacion == 'S')
					{

						agregarPasajero(pasajeros, max_pasajeros, nuevoPasajero.id, nuevoPasajero.nombre, nuevoPasajero.apellido, nuevoPasajero.precio, nuevoPasajero.tipoPasajero, nuevoPasajero.codigoVuelo, nuevoPasajero.estadoVuelo, indice);
						(*pProximoId)++;
						system("clear");
						printf("\n********************\n");
						printf("\n   CARGA EXITOSA   \n\n");
						printf("********************\n");

						retorno = 1;
					}

					else{

						system("clear");
						printf("\n********************\n");
						printf("\n  CARGA CANCELADA \n\n");
						printf("********************\n");

					}
				}
			}
			else
			{	system("clear");
				printf("Error en la carga.-\n\n");
				printf("\n********************\n");
				printf("\n  CARGA CANCELADA \n\n");
				printf("********************\n");
			}
	}
	return retorno;
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int agregarPasajero (ePas pasajeros[], int max_pasajeros, int id, char nombre[], char apellido[], float precio, int tipoPasajero, char codigoVuelo[], int estadoVuelo, int indice)
{
	int retorno = 0;

	if(pasajeros != NULL && max_pasajeros > 0)
	{
		pasajeros[indice].id = id;
		pasajeros[indice].precio = precio;
		pasajeros[indice].estadoVuelo = estadoVuelo;
		pasajeros[indice].tipoPasajero = tipoPasajero;
		strncpy(pasajeros[indice].nombre, nombre, 30);
		strncpy(pasajeros[indice].apellido, apellido, 30);
		strncpy(pasajeros[indice].codigoVuelo, codigoVuelo, 10);
		pasajeros[indice].isEmpty = 0;
	}
	return retorno;
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargaString (char string[], int max_string, char* mensaje, char* mensajeError){
	int retorno = 0;
	int reintentos = 3;
	int flag = 0;
	char aux[max_string];
	if(string != NULL && max_string > 0){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(aux, max_string, stdin);

			if(quitarEnter(aux, max_string)){

				flag = 0;

				for(int i = 0; aux[i] != '\0'; i++){

					if(i != 0 && aux[i] == ' '){

						continue;

					}

					if(!isalpha(aux[i])){

						flag = 1;
						reintentos --;
						printf("%s", mensajeError);
						break;
					}
				}

				if(!flag){

					retorno = 1;
					capitalString (aux);
					strncpy(string, aux, max_string);
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

int cargarCategoriaPasajero(int* pCategoria, eCategoria categorias[], int max_categorias){

	int retorno = 0;
	int reintentos = 2;

	if(pCategoria != NULL){

		listarCategorias(categorias, max_categorias);
		do{
			get_int("\nSeleccione e ingrese un ID\nTipo de Pasajero: ", "Ingrese un dato válido",0, 200, pCategoria);
			if(validarCategoriaId(categorias, max_categorias, *pCategoria)){
				retorno = 1;
				break;
			}
			reintentos--;

		}while(reintentos > 0);
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarEstadoVuelo(int* pEstadoVuelo, eEstado estados[], int max_estados){

	int retorno = 0;
	int reintentos = 2;

	if(pEstadoVuelo != NULL){

		listarEstados(estados, max_estados);
		printf("\nSeleccione e ingrese un ID");
		do{
			get_int("\nEstado de Vuelo: ", "Ingrese un dato válido",1, 3, pEstadoVuelo);
			if(validarEstadoId(estados, max_estados, *pEstadoVuelo)){
				retorno = 1;
				break;
			}
			reintentos--;

		}while(reintentos > 0);
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarCodigoVuelo(char codigo[], int max_codigos){
	int retorno = 0;

	if(codigo != NULL && max_codigos > 0){

		printf("\nRespete el formato: 'KKK666KK' (8 digitos)");
		if(get_code("\nCódigo de Vuelo: ", "Dato incorrecto\n", codigo, max_codigos)){

			retorno = 1;
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarPrecio(float* pPrecio){
	int retorno = 0;

	if(pPrecio != NULL){

		if(get_float("\nPrecio de Vuelo: $", "Dato incorrecto. \n", 0, 99999999, pPrecio)){

			retorno = 1;
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarPasajero(ePas pasajero, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados){


		printf("\nID: %d\n", pasajero.id);
		printf("Nombre: %s\n", pasajero.nombre);
		printf("Apellido: %s\n", pasajero.apellido);
		printf("Precio Vuelo: $%.2f\n", pasajero.precio);
		printf("Codigo de Vuelo: %s\n", pasajero.codigoVuelo);

		for(int i = 0; i < max_categorias; i++){

			if(pasajero.tipoPasajero == categorias[i].id){

				printf("Tipo de Pasajero: %s\n", categorias[i].descripcion);
			}
		}
		for(int i = 0; i < max_estados; i++){

			if(pasajero.estadoVuelo == estados[i].id){

				printf("Estado de Vuelo: %s\n", estados[i].descripcion);
			}
		}

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarPasajeroFila(ePas pasajero, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados)
{
	char estado[20];
	char categoria[40];

	cargarDescripcionEstado(estados, max_estados, pasajero.estadoVuelo, estado);
	cargarDescripcionCategoria(categorias, max_categorias, pasajero.tipoPasajero, categoria);

    printf(" %4d      %-17s    %-17s     $%10.2f      %8s       %-9s     %-9s\n",

           pasajero.id,
           pasajero.nombre,
           pasajero.apellido,
           pasajero.precio,
		   pasajero.codigoVuelo,
           categoria,
		   estado
           );
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarPasajeros(ePas pasajeros[], int max_pasajeros, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados)
{
    int retorno = 0;
    int flag = 1;
    if( pasajeros != NULL && categorias != NULL && estados != NULL && max_pasajeros > 0 && max_categorias > 0 && max_estados > 0)
    {

        printf("\n LISTADO DE PASAJEROS      \n");
        printf("--------------------------------------------------------------------------------------------------------------\n");
        printf("  ID         Nombre               Apellido              Precio          Vuelo        Categoria       Estado\n");
        printf("--------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i < max_pasajeros; i++)
        {
            if(pasajeros[i].isEmpty == 0)
            {
            	mostrarPasajeroFila(pasajeros[i], categorias, max_categorias, estados, max_estados);
            	//printf("_____________________________________________________________________________________________________________\n");

                flag = 0;
            }
        }

        if(flag)
        {
            printf("No hay empleados en el sistema\n");
        }
        else{

        	retorno = 1;
        }

    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int salir(char* var){

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
			despedida();
		}
	}
	else{

		printf("*ERROR* - Reinicie e intente nuevamente.");
	}


	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void bienvenida (){

	printf("\n''''''''''''''''''''''''''''''' \n");
	printf("    Bienvenido  a SISPAS®        \n");
	printf("\n''''''''''''''''''''''''''''''' \n");

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void despedida (){

	system("clear");
	printf("¡Hasta Luego!\n\n\n\n");
	printf("\n''''''''''''''''''''''''''''''' \n");
	printf("Gracias por utilizar SISPAS®. \n\n");
	printf("\n''''''''''''''''''''''''''''''' \n");


}


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int hardcodearPasajeros (ePas pasajeros[], int max_pasajeros, int* pProximoId){

	int retorno = 0;
	int indice = 0;
	int contador = 0;

	if( pasajeros != NULL && max_pasajeros > 0){

		ePas listado[25] = {

				{0, "Maria Rosa", "Gallo", 154290.34, "EZE712BA", 101, 3, 0},
				{0, "Jimena", "Monteverde", 132255.14, "EZE712BA", 103, 3, 0},
				{0, "Pablo Jose", "Alarcon", 163568.00, "BCN761BC", 103, 1, 0},
				{0, "Patricia", "Gomez", 192539.45, "BCN761BC", 103, 1, 0},
				{0, "Andrea Rosalia", "Del Boca", 182516.17, "JFK761MC", 103, 2, 0},
				{0, "Roberto Carlos", "Mansela", 129231.00, "BCN761BC", 102, 1, 0},
				{0, "Monica", "Guido", 199946.25, "EZE712BA", 102, 3, 0},
				{0, "Gustavo Ariel", "Bermudez", 271903.58, "BCN761BC", 101, 1, 0},
				{0, "German", "Kraus", 78125.93, "BCN761BC", 102, 1, 0},
				{0, "Franco", "Jimenez",117352.93, "EZE712BA", 103, 3, 0},
				{0, "Julian", "Gomez", 172419.54, "BCN761BC", 102, 1, 0},
				{0, "Fabiana", "Cantilo", 207829.00, "JFK761MC", 102, 2, 0},
				{0, "Hugo", "Moyano", 111629.00, "JFK761MC", 101, 2, 0},
				{0, "Sabrina", "Fernandez", 152399.19, "JFK761MC", 102, 2, 0},
				{0, "German", "Fernandez", 92416.47, "JFK761MC", 101, 2, 0},
				{0, "German", "Gomez", 66193.44, "BCN761BC", 103, 1, 0},
				{0, "Rodrigo", "Gomez", 199723.10, "BCN761BC", 102, 1, 0},
				{0, "Patricia", "Fernandez", 172333.99, "EZE712BA", 102, 3, 0},
				{0, "Florencia", "Fernandez", 110120.00, "JFK761MC", 102, 2, 0},
				{0, "Cristina", "Morena", 192221.00, "EZE712BA", 103, 3, 0},
				{0, "Franco Anibal", "Gimenez", 110221.00, "CDG101PA", 102, 1, 0},
				{0, "Tristan", "Mosser", 192221.00, "CDG101PA", 102, 1, 0},
				{0, "Julian", "Assange", 121332.00, "CDG101PA", 102, 1, 0},
				{0, "Romina", "Ricci", 199999.99, "CDG101PA", 101, 1, 0},
				{0, "Felicitas", "Wan", 100000.01, "CDG101PA", 101, 1, 0}
		};

		for( int i = 0; i < 25; i++){

			indice = 0;

			if(buscarLibre(pasajeros, max_pasajeros, &indice) == 1){

				pasajeros[indice] = listado[i];
				pasajeros[indice].id = *pProximoId;
				(*pProximoId)++;
				contador++;

			}

		}

		retorno = 1;
		system("clear");
		printf("Se agregaron %d pasajeros al sistema.", contador);
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int modificarPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados)
{
	int retorno = 0;
	char salir;
	int indice;
	int opcion;
	char confirmacion = 'n';
	int pasId = 0;
	char pasNombre[30];
	char pasApellido[30];
	float pasPrecio;
	char pasCodigo[10];
	int pasCategoria;


	if(pasajeros != NULL && categorias != NULL && estados != NULL && max_pasajeros > 0 &&
			max_nombre > 0 && max_apellido > 0 && max_codigos > 0 && max_categorias > 0 && max_estados > 0)
	{
		system("clear");
		printf("\n--------------------------------\n");
		printf("   MODIFICACIÓN  DE  PASAJERO      \n");
		printf("-------------------------------- \n");
		if(listarPasajeros(pasajeros, max_pasajeros, categorias, max_categorias, estados, max_estados))
		{

			get_int("\nElija el ID del pasajero que quiere modificar: ", "Dato incorrecto", 1000, 3001, &pasId);

			if(buscarPasajeroId(pasajeros, max_pasajeros, pasId, &indice) == 1)
			{
				system("clear");
				do{

					mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
					opcion = menuModificar();
					switch(opcion){

							case 1:

								system("clear");
								mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
								printf("-------------------------------- \n\n");
								if(cargaString (pasNombre, 30, "\nNuevo nombre: ", "Dato incorrecto\n") == 1){
									printf("\n---------------\n");
									printf("Nombre anterior: %s\n", pasajeros[indice].nombre);
									printf("Nombre nuevo: %s\n", pasNombre);
									getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion, 'a', 'z');

									if(confirmacion == 's'){

										strncpy(pasajeros[indice].nombre, pasNombre, 30);
										system("clear");
										printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");

									}
									else{
										system("clear");
										printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
									}
								}
								break;

							case 2:

								system("clear");
								mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
								printf("-------------------------------- \n\n");
								if(cargaString (pasApellido, 30, "\nNuevo apellido: ", "Dato incorrecto\n") == 1){
									printf("\n---------------\n");
									printf("Apellido anterior: %s\n", pasajeros[indice].apellido);
									printf("Apellido nuevo: %s\n", pasApellido);
									getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion, 'a', 'z');
									if(confirmacion == 's'){

										strncpy(pasajeros[indice].apellido, pasApellido, 30);
										system("clear");
										printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
									}
									else{
										system("clear");
										printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
									}
								}

								break;

							case 3:

								system("clear");
								mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
								printf("-------------------------------- \n\n");
								if(get_float("Nuevo precio: $", "Dato incorrecto\n", 0, 9999999, &pasPrecio) == 1){
									printf("\n---------------\n");
									printf("Precio anterior: $%.2f\n", pasajeros[indice].precio);
									printf("Precio nuevo: $%.2f\n", pasPrecio);
									getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion, 'a', 'z');

									if(confirmacion == 's'){

										pasajeros[indice].precio = pasPrecio;
										system("clear");
										printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
									}
									else{
										system("clear");
										printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
									}
								}
								break;

							case 4:

								system("clear");
								mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
								printf("-------------------------------- \n\n");
								if(get_code("\nNuevo código: ", "Dato incorrecto\n", pasCodigo, 10) == 1){
									printf("\n---------------\n");
									printf("Código anterior: %s\n", pasajeros[indice].codigoVuelo);
									printf("Código nuevo: %s\n", pasCodigo);
									getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion, 'a', 'z');

									if(confirmacion == 's'){

										strncpy(pasajeros[indice].codigoVuelo, pasCodigo, 10);
										system("clear");
										printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
									}
									else{
										system("clear");
										printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
									}
								}

								break;

							case 5:

								system("clear");
								mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
								printf("-------------------------------- \n\n");
								if(cargarCategoriaPasajero(&pasCategoria, categorias, max_categorias) == 1){
									printf("\n---------------\n");
									printf("Categoría anterior: ");
									mostrarCategoriaId(categorias, max_categorias, pasajeros[indice].tipoPasajero);
									printf("Categoría nueva: ");
									mostrarCategoriaId(categorias, max_categorias, pasCategoria);
									getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion, 'a', 'z');

									if(confirmacion == 's'){

										pasajeros[indice].tipoPasajero = pasCategoria;
										system("clear");
										printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");
									}
									else{
										system("clear");
										printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");
									}
								}

								break;

							case 6:

								salir = 's';
								system("clear");
								break;

					}

				}while(salir != 's' && salir != 'S');
			}
		}
	retorno = 1;
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuModificar (){

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
		printf("5. Categoria\n");
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

int buscarPasajeroId(ePas pasajeros[], int max_pasajeros, int idPasajero, int* pIndice)
{
	int retorno = 0;

	if(pasajeros != NULL && max_pasajeros > 0 && pIndice != NULL){


		for( int i = 0; i < max_pasajeros; i++){

			retorno = -1;

			if(pasajeros[i].id == idPasajero && pasajeros[i].isEmpty == 0){

				*pIndice = i;
				retorno = 1;
				break;
			}
		}
		if(retorno == -1){
			system("clear");
			printf(" No se ha encontrado ningún pasajero con ese ID\n\n");
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bajaPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados)
{
	int retorno = 0;
	char confirmacion = 'n';
	int pasId;
	int indice;


	if(pasajeros != NULL && categorias != NULL && estados != NULL && max_pasajeros > 0 &&
			max_nombre > 0 && max_apellido > 0 && max_codigos > 0 && max_categorias > 0 && max_estados > 0)
	{
		system("clear");
		printf("\n--------------------------------\n");
		printf("      BAJA   DE   PASAJERO       \n");
		printf("-------------------------------- \n");
		if(listarPasajeros(pasajeros, max_pasajeros, categorias, max_categorias, estados, max_estados)){
			get_int("\nElija el ID del pasajero que quiere dar de baja: ", "Dato incorrecto", 0, 2001, &pasId);
			if(buscarPasajeroId(pasajeros, max_pasajeros, pasId, &indice) == 1){

				system("clear");
				printf("\n--------------------------------\n");
				printf("      BAJA   DE   PASAJERO       \n");
				printf("-------------------------------- \n\n");
				mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
				printf("\nPor favor confirmar la baja (s): ");
				fpurge(stdin);
				scanf("%c", &confirmacion);

				if(confirmacion == 's'){


					pasajeros[indice].isEmpty = 1;
					system("clear");
					printf("\n->->-> Baja exitosa <-<-<-\n\n");
					retorno = 1;

				}
				else{
					system("clear");
					printf("\n->->-> Baja cancelada <-<-<-\n\n");

				}

			}
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuInformes (){

	int opcion = 0;
	int check = 0;


	do{
		//system("clear");
		printf("\n--------------------------------\n");
		printf("            INFORMES             \n");
		printf("-------------------------------- \n\n");
		printf("1. LISTADO DE PASAJEROS (ID)\n");
		printf("2. LISTADO DE PASAJEROS (APELLIDO / TIPO DE PASAJERO)\n");
		printf("3. LISTADO DE PASAJEROS (CÓDIGO DE VUELO / ESTADO DE VUELO 'ACTIVO')\n");
		printf("4. TOTAL PASAJES / PROMEDIO / PASAJEROS SOBRE EL PROMEDIO\n");
		printf("5. SALIR\n");

		printf("\nOPCION: ");
		fpurge(stdin);
		check = scanf("%d", &opcion);
		printf("\n\n");


		if(check != 1 || (opcion <1 && check != 1) || (opcion >5 && check != 1)){

			system("clear");
			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
		}


		}while(check != 1 || (opcion <1 || opcion >5));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int informesPasajeros(ePas pasajeros[], int max_pasajeros, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados)
{
	int retorno = 0;
	char salir;
	int criterio;



	if(pasajeros != NULL && categorias != NULL && estados != NULL && max_pasajeros > 0 && max_categorias > 0 && max_estados > 0)
	{
				system("clear");
				do{

					switch(menuInformes()){

							case 1:

								printf("Criterios:\n\nASCENDENTE: 1\nDESCENDENTE: 0\n\n");
								if(get_int("Criterio: ", "**Dato Incorrecto**\n", 0, 1, &criterio))
								{
									ordenarPasajerosId(pasajeros, max_pasajeros, criterio);
									system("clear");
									listarPasajeros(pasajeros, max_pasajeros, categorias, max_categorias, estados, max_estados);
								}
								break;

							case 2:

								printf("Criterios:\n\nASCENDENTE: 1\nDESCENDENTE: 0\n\n");
								if(get_int("Criterio: ", "**Dato Incorrecto**\n", 0, 1, &criterio))
								{
									ordenarPasajerosApellidoTipo(pasajeros, max_pasajeros, criterio);
									system("clear");
									listarPasajeros(pasajeros, max_pasajeros, categorias, max_categorias, estados, max_estados);
								}
								break;

							case 3:

								printf("Criterios:\n\nASCENDENTE: 1\nDESCENDENTE: 0\n\n");
								if(get_int("Criterio: ", "**Dato Incorrecto**\n", 0, 1, &criterio))
								{
									ordenarPasajerosCodigoEstado(pasajeros, max_pasajeros, criterio);
									system("clear");
									listarPasajerosEstadoActivo(pasajeros, max_pasajeros, categorias, max_categorias, estados, max_estados);
								}
								break;
							case 4:
								system("clear");
								informeTotalPromedioCantidadPasajeros(pasajeros, max_pasajeros);
								break;

							case 5:

								salir = 's';
								system("clear");
								break;

					}

				}while(salir != 's');


	retorno = 1;
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarPasajerosEstadoActivo(ePas pasajeros[], int max_pasajeros, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados)
{
    int retorno = 0;
    int flag = 1;
    if( pasajeros != NULL && categorias != NULL && estados != NULL && max_pasajeros > 0 && max_categorias > 0 && max_estados > 0)
    {

        printf("\n LISTADO DE PASAJEROS con ESTADO DE VUELO 'ACTIVO'      \n");
        printf("--------------------------------------------------------------------------------------------------------------\n");
        printf("  ID         Nombre               Apellido              Precio          Vuelo        Categoria       Estado\n");
        printf("--------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i < max_pasajeros; i++)
        {
            if(pasajeros[i].isEmpty == 0 && pasajeros[i].estadoVuelo == 1)
            {
            	mostrarPasajeroFila(pasajeros[i], categorias, max_categorias, estados, max_estados);
            	//printf("_____________________________________________________________________________________________________________\n");

                flag = 0;
            }
        }

        if(flag)
        {
            printf("No hay empleados con Estado de Vuelo ACTIVO en el sistema\n");
        }
        else{

        	retorno = 1;
        }

    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ordenarPasajerosId(ePas pasajeros[], int max_pasajeros, int criterio)
{
    int retorno = 0;
    ePas auxPas;

    if( pasajeros != NULL && max_pasajeros > 0)
    {
        for(int i=0; i < max_pasajeros - 1; i++)
        {
            for(int j= i+1; j < max_pasajeros; j++)
            {
            	if(criterio == 1)
            	{
					if(pasajeros[i].id > pasajeros[j].id)
					{
						auxPas = pasajeros[i];
						pasajeros[i] = pasajeros[j];
						pasajeros[j] = auxPas;
					}
            	}

            	else
            	{
            		if(pasajeros[i].id < pasajeros[j].id)
					{
						auxPas = pasajeros[i];
						pasajeros[i] = pasajeros[j];
						pasajeros[j] = auxPas;


					}
            	}
            }
        }
        retorno = 1;
    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ordenarPasajerosApellidoTipo(ePas pasajeros[], int max_pasajeros, int criterio)
{
    int retorno = 0;
    ePas auxPas;

    if( pasajeros != NULL && max_pasajeros > 0)
    {
        for(int i=0; i < max_pasajeros - 1; i++)
        {
            for(int j= i+1; j < max_pasajeros; j++)
            {
            	if(criterio == 1)
            	{
            		if((strcmp(pasajeros[i].apellido,pasajeros[j].apellido) > 0) ||
					   (strcmp(pasajeros[i].apellido,pasajeros[j].apellido) == 0 &&
						pasajeros[i].tipoPasajero > pasajeros[j].tipoPasajero))
					{
						auxPas = pasajeros[i];
						pasajeros[i] = pasajeros[j];
						pasajeros[j] = auxPas;
					}
            	}

            	else
            	{
            		if((strcmp(pasajeros[i].apellido,pasajeros[j].apellido) < 0) ||
					   (strcmp(pasajeros[i].apellido,pasajeros[j].apellido) == 0 &&
						pasajeros[i].tipoPasajero < pasajeros[j].tipoPasajero))
					{
						auxPas = pasajeros[i];
						pasajeros[i] = pasajeros[j];
						pasajeros[j] = auxPas;


					}
            	}
            }
        }
        retorno = 1;
    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ordenarPasajerosCodigoEstado(ePas pasajeros[], int max_pasajeros, int criterio)
{
    int retorno = 0;
    ePas auxPas;

    if( pasajeros != NULL && max_pasajeros > 0)
    {
        for(int i=0; i < max_pasajeros - 1; i++)
        {
            for(int j= i+1; j < max_pasajeros; j++)
            {

            	if(criterio == 1)
            	{
            		if((strcmp(pasajeros[i].codigoVuelo,pasajeros[j].codigoVuelo) > 0) ||
					   (strcmp(pasajeros[i].codigoVuelo,pasajeros[j].codigoVuelo) == 0 &&
						pasajeros[i].estadoVuelo > pasajeros[j].estadoVuelo))
					{
						auxPas = pasajeros[i];
						pasajeros[i] = pasajeros[j];
						pasajeros[j] = auxPas;
					}
				}

				else
				{
					if((strcmp(pasajeros[i].codigoVuelo,pasajeros[j].codigoVuelo) < 0) ||
					   (strcmp(pasajeros[i].codigoVuelo,pasajeros[j].codigoVuelo) == 0 &&
						pasajeros[i].estadoVuelo < pasajeros[j].estadoVuelo))
					{
						auxPas = pasajeros[i];
						pasajeros[i] = pasajeros[j];
						pasajeros[j] = auxPas;


					}
            	}
            }
        }
        retorno = 1;
    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int sumaPreciosPasajes(ePas pasajeros[], int max_pasajeros, float* pSumaPrecios, int* pCantPasajeros)
{
    int retorno = 0;

    if( pasajeros != NULL && pSumaPrecios != NULL && pCantPasajeros != NULL && max_pasajeros > 0)
    {
    	for(int i = 0; i < max_pasajeros; i++){

    		if(pasajeros[i].isEmpty == 0){

    			*pSumaPrecios += pasajeros[i].precio;
    			*pCantPasajeros += 1;
    			retorno = 1;
    		}
    	}
    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int promedioPreciosPasajes(ePas pasajeros[], int max_pasajeros, float* pPromedioPasajes)
{
    int retorno = 0;
    float sumaPrecios = 0;
    int cantidadPasajeros = 0;

    if( pasajeros != NULL && pPromedioPasajes != NULL && max_pasajeros > 0)
    {
    	if(sumaPreciosPasajes(pasajeros, max_pasajeros, &sumaPrecios, &cantidadPasajeros))
    	{
    		*pPromedioPasajes = sumaPrecios/cantidadPasajeros;
    		retorno = 1;
    	}
    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cantidadPasajerosPreciosEncimaPromedio(ePas pasajeros[], int max_pasajeros, int* pCantidadPasajeros)
{
    int retorno = 0;
    int contador = 0;
    float pasajePromedio;

    if( pasajeros != NULL && pCantidadPasajeros != NULL && max_pasajeros > 0)
    {
    	if(promedioPreciosPasajes(pasajeros, max_pasajeros, &pasajePromedio))
    	{
			for(int i = 0; i < max_pasajeros; i++){

				if(pasajeros[i].isEmpty == 0 && pasajeros[i].precio > pasajePromedio){

					contador += 1;
					retorno = 1;
				}
			}
    	}

    	if(contador){

    		*pCantidadPasajeros = contador;
    	}
    }
    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int informeTotalPromedioCantidadPasajeros( ePas pasajeros[], int max_pasajeros)
{

	int retorno = 0;
	float sumaPasajes = 0;
	int cantPasajeros = 0;
	float promedioPasajes = 0;
	int cantSobrePromedio = 0;

    	if( pasajeros != NULL && max_pasajeros > 0)
	    {

    		system("clear");
	    	if (sumaPreciosPasajes(pasajeros, max_pasajeros, &sumaPasajes, &cantPasajeros))
	    	{
				printf("\n--------------------------------------------------------------------------------------\n");
				printf("Cantidad Total de Pasajes: $%.2f \n", sumaPasajes);
				printf("\n--------------------------------------------------------------------------------------\n");
	    	}
	    	else
	    	{
				printf("\n--------------------------------------------------------------------------------------\n");
				printf("Cantidad Total de Pasajes: No hay suficientes datos.\n");
				printf("\n--------------------------------------------------------------------------------------\n");
	    	}

	    	if(promedioPreciosPasajes(pasajeros, max_pasajeros, &promedioPasajes))
	    	{
	    		printf("Precio Promedio de pasajes: $%.2f \n", promedioPasajes);
				printf("\n--------------------------------------------------------------------------------------\n");
	    	}
	    	else
	    	{
				printf("Precio Promedio de pasajes: No hay suficientes datos.\n");
				printf("\n--------------------------------------------------------------------------------------\n");
	    	}

	    	if(cantidadPasajerosPreciosEncimaPromedio(pasajeros, max_pasajeros, &cantSobrePromedio))
	    	{
	    		printf("Cantidad de Pasajeros con Pasajes por Encima del Promedio: %d\n", cantSobrePromedio);
				printf("\n--------------------------------------------------------------------------------------\n");
	    	}
	    	else
	    	{
				printf("Cantidad de Pasajeros con Pasajes por Encima del Promedio: No hay suficientes datos.\n");
				printf("\n--------------------------------------------------------------------------------------\n");
	    	}

	    	retorno = 1;

	    }
	    return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


