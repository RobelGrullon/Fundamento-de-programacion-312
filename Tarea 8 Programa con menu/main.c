#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void grabarDatos();
void leerArchivo();

int main(void) {
    int opcion;

    do {
        printf("\nMenu:\n");
        printf("0. Salida\n");
        printf("1. Grabar Dato\n");
        printf("3. Leer Archivo\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 0:
                printf("Saliendo del programa...\n");
                break;
            case 1:
                grabarDatos();
                break;
            case 3:
                leerArchivo();
                break;
            default:
                printf("Opcion no valida, por favor intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

void grabarDatos() {
    FILE *archivo;
    alumno *alu;
    int r;

    if ((archivo = fopen("ad1.dat", "ab")) == NULL) {
        printf("\nEl archivo no se puede abrir\n");
        return;
    }

    do {
        alu = (alumno *)malloc(sizeof(alumno));
        if (alu == NULL) {
            printf("No se pudo asignar memoria\n");
            return;
        }

        printf("Matricula del alumno: ");
        scanf("%d", &alu->matricula);
        printf("Nombre del alumno: ");
        scanf("%s", alu->nombre);
        printf("Carrera del alumno: ");
        scanf("%d", &alu->carrera);
        printf("Promedio del alumno: ");
        scanf("%f", &alu->promedio);

        fwrite(alu, sizeof(alumno), 1, archivo);
        free(alu);

        printf("\n¿Desea ingresar informacion sobre mas alumnos? (Si-1 No-0): ");
        scanf("%d", &r);
    } while (r == 1);

    fclose(archivo);
}

void leerArchivo() {
    FILE *archivo;
    alumno *alu;
    int count = 0;

    if ((archivo = fopen("ad1.dat", "rb")) == NULL) {
        printf("\nEl archivo no se puede abrir\n");
        return;
    }

    while (!feof(archivo)) {
        alu = (alumno *)malloc(sizeof(alumno));
        if (alu == NULL) {
            printf("No se pudo asignar memoria\n");
            return;
        }

        if (fread(alu, sizeof(alumno), 1, archivo) == 1) {
            printf("\nAlumno %d:", ++count);
            printf("\nMatricula: %d", alu->matricula);
            printf("\nNombre: %s", alu->nombre);
            printf("\nCarrera: %d", alu->carrera);
            printf("\nPromedio: %.2f\n", alu->promedio);
        }
        free(alu);
    }

    fclose(archivo);
}
