
#ifndef SRC_EMPLEADO_H_
#define SRC_EMPLEADO_H_


#endif /* SRC_EMPLEADO_H_ */

#include "LinkedList.h"

/*/////////////////////////////////////////////////////////////////////////////*/

typedef struct{

	int id;
	char nombre[20];
	char apellido[20];
	char sexo;
	float sueldo;


}eEmpleado;

/*/////////////////////////////////////////////////////////////////////////////*/

//mostrador
void mostrarEmpleado(eEmpleado* unEmpleado);
void mostrarEmpleadoFila(eEmpleado* pEmpleado);
int listarEmpleados(LinkedList* listado);
eEmpleado* getEmpleadoById(LinkedList* lista, int id);

/*/////////////////////////////////////////////////////////////////////////////*/

//constructores
eEmpleado* new_empleado();
eEmpleado* new_empleadoParam(int id, char* nombre, char* apellido, char sexo, float sueldo);

int altaForzadaEmpleados(LinkedList* listado, int cantidadEmpleados);

/*/////////////////////////////////////////////////////////////////////////////*/

//setters
int empleadoSetId(eEmpleado* emp, int id);
int empleadoSetNombre(eEmpleado* emp, char* nombre);
int empleadoSetApellido(eEmpleado* emp, char* apellido);
int empleadoSetSexo(eEmpleado* emp, char sexo);
int empleadoSetSueldo(eEmpleado* emp, float sueldo);

/*/////////////////////////////////////////////////////////////////////////////*/

//getters
int empleadoGetId(eEmpleado* emp, int* id);
int empleadoGetNombre(eEmpleado* emp, char* nombre);
int empleadoGetApellido(eEmpleado* emp, char* apellido);
int empleadoGetSexo(eEmpleado* emp, char* sexo);
int empleadoGetSexoFull(eEmpleado* emp, char* sexo);
int empleadoGetSueldo(eEmpleado* emp, float* sueldo);
int empleadoGetNombreCompleto(eEmpleado* emp, char* nombreCompleto);

/*/////////////////////////////////////////////////////////////////////////////*/

//destructor
void EmpleadoDestroy(eEmpleado* emp);

/*/////////////////////////////////////////////////////////////////////////////*/

//sorter

int empleadoSortBySueldo(void* a, void* b);
int empleadoSortBySexo(void* a, void* b);
int empleadoSortByNombre(void* a, void* b);
int empleadoSortByApellido(void* a, void* b);
int empleadoSortById(void* a, void* b);

/*/////////////////////////////////////////////////////////////////////////////*/

//buscadores

int busquedaPorId(LinkedList* listado);
int busquedaPorNombre(LinkedList* listadoAux);
int filtrarNombre (LinkedList* listadoAux, char* nombre);
int busquedaPorApellido(LinkedList* listadoAux);
int filtrarApellido (LinkedList* listadoAux, char* apellido);
int busquedaPorSexo(LinkedList* listadoAux);
int filtrarSexo (LinkedList* listadoAux, char sexo);
int busquedaPorSueldo(LinkedList* listadoAux);
int filtrarSueldo (LinkedList* listadoAux, float sueldo);
