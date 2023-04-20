#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "canvas.h"

void freeCanvas(Matrix canvas){
    for(int i = 0; i < canvas.rows; i++){
        free(canvas.values[i]);
    }
    free(canvas.values);
}

char** create_canvas(int rows, int cols){

    char** canvas = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++){
        canvas[i] = (char*)malloc(cols * sizeof(char));
    }
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            canvas[row][col] = '*';
        }
    }

    return canvas;
}


int print_canvas(char** canvas, int rows, int cols){
    for(int row = rows - 1; row >= 0; row--){
        printf("%d ", row);
        for(int col = 0; col < cols; col++){
            printf("%c ", canvas[row][col]);
        }
        printf("\n");
    }
    printf(" ");
    for(int col = 0; col < cols; col++){
        printf(" %d", col);
    }
    printf("\n");
    return 0;
}
