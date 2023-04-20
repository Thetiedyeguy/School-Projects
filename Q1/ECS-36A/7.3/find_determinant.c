#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "find_determinant.h"



double** makeEmpty2dArray(int rows, int cols){
    double** values = (double**)malloc(rows * sizeof(double*));
    for(int i = 0; i < rows; i++){
        values[i] = (double*)malloc(cols * sizeof(double));
    }
    return values;
}


double determinant(Matrix originalMatrix){
    if(originalMatrix.rows > 2){
        Matrix newMatrix;
        double solution = 0;
        bool isPositive = true;
        newMatrix.rows = originalMatrix.rows - 1;
        newMatrix.cols = originalMatrix.cols - 1;
        newMatrix.values = makeEmpty2dArray(newMatrix.rows, newMatrix.cols);
        for(int matrixes = 0; matrixes < originalMatrix.cols; matrixes++){
            for(int rows = 1; rows < originalMatrix.rows; rows++){
                int col = 0;
                for(int cols = 0; cols < originalMatrix.cols; cols++){
                    if(cols != matrixes){
                        newMatrix.values[rows - 1][col] = originalMatrix.values[rows][cols];
                        col++;
                    }
                }
            }
            if(isPositive){
                solution += originalMatrix.values[0][matrixes] * determinant(newMatrix);
            }else{
                solution -= originalMatrix.values[0][matrixes] * determinant(newMatrix);
            }
            isPositive = !isPositive;
        }
        return solution;
    }else{
        return (originalMatrix.values[0][0] * originalMatrix.values[1][1]) - (originalMatrix.values[0][1] * originalMatrix.values[1][0]);
    }
}
