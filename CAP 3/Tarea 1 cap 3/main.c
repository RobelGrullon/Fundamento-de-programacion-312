#include <stdio.h>
#include <stdlib.h>

/* N�nima
El programa, al recibir los salarios de 15 profesores, obtiene el total de la
n�mina de la universidad

I: variable de tipo entero.
SAL y NOM: variables de tipo real. */

void main(void)
{
    int I;
    float SAL, NOM;
    NOM = 0;
    for (I=1; I<=15; I++)
{
    printf("/Ingrese el salario del profesor%d:\t", I);
    scanf("%f", &SAL);
    NOM = NOM + SAL;
}
printf("\nEl total de la n�mina es: %.2f", NOM);
}
