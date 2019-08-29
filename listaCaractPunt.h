#include <stdio.h>
#include <stdlib.h>

typedef struct puntuacion{
    char* caracter;
	int cantidad;
    struct puntuacion* next;
}puntuacion;

puntuacion *primeroPuntuacion, *ultimoPuntuacion;

int encontradoCaracter(puntuacion* lista,char* caracter){
	puntuacion* aux = primeroPuntuacion;
	while(aux!=NULL){
		if(aux->caracter == caracter){
			aux->cantidad ++;
			return 1;
		}else{
		aux=aux->next;
		}
	}
	return 0;
}

void agregarCaract(char* caracterNuevo){
    puntuacion *nuevo;
	nuevo = (puntuacion *) malloc (4+4+strlen(caracterNuevo));
    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
  	nuevo -> caracter = caracterNuevo;
    nuevo -> cantidad = 1;
    nuevo -> next = NULL;
    if(encontradoCaracter(nuevo,caracterNuevo)==0){
    if (primeroPuntuacion==NULL) {
        primeroPuntuacion = nuevo;
        ultimoPuntuacion = nuevo;
    } else {
    	ultimoPuntuacion->next = nuevo;
        ultimoPuntuacion = nuevo;
    	}
	}
}
void recorrerListaCaracteres(){
    puntuacion *auxiliar=primeroPuntuacion;
    printf("\nMostrando la lista de caracteres de puntuacion:\n");
    while (auxiliar!=NULL) {
            printf( "Nombre: %s\n", auxiliar->caracter);
            printf( "Cantidad : %d\n", auxiliar->cantidad);
            auxiliar = auxiliar->next;
	}
 }

