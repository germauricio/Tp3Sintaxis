#include <stdio.h>
#include <stdlib.h>

typedef struct comentarios{
    char* comentario;
    struct comentarios* next;
}comentarios;

comentarios *primeroComentarios, *ultimoComentarios;

void agregarComentario(char* comentarioNuevo){
    comentarios *nuevo;
	nuevo = (comentarios *) malloc (4+strlen(comentarioNuevo));
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
  	nuevo -> comentario = comentarioNuevo;
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
    printf("\nMostrando la lista de comentarios:\n");
    while (auxiliar!=NULL) {
            printf( "Nombre: %s\n", auxiliar->comentario);
            auxiliar = auxiliar->next;
	}
 }

