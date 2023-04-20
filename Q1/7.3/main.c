#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "find_determinant.h"

int main(int argc, char* argv[]){
    FILE* fp = NULL;
    fp = fopen(argv[1], "r");
    Matrix originalMatrix;
    fscanf(fp, "%d", &originalMatrix.rows);
    fscanf(fp, "%d", &originalMatrix.cols);
    originalMatrix.values = makeEmpty2dArray(originalMatrix.rows, originalMatrix.cols);
    for(int row = 0; row < originalMatrix.rows; row++){
        for(int col = 0; col< originalMatrix.cols; col++){
            fscanf(fp, "%lf", &originalMatrix.values[row][col]);
        }
    }
    printf("The determinant is %.2lf.\n", determinant(originalMatrix));
}
