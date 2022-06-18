

#ifndef SRC_IOPUT_H_
#define SRC_IOPUT_H_



#endif /* SRC_IOPUT_H_ */


int menu();
int menuModificar();
int menuOrdenar();
int menuBusqueda();
int cargaString (char* string, int tam_string, char* mensaje, char* mensajeError);
int get_int(char* mensaje, char* mensajeError, int min, int max, int* pNumero);
int esNumero(char string[], int max_string);
int get_float(char* mensaje, char* mensajeError, int min, int max, float* pNumero);
int esFloat(char string[], int max_string);
int quitarEnter (char string[], int max_string);
int capitalString (char* string);
int getCharacter(char* mensaje, char* mensajeError, char* character);
int cargaPath (char* string, int tam_string, char* mensaje, char* mensajeError);

