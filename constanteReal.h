#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    char *nombreId;
    int cantId;
    struct nodo *sig;
} constantesReales;

constantesReales *primeroReal, *ultimoReal;

void agregarReal(char *numeroNuevo){
    constantesReales *nuevo;
	int a = atof(numeroNuevo);
	nuevo = (constantesReales *) malloc (sizeof(constantesReales));
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
    nuevo -> nombreId = numeroNuevo;
    nuevo -> cantId = a;
    nuevo -> sig = NULL;
    if (primeroReal==NULL) {
        primeroReal = nuevo;
        ultimoReal = nuevo;
    } else {
    	ultimoReal->sig = nuevo;
        ultimoReal = nuevo;
    }
}

void recorrerListaReales(){
    constantesReales *auxiliar = primeroReal;
    int i;
    i=0;
    float a;
    printf("\nMostrando lista de reales:\n");
    while (auxiliar!=NULL) {
            a = atof(auxiliar -> nombreId)-(auxiliar -> cantId);
            printf( "Numero: %s\n", auxiliar -> nombreId);
            printf( "Parte entera: %d\n", auxiliar -> cantId);
            printf( "Parte decimal: %f\n\n", a);
            auxiliar = auxiliar->sig;
            i++;
	}
    if (i==0) printf( "\nLa lista está vacía!!\n" );
 }

