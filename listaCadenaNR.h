#include <stdio.h>
#include <stdlib.h>

typedef struct cadenaNoReconocida{
    char cadenaNR[10];
    struct cadenaNoReconocida* next;
}cadenaNoReconocida;

cadenaNoReconocida *primeroCadenaNoReconocida, *ultimoCadenaNoReconocida;

void agregarCadenaNR(char* cadenaNRNuevo){
    cadenaNoReconocida *nuevo;
	nuevo = (cadenaNoReconocida *) malloc (4+10);
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
  	strcpy(nuevo -> cadenaNR, cadenaNRNuevo);
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
    printf("\n__________Mostrando la lista de no reconocidos:\n\n");
    while (auxiliar!=NULL) {
            printf( "Nombre: %s\n", auxiliar->cadenaNR);
            auxiliar = auxiliar->next;
	}
 }
