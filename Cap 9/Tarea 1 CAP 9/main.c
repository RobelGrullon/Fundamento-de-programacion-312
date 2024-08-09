#include <stdio.h>

 /* Archivo y caracteres.
 El programa escribe caracteres en un archivo. */

void main(void)
{
char p1;
FILE *ar;
ar = fopen("arc.txt", "w");   /* Se abre el archivo arc.txt para escritura. */
if (ar != NULL)
{
    printf("Escriba una cadena de caracteres:\n");
    while  ((p1=getchar()) != '\n')
        /* Se escriben caracteres en el archivo mientras no se detecte el caracter
        que indica el fin de la linea. */
          fputc(p1, ar);
    fclose(ar);                /* Se cierra el archivo. */
}
else
    printf("No se puede abrir el archivo");
}
/*ar es un puntero de euna estructura de tipo */
