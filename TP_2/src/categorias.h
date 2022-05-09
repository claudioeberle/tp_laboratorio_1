
#ifndef CATEGORIAS_H_
#define CATEGORIAS_H_

typedef struct{

	int id;
	char descripcion[30];

}eCategoria;

#endif /* CATEGORIAS_H_ */

int validarCategoriaId(eCategoria categorias[], int max_categorias, int id);
int mostrarCategoriaIndice(eCategoria categorias[], int max_categorias, int indice);
int mostrarCategoriaId(eCategoria categorias[], int max_categorias, int id);
int listarCategorias (eCategoria categorias[], int max_categorias);
int cargarDescripcionCategoria(eCategoria categorias[], int max_categorias, int idCategoria, char descCategoria[]);
