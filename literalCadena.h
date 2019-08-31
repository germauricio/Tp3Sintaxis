#include <stdio.h>
#include <stdlib.h>

typedef struct cadena{
	char nombre[50];
	struct cadena *sig;
	int tamanio;
}cad;

cad *primeroCAD, *ultimoCAD;

cad* encontrado(char *nombre){
	cad *auxiliar=primeroCAD;
	char *nombreAux;
	while(auxiliar!=NULL){
		nombreAux = auxiliar->nombre;
		if(nombreAux==nombre){
			return auxiliar;
		}else{
			auxiliar=auxiliar->sig;
		}
	}
	return auxiliar;
}


void agregarCad(char *cadena, int tamanio){
    cad *nuevo;
	nuevo = (cad *) malloc (sizeof(cad));
	cad *encontrar = encontrado (cadena);
	if(encontrar == NULL){
        if (nuevo == NULL) printf( "No hay memoria disponible!\n");
        strcpy(nuevo -> nombre, cadena);
        nuevo -> sig = NULL;
        nuevo -> tamanio = tamanio;
        if (primeroCAD==NULL) {
            primeroCAD = nuevo;
            ultimoCAD = nuevo;
        } else {
            ultimoCAD->sig = nuevo;
            ultimoCAD = nuevo;
        }
	}
}



void recorrerListaCadena(){
    cad *auxiliar=primeroCAD;
    int i;
    i=0;
    printf("\n__________Mostrando lista de cadenas:\n\n");
    while (auxiliar!=NULL) {
            printf( "cadena: %s\n", auxiliar->nombre);
            printf( "tamanio: %i\n", auxiliar->tamanio);
            auxiliar = auxiliar->sig;
            i++;
	}
    if (i==0) printf( "\nLa lista está vacía!!\n" );
 }

