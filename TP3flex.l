%{
    #include <math.h>
    #include <stdio.h>
    #include <string.h>
    #include "listaOperadores.h"
    #include "palabrasReservadas.h"
    #include "listaComentarios.h"
    #include "listaIdentificadores.h"
    #include "listaCadenaNR.h"
    #include "constanteReal.h"
    #include "constanteOctalHexaDec.h"
    #include "listaCaractPunt.h"
    #include "literalCadena.h"
    #include "reporte.h"
 
%}

CEDECIMAL 		[1-9][0-9]*
CEOCTAL			0[0-7]*
CEHEXA			0[xX][A-Fa-f0-9]+
CREAL	        	[0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?
PRESERVADA     		while|for|do|if|else|int|char|return|case|switch
OPERADOR        	&&|==|sizeof|\|\||\+=|>=|<=|\*=|\+\+|%=|\-=|\/=|[<>\+\-*&!\/%]
ID       		[a-zA-Z_][a-zA-Z0-9_]*
CARPUNTUACION		[,\/#!$\^;{}`~()]
LITCADENA	    	\"([ -!#-~]|\\\")*\"
COMENTARIOLINEA		\/\/(.)*
COMENTARIOMULTLINEA	\/\*(.|\n)*\*\/
NORECONOCIDO   	 	.

%%
{CEDECIMAL}		{agregarDec(yytext);}
{CEOCTAL}		{agregarOctal(yytext,yyleng);}
{CEHEXA}		{agregarHexa(yytext,yyleng);}
{CREAL}   		{agregarReal(yytext);}
{PRESERVADA}		{agregarPalabra(yytext);}
{OPERADOR} 		{agregarOp(yytext);}
{ID}			{agregarId(yytext);}
{CARPUNTUACION}		{agregarCaract(yytext);}
{LITCADENA}   		{agregarCad(yytext,yyleng);}
{COMENTARIOLINEA}	{agregarComentario(yytext);}
{COMENTARIOMULTLINEA}	{agregarComentario(yytext);}
[ \t\n]+  		
{NORECONOCIDO}		{agregarCadenaNR(yytext);}

%%

int main(){
    yyout = fopen("salida.txt","w");
    yyin = fopen("entrada.txt","r");
    yylex();
    realizarReporte();
    return 0;
}
yywrap(){

  
}