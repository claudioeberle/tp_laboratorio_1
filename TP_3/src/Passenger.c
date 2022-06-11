#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "ioput.h"

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

	/*
	 printf("%s\n", idStr);
	 printf("%s\n", nombreStr);
	 printf("%s\n", apellidoStr);
	 printf("%s\n", precioStr);
	 printf("%s\n", tipoPasajeroStr);
	 printf("%s\n", codigoVueloStr);
	 printf("%s\n", estadoVueloStr);


	 printf("id parametro: %d\n", Passenger_setId(new_passenger, atoi(idStr)));
	 printf("nombre parametro: %d\n", Passenger_setNombre(new_passenger, nombreStr));
	 printf("apellido parametro: %d\n", Passenger_setApellido(new_passenger, apellidoStr));
	 printf("precio parametro: %d\n", Passenger_setPrecio(new_passenger, atof(precioStr)));
	 printf("codigo parametro: %d\n", Passenger_setCodigoVuelo(new_passenger, codigoVueloStr));
	 printf("tipo parametro: %d\n", Passenger_setTipoPasajero(new_passenger, tipoPasajeroStr));
	 printf("estado parametro: %d\n", Passenger_setEstadoVuelo(new_passenger, estadoVueloStr));
*/

	if( !(Passenger_setId(new_passenger, atoi(idStr)) &&
		  Passenger_setNombre(new_passenger, nombreStr) &&
		  Passenger_setApellido(new_passenger, apellidoStr) &&
		  Passenger_setPrecio(new_passenger, atof(precioStr)) &&
		  Passenger_setCodigoVuelo(new_passenger, codigoVueloStr) &&
		  Passenger_setTipoPasajero(new_passenger, tipoPasajeroStr) &&
		  Passenger_setEstadoVuelo(new_passenger, estadoVueloStr)))
	{
/*
		 printf("id parametro: %d\n", Passenger_setId(new_passenger, atoi(idStr)));
		 printf("nombre parametro: %d\n", Passenger_setNombre(new_passenger, nombreStr));
		 printf("apellido parametro: %d\n", Passenger_setApellido(new_passenger, apellidoStr));
		 printf("precio parametro: %d\n", Passenger_setPrecio(new_passenger, atof(precioStr)));
		 printf("codigo parametro: %d\n", Passenger_setCodigoVuelo(new_passenger, codigoVueloStr));
		 printf("tipo parametro: %d\n", Passenger_setTipoPasajero(new_passenger, tipoPasajeroStr));
		 printf("estado parametro: %d\n", Passenger_setEstadoVuelo(new_passenger, estadoVueloStr));
*/
		free(new_passenger);
		new_passenger = NULL;
		printf("ROMPE EL PASSENGER NEW PARAMETROS!\n");
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
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	char name[50];

	if(this != NULL && nombre != NULL && strlen(nombre) < 50 && strlen(nombre) > 1)
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

	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo, codigoVuelo, 8);
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
		//printf("setEstadoVuelo1...\n");
		indiceEstadoVuelo(estadoVuelo, &indexEstado);
		//printf("setEstadoVuelo2...\n");

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

int Passenger_getIdStr(Passenger* this,char* id)
{
	int retorno = 0;
	int aux;

	if(this != NULL && id != NULL)
	{
		Passenger_getId(this, &aux);
		sprintf(id, "%d", aux);
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
		strncpy(codigoVuelo, this->codigoVuelo, 8);
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

int Passenger_getTipoStr(Passenger* this,char* tipo)
{
	int retorno = 0;
	int aux;

	if(this != NULL && tipo != NULL)
	{
		Passenger_getTipoPasajero(this, &aux);

		descripcionTipoPasajero(aux, tipo);

		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/


int Passenger_getPrecio(Passenger* this, int* precio)
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

int Passenger_getPrecioStr(Passenger* this, char* precio)
{
	int retorno = 0;
	int aux;

	if(this != NULL && precio != NULL)
	{
		Passenger_getPrecio(this, &aux);
		sprintf(precio, "%d", aux);
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

int Passenger_getEstadoVueloStr(Passenger* this, char* estadoVuelo)
{
	int retorno = 0;
	int aux;

	if(this != NULL && estadoVuelo != NULL)
	{
		Passenger_getEstadoVuelo(this, &aux);
		descripcionEstadoVuelo(aux, estadoVuelo);
		retorno = 1;
	}

	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int passengerSortById(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* pas1 = (Passenger*)a;
		Passenger* pas2 = (Passenger*)b;

		if(pas1->id == pas2->id)
		{
			retorno = 0;
		}
		else if(pas1->id > pas2->id)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int passengerSortByApellido(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* pas1 = (Passenger*)a;
		Passenger* pas2 = (Passenger*)b;

		if(strcmp(pas1->apellido, pas2->apellido) == 0)
		{
			retorno = 0;
		}
		else if(strcmp(pas1->apellido, pas2->apellido) > 0)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/

int passengerSortByCodigo(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* pas1 = (Passenger*)a;
		Passenger* pas2 = (Passenger*)b;

		if(strcmp(pas1->codigoVuelo, pas2->codigoVuelo) == 0)
		{
			retorno = 0;
		}
		else if(strcmp(pas1->codigoVuelo, pas2->codigoVuelo) > 0)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/


int passengerSortByTipo(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* pas1 = (Passenger*)a;
		Passenger* pas2 = (Passenger*)b;

		if(pas1->tipoPasajero == pas2->tipoPasajero)
		{
			retorno = 0;
		}
		else if(pas1->tipoPasajero > pas2->tipoPasajero)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}

/*/////////////////////////////////////////////////////////////////////////////*/
