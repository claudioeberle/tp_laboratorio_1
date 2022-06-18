
#include "LinkedList.h"
#include "parser.h"

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_



#endif /* SRC_CONTROLLER_H_ */

int controller_loadFromBinary(char* path , LinkedList* listadoEmpleados);
int controller_loadIdFromBinary(char* path , int* nextId);
int controller_addEmpleado(LinkedList* listadoEmpleados, int* nextId);
int controller_editEmpleado(LinkedList* listadoEmpleados);
int controller_removeEmpleado(LinkedList* listadoEmpleados);
int controller_ListEmpleado(LinkedList* listadoEmpleados);
int controller_sortEmpleado(LinkedList* listadoEmpleados);
int controller_saveNextId(char* path, int* nextId);
int controller_saveAsBinary(char* path , LinkedList* listado);
int controller_backup(LinkedList* listado);
int controller_buscarEmpleado(LinkedList* listado);
