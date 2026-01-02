#include <stdio.h>
#include <stdlib.h>

/* -------- suma de dígitos -------- */
int sumaDigito(int a) {
    if (a == 0)
        return 0;
    return (a % 10) + sumaDigito(a / 10);
}

/* -------- reservar matriz -------- */
int **crearMatriz(int nfilas, int ncolumnas) {
    int **matriz = (int **)malloc(nfilas * sizeof(int*));
    for (int i = 0; i < nfilas; i++) {
        matriz[i] = (int *)malloc(ncolumnas * sizeof(int));
    }
    return matriz;
}

/* -------- ingresar datos -------- */
void ingresarMatriz(int **matriz, int nfilas, int ncolumnas) {
    for (int i = 0; i < nfilas; i++) {
        for (int j = 0; j < ncolumnas; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

/* -------- mostrar matriz -------- */
void mostrarMatriz(int **matriz, int nfilas, int ncolumnas) {
    for (int i = 0; i < nfilas; i++) {
        for (int j = 0; j < ncolumnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

/* -------- matriz cifrada -------- */
int **matrizcifrada(int **matriz, int nfilas, int ncolumnas) {
    int **nueva = crearMatriz(nfilas, ncolumnas);

    for (int i = 0; i < nfilas; i++) {
        for (int j = 0; j < ncolumnas; j++) {
            nueva[i][j] = sumaDigito(matriz[i][j]);
        }
    }
    return nueva;
}

/* -------- liberar memoria -------- */
void liberarMatriz(int **matriz, int nfilas) {
    for (int i = 0; i < nfilas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

/* -------- main -------- */
int main() {
    int nfilas, ncolumnas;

    printf("Ingrese numero de filas: ");
    scanf("%d", &nfilas);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &ncolumnas);

    int **matriz = crearMatriz(nfilas, ncolumnas);
    ingresarMatriz(matriz, nfilas, ncolumnas);

    printf("\nMATRIZ ORIGINAL:\n");
    mostrarMatriz(matriz, nfilas, ncolumnas);

    int **cifrada = matrizcifrada(matriz, nfilas, ncolumnas);

    printf("\nMATRIZ CIFRADA (suma de digitos):\n");
    mostrarMatriz(cifrada, nfilas, ncolumnas);

    liberarMatriz(matriz, nfilas);
    liberarMatriz(cifrada, nfilas);

    return 0;
}
