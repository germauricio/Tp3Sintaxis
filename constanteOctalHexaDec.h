#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct nodo1{
    char *nombreId;
    int cantId;
    struct nodo1 *sig;
} octales, hexadecimales;
	octales *primeroOctal, *ultimoOctal = NULL;
	hexadecimales *primeroHexa, *ultimoHexa = NULL;

typedef struct nodo2{
	char *nombreId;
	struct nodo2 *sig;
} decimales;
decimales *primeroDecimal, *ultimoDecimal = NULL;

int acumDec = 0;
int octalADecimal(char *cadenaOctal, int longitud) {
  int decimal = 0;
  int potencia = 0;
  for (int i = longitud - 1; i >= 0; i--) {

    int valorActual = cadenaOctal[i] - '0';
    // Elevar 8 a la potencia que se va incrementando, y multiplicarla por el
    // valor
    int elevado = pow(8, potencia) * valorActual;

    // Agregar al número
    decimal += elevado;
    // Avanzar en la potencia
    potencia++;
  }
  return decimal;
}
void agregarOctal(char *numeroNuevo, int longitud){
    octales *nuevo;

	int a = octalADecimal(numeroNuevo,longitud);

	nuevo = (octales*) malloc (4+4+strlen(numeroNuevo));

    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
    nuevo -> nombreId = numeroNuevo;

    nuevo -> cantId = a;
    nuevo -> sig = NULL;
    if (primeroOctal==NULL) {
        primeroOctal = nuevo;
        ultimoOctal = nuevo;
    } else {
    	ultimoOctal->sig = nuevo;
        ultimoOctal = nuevo;
    }
}


void mostrarOctal() {
 octales* aux = primeroOctal;
 printf("Mostrando lista de octales:\n\n");
 while( aux!=NULL ) {
 	printf("%s%s\n","Numero en octal: ",aux->nombreId);
	printf("%s%d\n","Valor en Decimal: ",aux->cantId);
 	aux = aux->sig;
 }
}

int caracterHexadecimalADecimal(char caracter) {
  if (isdigit(caracter))
    return caracter - '0';
  return 10 + (toupper(caracter) - 'A');
}

int hexadecimalADecimal(char *cadenaHexadecimal, int longitud) {

  int decimal = 0;
  int potencia = 0;
  for (int i = longitud - 1; i >= 0; i--) {
    // Obtener el decimal, por ejemplo para A es 10, para F 15 y para 9 es 9
    int valorActual = caracterHexadecimalADecimal(cadenaHexadecimal[i]);
    // Elevar 16 a la potencia que se va incrementando, y multiplicarla por el
    // valor
    int elevado = pow(16, potencia) * valorActual;

    // Agregar al número
    decimal += elevado;
    // Avanzar en la potencia
    potencia++;
  }
  return decimal;
}
void agregarHexa(char *numeroNuevo, int longitud){
    hexadecimales *nuevo;

	int a = hexadecimalADecimal(numeroNuevo,longitud);

	nuevo = (hexadecimales*) malloc (4+4+strlen(numeroNuevo));

    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
    nuevo -> nombreId = numeroNuevo;

    nuevo -> cantId = a;
    nuevo -> sig = NULL;
    if (primeroHexa==NULL) {
        primeroHexa = nuevo;
        ultimoHexa = nuevo;
    } else {
    	ultimoHexa->sig = nuevo;
        ultimoHexa = nuevo;
    }
}


void mostrarHexadecimal() {
 hexadecimales* aux = primeroHexa;
 while( aux!=NULL ) {
 	printf("%s%s\n","Numero en hexadecimal: ",aux->nombreId);
	printf("%s%d\n","Valor en Decimal: ",aux->cantId);
 	aux = aux->sig;
 }

 }
void sumarAcum(char* cadenaDec){
	int a= atoi(cadenaDec);
	acumDec = acumDec + a;
}
void agregarDec (char *cadenaDecimal ){
	decimales *nuevo;

	sumarAcum(cadenaDecimal);

	nuevo = (octales*) malloc (4+strlen(cadenaDecimal));

    if (nuevo == NULL) printf( "No hay memoria disponible!\n");
    nuevo -> nombreId = cadenaDecimal;
    printf("agre %s \n", nuevo -> nombreId);
    nuevo -> sig = NULL;
    if (primeroDecimal==NULL) {
        primeroDecimal = nuevo;
        ultimoDecimal = nuevo;
    } else {
    	ultimoDecimal->sig = nuevo;
        ultimoDecimal = nuevo;
    }
}

void mostrarDec (){
	decimales* aux = primeroDecimal;
    printf("Mostrando lista de decimales:\n\n");

 while( aux!=NULL ) {
 	printf("%s%s\n","Numero decimal: ",aux->nombreId);
 	aux = aux->sig;
 }
 printf("%s%i\n","Valor acumulado de decimales: ",acumDec);
}

