#include <stdio.h>
 /* Suma positivos.
 El programa, al recibir datos N�neros enteros, obtiene la suma de los
 enteros positivos.

 I, N, NUM, SUM: variables de tipo entero. */
 void main(void)
 {
     int I, N, NUM, SUM;
     SUM = 0;
     printf("Ingrese el n�mero de datos:\t");
     scanf("%d", &N) ;
     for (I=1; I<=N; I++)
 {
     printf("Ingrese el dato n�mero %d:}t", I);
     scanf("%d", &NUM);
     if (NUM > 0)
        SUM = SUM + NUM;
 }
  printf ("\nLa suma de los n�meros positivos es: %d", SUM);
  }

