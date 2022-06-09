#include "Passenger.h"

#ifndef ABM_PASSENGER_H_
#define ABM_PASSENGER_H_

#include "Passenger.h"
#include "LinkedList.h"
#include "input.h"



#endif /* ABM_PASSENGER_H_ */


int proximoId(LinkedList* lista, int* proximoId);
Passenger* buscarPasajeroPorId(LinkedList* listaPasajeros, int id);
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
int salir(char* var);
void saludar ();
void despedir ();
int menuModificar();
