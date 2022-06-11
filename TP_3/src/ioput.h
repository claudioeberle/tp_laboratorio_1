
#ifndef INPUT_H_
#define INPUT_H_

#include "LinkedList.h"

#include "Passenger.h"

#endif /* INPUT_H_ */

int cargaString (char* string, int tam_string, char* mensaje, char* mensajeError);
int get_int(char* mensaje, char* mensajeError, int min, int max, int* pNumero);
int esNumero(char string[], int max_string);
int get_code(char* mensaje, char* mensajeError, char codigo[], int max_codigos);
int validateCode(char* code);
int get_float(char* mensaje, char* mensajeError, int min, int max, float* pNumero);
int esFloat(char string[], int max_string);
int quitarEnter (char string[], int max_string);
int capitalString (char* string);
int getCharacter(char* mensaje, char* mensajeError, char* character);
int menu(void);
int definirId(LinkedList* listaPasajeros);
int buscarPasajeroPorId(LinkedList* listadoPasajeros, int* posicionId, int id);
int pasajeroBuscarId(Passenger* this,int* resultado);
int cargarPrecio(float* precio);
int cargarCodigoVuelo(char* codigo, int tam_codigos);
void listarTipos();
int cargarTipoPasajero(int* tipoPasajero);
void listarEstadosVuelo();
int cargarEstadoVuelo(int* estadoVuelo);
int descripcionTipoPasajero(int tipoPasajero, char* descTipoPasajero);
int indiceTipoPasajero(char* tipoPasajero, int* indiceTipoPasajero);
int descripcionEstadoVuelo(int estadoVuelo, char* descEstadoVuelo);
int indiceEstadoVuelo(char* estadoVuelo, int* indiceEstadoVuelo);
int mostrarPasajero(Passenger* pasajero);
int mostrarPasajeroFila(Passenger* pasajero);
int buscarMayorId(LinkedList* lista, int* id);
int salir(char* var);
void saludar ();
void despedir ();
int menuModificar();
int validarId(LinkedList* pArrayListPassenger, int id);
int menuOrdenar(void);
