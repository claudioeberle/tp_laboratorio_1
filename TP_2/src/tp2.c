#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tp2.h"
#include "categorias.h"
#include "estadosVuelo.h"
#include "input.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menu(void){

	int opcion;
	int check;

	do{

		printf("\n-------------------------------\n");
		printf("   Sistema   de   Pasajeros \n");
		printf("------------------------------- \n\n");
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


		if(opcion <1 || opcion >6){

			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
		}


		}while(check == 0 && (opcion<1 || opcion>6));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int inicilizarPasajeros(ePas pasajeros[], int max_pasajeros){

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
		printf("%d\n\n", buscarLibre(pasajeros, max_pasajeros, &indice));

				printf("\n--------------------------");
				printf("\n  Alta   de  Pasajero     ");
				printf("\n--------------------------\n");

				ePas nuevoPasajero;

				nuevoPasajero.id = *pProximoId;

				cargaString (nuevoPasajero.nombre, max_nombre, "\nNombre: ", "Dato Incorrecto. \n");

				cargaString (nuevoPasajero.apellido, max_apellido, "\nApellido: ", "Dato Incorrecto. \n");

				cargarPrecio(&nuevoPasajero.precio);

				cargarCodigoVuelo(nuevoPasajero.codigoVuelo, max_codigos);

				cargarCategoriaPasajero(&nuevoPasajero.tipoPasajero, categorias, max_categorias);

				cargarEstadoVuelo(&nuevoPasajero.estadoVuelo, estados, max_estados);

				nuevoPasajero.isEmpty = 0;

				printf("\n--------------------------");
				printf("\n Nuevo Pasajero");
				printf("\n--------------------------");
				mostrarPasajero(nuevoPasajero, categorias, max_categorias, estados, max_estados);

				printf("\nConfirmar carga de nuevo pasajero (s/n): ");
				fpurge(stdin);
				scanf("%c", &confirmacion);

				if(confirmacion == 's'){

					pasajeros[indice] = nuevoPasajero;

					(*pProximoId)++;

					printf("\n***************");
					printf("\nCarga exitosa.\n");
					printf("\n***************");

					retorno = 1;
				}
				else{

					printf("\n******************");
					printf("\nCarga cancelada.\n");
					printf("\n******************");

				}
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
			get_int("\nEstado de Vuelo: ", "Ingrese un dato válido",0, 200, pEstadoVuelo);
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

		printf("\nRespete el formato: 'EZE723AR' (8 digitos)");
		get_code("\nCódigo de Vuelo: ", "Dato incorrecto\n", codigo, max_codigos);
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarPrecio(float* pPrecio){
	int retorno = 0;

	if(pPrecio != NULL){

		get_float("\nPrecio de Vuelo: $", "Dato incorrecto. \n", 0, 99999999, pPrecio);
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
	char estado[10];
	char categoria[30];

	cargarDescripcionEstado(estados, max_estados, pasajero.estadoVuelo, estado);
	cargarDescripcionCategoria(categorias, max_categorias, pasajero.tipoPasajero, categoria);

    printf(" %4d    %.20s             %5s    %.2f    %8s  %s  %s \n",

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

        printf("\n        Listado de Pasajeros      \n");
        printf("-----------------------------------------------------------------------------\n");
        printf("  id     nombre        Apellido       Precio     Vuelo   Categoria    Estado\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i=0; i < max_pasajeros; i++)
        {
            if(pasajeros[i].isEmpty == 0)
            {
            	mostrarPasajeroFila(pasajeros[i], categorias, max_categorias, estados, max_estados);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay empleados en el sistema\n");
        }
        else{

        	retorno = 1;
        }

    }
    return retorno;
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

int hardcodearPasajeros (ePas pasajeros[], int max_pasajeros, int* pProximoId){

	int retorno = 0;
	int indice = 0;
	int contador = 0;

	if( pasajeros != NULL && max_pasajeros > 0){

		ePas listado[10] = {

				{0, "Maria Rosa", "Gallo", 154290.34, "EZE712BA", 101, 1, 0},
				{0, "Jimena", "Monteverde", 132255.14, "JFK381HT", 103, 2, 0},
				{0, "Pablo Jose", "Alancon", 163568.00, "HJW612LW", 103, 2, 0},
				{0, "Patricia", "Palmer", 192539.45, "FGH285PA", 103, 1, 0},
				{0, "Andrea Rosalia", "Del Boca", 182516.17, "EZE761MC", 103, 1, 0},
				{0, "Roberto Carlos", "Mansela", 129231.00, "AJN339BA", 102, 1, 0},
				{0, "Monica", "Guido", 199946.25, "JFK012NY", 102, 0, 0},
				{0, "Gustavo Ariel", "Bermudez", 271903.58, "BCN761BC", 101, 0, 0},
				{0, "German", "Kraus", 78125.93, "BRU772JK", 102, 1, 0},
				{0, "Cristina", "Morena", 192221.00, "EZE002BA", 103, 2, 0}
		};

		for( int i = 0; i < 10; i++){

			indice = 0;

			printf(buscarLibre(pasajeros, max_pasajeros, &indice));

			if(buscarLibre(pasajeros, max_pasajeros, &indice) == 1){

				pasajeros[indice] = listado[i];
				pasajeros[indice].id = *pProximoId;
				(*pProximoId)++;
				contador++;

			}

		}

		retorno = 1;
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
	char confirmacion = 'n';
	int pasId;
	char pasNombre[30];
	char pasApellido[30];
	float pasPrecio;
	char pasCodigo[10];
	int pasCategoria;


	if(pasajeros != NULL && categorias != NULL && estados != NULL && max_pasajeros > 0 &&
			max_nombre > 0 && max_apellido > 0 && max_codigos > 0 && max_categorias > 0 && max_estados > 0)
	{
		if(listarPasajeros(pasajeros, max_pasajeros, categorias, max_categorias, estados, max_estados)){
			get_int("\nElija el ID del pasajero que quiere modificar: ", "Dato incorrecto", 0, 2001, &pasId);
			if(buscarPasajeroId(pasajeros, max_pasajeros, pasId, &indice) == 1){

				do{

					switch(menuModificar()){

							case 1:

								if(cargaString (pasNombre, 30, "\nNuevo nombre: ", "Dato incorrecto\n") == 1){
									printf("\n---------------\n");
									printf("Nombre anterior: %s\n", pasajeros[indice].nombre);
									printf("Nombre nuevo: %s\n", pasNombre);
									printf("\nConfirmar modificación (s): ");
									fpurge(stdin);
									scanf("%c", &confirmacion);

									if(confirmacion == 's'){

										strncpy(pasajeros[indice].nombre, pasNombre, 30);
										printf("\nModificación exitosa.\n");
									}
									else{
										printf("\nModificación cancelada.\n");
									}
								}
								break;

							case 2:

								if(cargaString (pasApellido, 30, "\nNuevo apellido: ", "Dato incorrecto\n") == 1){
									printf("\n---------------\n");
									printf("Apellido anterior: %s\n", pasajeros[indice].apellido);
									printf("Apellido nuevo: %s\n", pasApellido);
									printf("\nConfirmar modificación (s): ");
									fpurge(stdin);
									scanf("%c", &confirmacion);

									if(confirmacion == 's'){

										strncpy(pasajeros[indice].apellido, pasApellido, 30);
										printf("\nModificación exitosa.\n");
									}
									else{
										printf("\nModificación cancelada.\n");
									}
								}

								break;

							case 3:

								if(get_float("Nuevo precio: $", "Dato incorrecto\n", 0, 9999999, &pasPrecio) == 1){
									printf("\n---------------\n");
									printf("Precio anterior: $%.2f\n", pasajeros[indice].precio);
									printf("Precio nuevo: $%.2f\n", pasPrecio);
									printf("\nConfirmar modificación (s): ");
									fpurge(stdin);
									scanf("%c", &confirmacion);

									if(confirmacion == 's'){

										pasajeros[indice].precio = pasPrecio;
										printf("\nModificación exitosa.\n");
									}
									else{
										printf("\nModificación cancelada.\n");
									}
								}
								break;

							case 4:

								if(get_code("\nNuevo código: ", "Dato incorrecto\n", pasCodigo, 10) == 1){
									printf("\n---------------\n");
									printf("Código anterior: %s\n", pasajeros[indice].codigoVuelo);
									printf("Código nuevo: %s\n", pasCodigo);
									printf("\nConfirmar modificación (s): ");
									fpurge(stdin);
									scanf("%c", &confirmacion);

									if(confirmacion == 's'){

										strncpy(pasajeros[indice].codigoVuelo, pasCodigo, 10);
										printf("\nModificación exitosa.\n");
									}
									else{
										printf("\nModificación cancelada.\n");
									}
								}

								break;

							case 5:

								if(cargarCategoriaPasajero(&pasCategoria, categorias, max_categorias) == 1){
									printf("\n---------------\n");
									printf("Categoría anterior: ");
									mostrarCategoriaId(categorias, max_categorias, pasajeros[indice].tipoPasajero);
									printf("Categoría nueva: ");
									mostrarCategoriaId(categorias, max_categorias, pasCategoria);
									printf("\nConfirmar modificación (s): ");
									fpurge(stdin);
									scanf("%c", &confirmacion);

									if(confirmacion == 's'){

										pasajeros[indice].tipoPasajero = pasCategoria;
										printf("\n*****Modificación exitosa*****\n");
									}
									else{
										printf("\n*****Modificación cancelada*****\n");
									}
								}

								break;

							case 6:

								salir = 's';
								break;

					}

				}while(salir != 's');
			}
		}
	retorno = 1;
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuModificar (){

	int opcion = 0;
	int check = 0;


	do{

		printf("\n--------------------------------\n");
		printf("  Modificacion   de   Pasajero  \n");
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


		if(opcion <1 || opcion >6){

			printf("OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n");
		}


		}while(check == 0 && (opcion <1 || opcion >6));

		return opcion;
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

			printf(" No se ha encontrado ningún pasajero con ese ID\n");
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
		printf("\n--------------------------------\n");
		printf("    Baja       de      Pasajero  \n");
		printf("-------------------------------- \n\n");
		if(listarPasajeros(pasajeros, max_pasajeros, categorias, max_categorias, estados, max_estados)){
			get_int("\nElija el ID del pasajero que quiere dar de baja: ", "Dato incorrecto", 0, 2001, &pasId);
			if(buscarPasajeroId(pasajeros, max_pasajeros, pasId, &indice) == 1){

				mostrarPasajero(pasajeros[indice], categorias, max_categorias, estados, max_estados);
				printf("\nPor favor confirmar la baja (s): ");
				fpurge(stdin);
				scanf("%c", &confirmacion);

				if(confirmacion == 's'){

					pasajeros[indice].isEmpty = 1;
					printf("\n*****Baja exitosa*****");
					retorno = 1;
				}
				else{

					printf("\n*****Baja cancelada*****");
				}

			}
		}
	}
	return retorno;
}
