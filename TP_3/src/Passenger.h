
#ifndef PASSENGER_H_
#define PASSENGER_H_



typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;

}Passenger;

//constructores
Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);

//destructor

void Passenger_delete( Passenger* Passenger);

//setters y getters

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);
int Passenger_getIdStr(Passenger* this,char* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_getTipoStr(Passenger* this,char* tipo);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,int* precio);
int Passenger_getPrecioStr(Passenger* this, char* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);
int Passenger_getEstadoVueloStr(Passenger* this, char* estadoVuelo);

//sorters

int passengerSortById(void* a, void* b);
int passengerSortByApellido(void* a, void* b);
int passengerSortByTipo(void* a, void* b);
int passengerSortByCodigo(void* a, void* b);


#endif /* PASSENGER_H_ */

