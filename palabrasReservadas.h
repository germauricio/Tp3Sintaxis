#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodo{
    char nombre[30];
    char* tipo;
    struct Nodo* sig;
}Palabra;

Palabra *primeroPr=NULL;


char* tipo (char* palabra){
if ( (strcmp("while", palabra)==0) ||  (strcmp("go to", palabra)==0) ||  (strcmp("if", palabra)==0) || (strcmp("else", palabra)==0)|| (strcmp("do", palabra)==0)|| (strcmp("for", palabra)==0)|| (strcmp("switch", palabra)==0) || (strcmp("case", palabra)==0)||  (strcmp("default", palabra)==0)){
    return "Estructura de control";
    }
if ((strcmp("char", palabra)==0) ||  (strcmp("double", palabra)==0) || (strcmp("float", palabra)==0) || (strcmp("int", palabra)==0) ||(strcmp("long", palabra)==0) || (strcmp("short", palabra)==0) || (strcmp("void", palabra)==0)){
    return "Tipo de dato";
}
if((strcmp("const", palabra)==0) ||  (strcmp("emun", palabra)==0) || (strcmp("return", palabra)==0) || (strcmp("signed", palabra)==0) || (strcmp("sizeof", palabra)==0) ||  (strcmp("struct", palabra)==0) ||  (strcmp("typedef", palabra)==0)){
    return "Otro.";
}
}



Palabra* prEncontrado(Palabra *Lista,char *cadena){
	char *a;
	while(Lista!=NULL){
        a = Lista->nombre;
		if(a == cadena){
			return Lista;
		}else{
			Lista=Lista->sig;
		}
	}
	return Lista;
}


void agregarPalabra(char *palabraReservada){

    Palabra *nuevo;
	Palabra *auxiliar = primeroPr;
	nuevo = (Palabra*) malloc (sizeof(Palabra));
	Palabra *encontrar = prEncontrado (auxiliar,palabraReservada);
	if(encontrar == NULL){
        if (nuevo == NULL) printf( "No hay memoria disponible!\n");
        strcpy(nuevo -> nombre, palabraReservada);
        nuevo -> tipo = tipo (palabraReservada);
        nuevo -> sig = NULL;
        if (primeroPr==NULL) {
            primeroPr = nuevo;
            //ultimoPr = nuevo;
        } else {
            Palabra* aux=primeroPr;
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=nuevo;
        }
	}
}

void recorrerListaPr(){
    Palabra *auxiliar=primeroPr;
    int i;
    i=0;
    printf("Mostrando lista de palabras reservadas:\n\n");
    while (auxiliar!=NULL) {
            printf( "Palabra reservada: %s \n", auxiliar->nombre);
            printf ("De tipo: %s\n", auxiliar->tipo);

            auxiliar = auxiliar->sig;
            i++;
	}
    if (i==0) printf( "\nLa lista está vacía!!\n" );
 }


