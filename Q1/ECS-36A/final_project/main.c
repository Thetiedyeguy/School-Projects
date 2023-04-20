#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "canvas.h"
#include "command.h"

int input_validation(int argc, char* argv[], int* rows, int* cols) {
    bool isNumber;
    char numbers[] = "1234567890-";
    if(argc == 1){
        *rows = 10;
        *cols = 10;
    }else if(argc != 3){
        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        *rows = 10;
        *cols = 10;
        return 0;
    }else{
        for(int i = 1; i < 3; i++){
            for(int a = 0; a < strlen(argv[i]); a++){
                isNumber = false;
                for(int b = 0; b < 11; b++){
                    if(argv[i][a] == numbers[b]){
                        isNumber = true;
                    }
                }
                if(!isNumber){
                    if(i == 1){
                        printf("The number of rows is not an integer.\n");
                        printf("Making default board of 10 X 10.\n");
                        *rows = 10;
                        *cols = 10;
                        return 0;
                    }else{
                        printf("The number of columns is not an integer.\n");
                        printf("Making default board of 10 X 10.\n");
                        *rows = 10;
                        *cols = 10;
                        return 0;
                    }
                }
            }
        }
        *rows = atoi(argv[1]);
        *cols = atoi(argv[2]);
        if(*rows < 1){
            printf("The number of rows is less than 1.\n");
            printf("Making default board of 10 X 10.\n");
            *rows = 10;
            *cols = 10;
        }
        if(*cols < 1){
            printf("The number of columns is less than 1.\n");
            printf("Making default board of 10 X 10.\n");
            *rows = 10;
            *cols = 10;
        }
    }
    return 0;
}

int main(int argc, char* argv[]){
    Matrix canvas;
    input_validation(argc, argv, &canvas.rows, &canvas.cols);
    canvas.values = create_canvas(canvas.rows, canvas.cols);
    getCommand(canvas);
    freeCanvas(canvas);
}
