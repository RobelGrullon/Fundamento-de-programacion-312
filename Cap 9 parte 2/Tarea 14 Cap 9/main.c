#include <stdio.h>
#include <ctype.h>

/* Letras minusculas y mayusculas
El programa, al r ecibir como dato un archivo formado por cadenas de caracteres,
determina el numero de letras minusculas y mayusculas que hay en el archivo. */

void minymay(FILE *);               /* Prototipo de función. */
/* Observa que esta función va a recibir un archivo como parámetro. */

void main(void)
{
char p;
FILE *ar;
if ((ar = fopen("arc5.txt", "r")) != NULL)
{
   minymay(ar);
  /* Se llama a la funcion minymay. Se pasa el archivo ar como parametro. */
  fclose(ar);
}
else
    printf("No se pudo abrir el archivo");
}
void minymay(FILE *arc)
/* Esta funcion cuenta el numero de minusculas y mayusculas que hay en el
archivo arc. */
{
int min = 0, may = 0;
char p;
while (!feof(arc))
{
p = fgetc(arc);    /* Se utiliza la funcion fgetc() para leer caracteres
                   del archivo. */
if (islower(p))
min++;
else
    if (isupper(p))
    may++;
}
printf("\nNumero de minusculas: %d", min);
printf("\nNumero de mayusculas: %d", may);
}
