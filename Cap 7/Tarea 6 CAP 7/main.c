#include <stdio.h>
#include <string.h>

/* Funciones de la biblioteca string.h para el manejo de cadenas de caracteres. */

void main(void)
{
    char *cad0 = "Hola Mexico";
    char cad1[20], cad2[20], cad3[20] =", buenos dias!!!";

    strcpy(cad1, cad0);
    /* La funcion strcpy permite copiar una cadena de caracteres completa. En este
    caso se copia la cadena cad0 a cad1. Si el espacio reservado para cad1 es
}
