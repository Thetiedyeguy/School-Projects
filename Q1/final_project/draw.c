#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "canvas.h"
#include "command.h"

void horizontalLine(int row, int startCol, int endCol, Matrix canvas){
    if(endCol < startCol){
        int temporary = endCol;
        endCol = startCol;
        startCol = temporary;
    }
    for(int i = startCol; i <= endCol; i++){
        if(canvas.values[row][i] == '*' || canvas.values[row][i] == '-'){
            canvas.values[row][i] = '-';
        }else{
            canvas.values[row][i] = '+';
        }
    }
}

void verticalLine(int col, int startRow, int endRow, Matrix canvas){
    if(endRow < startRow){
        int temporary = endRow;
        endRow = startRow;
        startRow = temporary;
    }
    for(int i = startRow; i <= endRow; i++){
        if(canvas.values[i][col] == '*' || canvas.values[i][col] == '|'){
            canvas.values[i][col] = '|';
        }else{
            canvas.values[i][col] = '+';
        }
    }
}

void diagonalLine(int startRow, int endRow, int startCol, int endCol, Matrix canvas){
    int length;
    if(startRow - endRow > 0){
        length = startRow - endRow;
    }else{
        length = endRow - startRow;
    }
    char line;
    int rowMultiplier, colMultiplier;
    if((startRow > endRow && startCol < endCol) || (startRow < endRow && startCol > endCol)){
        line = '\\';
    }else{
        line = '/';
    }
    if(startRow > endRow){
        rowMultiplier = -1;
    }else{
        rowMultiplier = 1;
    }
    if(startCol > endCol){
        colMultiplier = -1;
    }else{
        colMultiplier = 1;
    }
    for(int i = 0; i <= length; i++){
        if(canvas.values[startRow + (i * rowMultiplier)][startCol + (i * colMultiplier)] == '*' || canvas.values[startRow + (i * rowMultiplier)][startCol + (i * colMultiplier)] == line){
            canvas.values[startRow + (i * rowMultiplier)][startCol + (i * colMultiplier)] = line;
        }else{
            canvas.values[startRow + (i * rowMultiplier)][startCol + (i * colMultiplier)] = '+';
        }
    }
}
