#include <stdio.h>
#include <stdlib.h>

typedef struct cadenaNoReconocida{
    char* cadenaNR;
    struct cadenaNoReconocida* next;
}cadenaNoReconocida;

cadenaNoReconocida *primeroCadenaNoReconocida, *ultimoCadenaNoReconocida;

void agregarCadenaNR(char* cadenaNRNuevo){
    cadenaNoReconocida *nuevo;
	nuevo = (cadenaNoReconocida *) malloc (4+strlen(cadenaNRNuevo));
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
  	nuevo -> cadenaNR = cadenaNRNuevo;
    nuevo -> next = NULL;
    if (primeroCadenaNoReconocida==NULL) {
        primeroCadenaNoReconocida = nuevo;
        ultimoCadenaNoReconocida = nuevo;
    } else {
    	ultimoCadenaNoReconocida->next = nuevo;
        ultimoCadenaNoReconocida = nuevo;
	}
}

void recorrerListaNoReconocidos(){
    cadenaNoReconocida *auxiliar=primeroCadenaNoReconocida;
    printf("\nMostrando la lista de no reconocidos:\n");
    while (auxiliar!=NULL) {
            printf( "Nombre: %s\n", auxiliar->cadenaNR);
            auxiliar = auxiliar->next;
	}
 }
