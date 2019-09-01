#include <stdio.h>
#include <stdlib.h>

typedef struct comentarios{
    char comentario[50];
    struct comentarios* next;
}comentarios;

comentarios *primeroComentarios, *ultimoComentarios = NULL;

void agregarComentario(char* comentarioNuevo){
    comentarios *nuevo;
	nuevo = (comentarios *) malloc (4+50);
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
  	strcpy(nuevo -> comentario, comentarioNuevo);

    nuevo -> next = NULL;
    if (primeroComentarios==NULL) {
        primeroComentarios = nuevo;
        ultimoComentarios = nuevo;
    } else {
    	ultimoComentarios->next = nuevo;
        ultimoComentarios = nuevo;
	}
}

void recorrerListaCom(){
    comentarios *auxiliar=primeroComentarios;
    printf("\n__________Mostrando la lista de comentarios:\n\n");
    while (auxiliar!=NULL) {
            printf( "Nombre: %s\n", auxiliar->comentario);
            auxiliar = auxiliar->next;
	}
 }

