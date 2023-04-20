#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getMatrixInput(int rows, int cols, int matrix[rows][cols], char letter) {
    printf("Enter Matrix %c\n", letter);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }
    return 0;
}

int matrixAdittion(int rows, int cols, int matrixTotal[rows][cols], int matrix1[rows][cols], int matrix2[rows][cols]) {
    printf("A + B = \n");
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            matrixTotal[row][col] = matrix1[row][col] + matrix2[row][col];
            printf("%d ", matrixTotal[row][col]);
        }
        printf("\n");
    }
    return 0;
}

int main(void) {
    int rows, cols;
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);

    int matrixA[rows][cols], matrixB[rows][cols], matrixTotal[rows][cols];

    getMatrixInput(rows, cols, matrixA, 'A');
    getMatrixInput(rows, cols, matrixB, 'B');

    matrixAdittion(rows, cols, matrixTotal, matrixA, matrixB);
}
