#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "input.h"

/*/////////////////////////////////////////////////////////////////////////////*/

Passenger* Passenger_new()
{
	Passenger* new_passenger = NULL;

	new_passenger = (Passenger*) malloc(sizeof(Passenger));

	if(new_passenger != NULL)
	{
		new_passenger->id = 0;
		strcpy(new_passenger->nombre, "NN");
		strcpy(new_passenger->apellido, "NN");
		new_passenger ->precio = 0;
		new_passenger ->tipoPasajero = 0;
		strcpy(new_passenger->codigoVuelo, "NN");

	}

	return new_passenger;

}

/*/////////////////////////////////////////////////////////////////////////////*/

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr)
{

	Passenger* new_passenger = Passenger_new();


	if( !(Passenger_setId(new_passenger, atoi(idStr)) &&
		  Passenger_setNombre(new_passenger, nombreStr) &&
		  Passenger_setApellido(new_passenger, apellidoStr) &&
		  Passenger_setPrecio(new_passenger, atof(precioStr)) &&
		  Passenger_setTipoPasajero(new_passenger, tipoPasajeroStr) &&
		  Passenger_setCodigoVuelo(new_passenger, codigoVueloStr) &&
		  Passenger_setEstadoVuelo(new_passenger, estadoVueloStr)))
	{
		free(new_passenger);
		new_passenger = NULL;
	}

	return new_passenger;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->id =id;
		retorno = 1;
		//printf("set ID\n");
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	char name[50];

	if(this != NULL && nombre != NULL && strlen(nombre) < 50 && strlen(nombre) > 2)
	{
		strcpy(name, nombre);
		capitalString(name);
		strcpy(this->nombre, name);
		//printf("set NOMBRE\n");
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	char surname[50];

	if(this != NULL && apellido != NULL && strlen(apellido) < 50 && strlen(apellido) > 2)
	{
		strcpy(surname, apellido);
		capitalString(surname);
		strcpy(this->apellido, surname);
		//printf("set APELLIDO\n");
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL && validateCode(codigoVuelo))
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		//printf("set CODIGO\n");
		retorno = 1;
	}

	return retorno;
}
/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int retorno = 0;

	if(this != NULL && tipoPasajero != NULL)
	{

		if (strcmp(tipoPasajero, "FirstClass") == 0)
		{
			this->tipoPasajero = 1;
			retorno = 1;
		}
		else if (strcmp(tipoPasajero, "ExecutiveClass") == 0)
		{
			this->tipoPasajero = 2;
			retorno = 1;
		}
		else if (strcmp(tipoPasajero, "EconomyClass") == 0)
		{
			this->tipoPasajero = 3;
			retorno = 1;
		}
	}
	return retorno;

}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;

	if(this != NULL && precio > 0)
	{
		this->precio =precio;
		//printf("precio\n");
		retorno = 1;
	}

	return retorno;

}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{

	int retorno = 0;
	int indexEstado;

	if(this != NULL && estadoVuelo != NULL)
	{

		indiceEstadoVuelo(estadoVuelo, &indexEstado);

		this->estadoVuelo = indexEstado;
		retorno = 1;
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

void Passenger_delete( Passenger* Passenger)
{
	free(Passenger);
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
				retorno = 1;
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = 0;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}

	return retorno;
}
/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = 0;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;

}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{

	int retorno = 0;

	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		retorno = 1;
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/
