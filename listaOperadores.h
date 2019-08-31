#include <stdio.h>
#include <stdlib.h>

typedef struct operadores{

	int cantidad;
    struct operadores* next;
    char operador[];
}operadores;

operadores *primeroOperador, *ultimoOperador;

int opEncontrado(operadores* lista,char* operador){
	operadores* aux = primeroOperador;
	while(aux!=NULL){
		if(!strcmp(aux->operador,operador)){
			aux->cantidad ++;
			return 1;
		}else{
		aux=aux->next;
		}
	}
	return 0;
}

void agregarOp(char* operadorNuevo){
    operadores *nuevo;
	nuevo = (operadores *) malloc (4+4+strlen(operadorNuevo));
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
  	strcpy(nuevo -> operador,operadorNuevo);
    nuevo -> cantidad = 1;
    nuevo -> next = NULL;
    if(opEncontrado(nuevo,operadorNuevo)==0){
    if (primeroOperador==NULL) {
        primeroOperador = nuevo;
        ultimoOperador = nuevo;
    } else {
    	ultimoOperador->next = nuevo;
        ultimoOperador = nuevo;
    	}
	}
}
void recorrerListaOp(){
    operadores *auxiliar=primeroOperador;
    printf("\n__________Mostrando la lista de operadores:\n\n");
    while (auxiliar!=NULL) {
            printf( "Nombre: %s\n", auxiliar->operador);
            printf( "Cantidad : %d\n", auxiliar->cantidad);
            auxiliar = auxiliar->next;
	}
 }

