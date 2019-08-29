#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char identificador[90];
	int cantidad;
    struct node* next;
}nodoIdentificador;

nodoIdentificador *primeroId, *ultimoId;

int idEncontrado(nodoIdentificador* lista,char* iden){
	nodoIdentificador* aux = primeroId;
	while(aux!=NULL){
		if(aux->identificador == iden){
			aux->cantidad ++;
			return 1;
		}else{
		aux=aux->next;
		}
	}
	return 0;
}

void agregarId(char *iden){
    nodoIdentificador *nuevo;
	nuevo = (nodoIdentificador *) malloc (4+4+strlen(iden));
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
  	strcpy(nuevo -> identificador, iden);
    nuevo -> cantidad = 1;
    nuevo -> next = NULL;
    if(idEncontrado(nuevo,iden)==0){
    if (primeroId==NULL) {
        primeroId = nuevo;
        ultimoId = nuevo;
    } else {
    	ultimoId->next = nuevo;
        ultimoId = nuevo;
    	}
	}
}
void recorrerListaId(){
    nodoIdentificador *auxiliar=primeroId;
    printf("\nMostrando la lista de identificadores:\n");
    while (auxiliar!=NULL) {
            printf( "Nombre: %s\n", auxiliar->identificador);
            printf( "Cantidad : %d\n", auxiliar->cantidad);
            auxiliar = auxiliar->next;
	}
 }
