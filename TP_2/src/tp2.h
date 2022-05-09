#include "categorias.h"
#include "estadosVuelo.h"
#include "input.h"

#ifndef TP2_H_
#define TP2_H_

typedef struct{

	int id;
	char nombre[30];
	char apellido[30];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int isEmpty;

}ePas;

#endif /* TP2_H_ */

void bienvenida (void);
int menu(void);
int inicilizarPasajeros(ePas pasajeros[], int max_pasajeros);
int buscarLibre(ePas pasajeros[], int max_pasajeros, int* pIndice);
int altaPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados, int* pProximoId);
int cargarCategoriaPasajero(int* pCategoria, eCategoria categorias[], int max_categorias);
int cargarCodigoVuelo(char* codigo, int max_codigos);
int cargarPrecio(float* pPrecio);
int cargaString (char string[], int max_string, char* mensaje, char* mensajeError);
int cargarEstadoVuelo(int* pEstadoVuelo, eEstado estados[], int max_estados);
void mostrarPasajero(ePas pasajero, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
void mostrarPasajeroFila(ePas pasajero, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
int listarPasajeros(ePas pasajeros[], int max_pasajeros, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
int salir(char*);
void despedida (void);
int hardcodearPasajeros (ePas pasajeros[], int max_pasajeros, int* pProximoId);
int modificarPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);
int menuModificar(void);
int buscarPasajeroId(ePas pasajeros[], int max_pasajeros, int idPasajero, int* pIndice);
int bajaPasajero(ePas pasajeros[], int max_pasajeros, int max_nombre, int max_apellido, int max_codigos, eCategoria categorias[], int max_categorias, eEstado estados[], int max_estados);



