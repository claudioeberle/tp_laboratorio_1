#include "Passenger.h"

#ifndef ABM_PASSENGER_H_
#define ABM_PASSENGER_H_

#include "Passenger.h"
#include "LinkedList.h"
#include "input.h"



#endif /* ABM_PASSENGER_H_ */

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
