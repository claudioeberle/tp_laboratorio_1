#include "LinkedList.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

int passengerToText(FILE* pFile , LinkedList* pArrayListPassenger);
int passengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger);

int nextIdToBinary(FILE* pFile, int* nextId);
