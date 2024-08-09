#include <stdio.h>

#define FIBONACCI_COUNT 50

void generate_fibonacci(int fib[], int count) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < count; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void write_to_file(int fib[], int count) {
    FILE *file = fopen("fibonacci.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    /* Escribe todos los numeros de fibonacci */
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d", fib[i]);
        if (i < count - 1) {
            fprintf(file, "-");
        }
    }
    fprintf(file, "\n");

    // Escribir números impares de Fibonacci
    int odd_sum = 0;
    int first_odd = 1; /* Para manejar el primer elemento sin guión */
    for (int i = 0; i < count; i++) {
        if (fib[i] % 2 != 0) {
            if (!first_odd) {
                fprintf(file, "-");
            }
            fprintf(file, "%d", fib[i]);
            odd_sum += fib[i];
            first_odd = 0;
        }
    }
    fprintf(file, "\n");

    // Escribe numeros pares de Fibonacci
    int even_sum = 0;
    int first_even = 1; /* Para manejar el primer elemento sin guion */
    for (int i = 0; i < count; i++) {
        if (fib[i] % 2 == 0) {
            if (!first_even) {
                fprintf(file, "-");
            }
            fprintf(file, "%d", fib[i]);
            even_sum += fib[i];
            first_even = 0;
        }
    }
    fprintf(file, "\n");

    // Escribir las sumas de números pares e impares.
    fprintf(file, "Suma de los numeros impares: %d\n", odd_sum);
    fprintf(file, "Suma de los numeros pares: %d\n", even_sum);

    fclose(file);
}

int main() {
    int fib[FIBONACCI_COUNT];
    generate_fibonacci(fib, FIBONACCI_COUNT);
    write_to_file(fib, FIBONACCI_COUNT);
    return 0;
}

