
#ifndef ESTADOSVUELO_H_
#define ESTADOSVUELO_H_

typedef struct{

	int id;
	char descripcion[10];

}eEstado;

#endif /* ESTADOSVUELO_H_ */

int validarEstadoId(eEstado estados[], int max_estados, int id);
int mostrarEstadoIndice(eEstado estados[], int max_estados, int posicion);
int listarEstados (eEstado estados[], int max_estados);
int cargarDescripcionEstado(eEstado estados[], int max_estados, int idEstado, char descEstado[]);
