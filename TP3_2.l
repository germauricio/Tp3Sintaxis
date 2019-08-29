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
CREAL	        [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?
PRESERVADA      while|for|do|if|else|int|char|return|case|switch
ID       		[a-zA-Z_][a-zA-Z0-9_]*
COMENTARIO		\/\/(.)*
CARPUNTUACION	[,\/#!$\^;{}`~()]
LITCADENA	    \"([ -!#-~]|\\\")*\"
OPERADOR        &&|==|sizeof|\|\||\+=|>=|<=|\*=|\+\+|%=|\-=|\/=|[<>\+\-*&!\/%]
NORECONOCIDO    .
%%


{CEDECIMAL}     {agregarDec(yytext);}
{CEOCTAL}       {agregarOctal(yytext,yyleng);}
{CEHEXA}        {agregarHexa(yytext,yyleng);}
{CREAL}         {agregarReal(yytext);}
{PRESERVADA}    {agregarPalabra(yytext);}
{ID}            {agregarId(yytext);}
{COMENTARIO}    {agregarComentario(yytext);}
{LITCADENA}     {agregarCad(yytext,yyleng);}
{OPERADOR}      {agregarOp(yytext);}
{CARPUNTUACION} {agregarCaract(yytext);}
{NORECONOCIDO}  {agregarCadenaNR(yytext);}


%%

int main(){
    yyout = fopen("salida.txt","w");
    yyin = fopen("entrada.txt","r");
    yylex();
    return 0;
}
yywrap(){

    realizarReporte();
}
