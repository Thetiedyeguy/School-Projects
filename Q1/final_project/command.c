#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "canvas.h"
#include "draw.h"

Matrix addRow(int row, Matrix canvas){
    if(row < 0 || row > canvas.rows){
        printf("Improper add command.\n");
        return canvas;
    }
    Matrix replacement;
    replacement.rows = canvas.rows + 1;
    replacement.cols = canvas.cols;
    replacement.values = create_canvas(replacement.rows, replacement.cols);
    for(int i = canvas.rows; i > row; i--){
        for(int a = 0; a < canvas.cols; a++){
            if(i > 0){
                replacement.values[i][a] = canvas.values[i - 1][a];
            }
        }
    }
    for(int i = 0; i < row; i++){
        for(int a = 0; a < canvas.cols; a++){
            replacement.values[i][a] = canvas.values[i][a];
        }
    }
    freeCanvas(canvas);
    return replacement;
}

Matrix addCol(int col, Matrix canvas){
    if(col < 0 || col > canvas.cols){
        printf("Improper add command.\n");
        return canvas;
    }
    Matrix replacement;
    replacement.rows = canvas.rows;
    replacement.cols = canvas.cols + 1;
    replacement.values = create_canvas(replacement.rows, replacement.cols);
    for(int i = 0; i < canvas.rows; i++){
        for(int a = canvas.cols; a > col; a--){
            if(a > 0){
                replacement.values[i][a] = canvas.values[i][a - 1];
            }
        }
        for(int b = 0; b < col; b++){
            replacement.values[i][b] = canvas.values[i][b];
        }
    }
    freeCanvas(canvas);
    return replacement;
}

Matrix deleteRow(int row, Matrix canvas){
    if(row < 0 || row > canvas.rows - 1){
        printf("Improper delete command.\n");
        return canvas;
    }
    Matrix replacement;
    replacement.rows = canvas.rows - 1;
    replacement.cols = canvas.cols;
    replacement.values = create_canvas(replacement.rows, replacement.cols);
    for(int i = replacement.rows - 1; i >= row; i--){
        for(int a = 0; a < canvas.cols; a++){
            replacement.values[i][a] = canvas.values[i + 1][a];
        }
    }
    for(int i = 0; i < row; i++){
        for(int a = 0; a < canvas.cols; a++){
            replacement.values[i][a] = canvas.values[i][a];
        }
    }
    freeCanvas(canvas);
    return replacement;
}

Matrix deleteCol(int col, Matrix canvas){
    if(col < 0 || col > canvas.cols - 1){
        printf("Improper delete command.\n");
        return canvas;
    }
    Matrix replacement;
    replacement.rows = canvas.rows;
    replacement.cols = canvas.cols - 1;
    replacement.values = create_canvas(replacement.rows, replacement.cols);
    for(int i = 0; i < replacement.rows; i++){
        for(int a = replacement.cols - 1; a >= col; a--){
            replacement.values[i][a] = canvas.values[i][a + 1];
        }
    }
    for(int i = 0; i < replacement.rows; i++){
        for(int a = 0; a < col; a++){
            replacement.values[i][a] = canvas.values[i][a];
        }
    }
    freeCanvas(canvas);
    return replacement;
}

void erase(int row, int col, Matrix canvas){
    if(row < 0 || row > canvas.rows - 1 || col < 0 || col > canvas.cols - 1){
        printf("Improper erase command.\n");
    }else{
        canvas.values[row][col] = '*';
    }
}

void loadFile(char fileName[], Matrix canvas){
    FILE *fp;
    if((fp = fopen(fileName, "r"))){
        char rows[10];
        char cols[10];
        char c;
        for(int i = 0; i < 10; i++){
            c = getc(fp);
            if(c == ' '){
                break;
            }
            rows[i] = c;
        }
        canvas.rows = atoi(rows);
        for(int i = 0; i < 10; i++){
            c = getc(fp);
            if(c == '\n'){
                break;
            }
            cols[i] = c;
        }
        canvas.cols = atoi(cols);
        for(int row = 0; row < canvas.rows; row++){
            for(int col = 0; col < canvas.cols; col++){
                canvas.values[row][col] = getc(fp);
            }
        }
        fclose(fp);
    }else{
        printf("Failed to open file: %s\n", fileName);
    }
}

Matrix resize(int rows, int cols, Matrix canvas){
    int currentRows = canvas.rows;
    int currentCols = canvas.cols;
    if(rows < 1 || cols < 1){
        printf("Improper resize command.\n");
    }else{
        if(currentRows - rows > 0){
            for(int i = rows; i < currentRows; i++){
                canvas = deleteRow(rows, canvas);
            }
        }else if(currentRows - rows < 0){
            for(int i = currentRows; i < rows; i++){
                canvas = addRow(i, canvas);
            }
        }
        if(currentCols - cols > 0){
            for(int i = cols; i < currentCols; i++){
                canvas = deleteCol(cols, canvas);
            }
        }else if(currentCols - cols < 0){
            for(int i = currentCols; i < cols; i++){
                canvas = addCol(i, canvas);
            }
        }
    }
    return canvas;
}

void saveFile(char fileName[], Matrix canvas){
    FILE *fp;
    fp = fopen(fileName, "w");
    if(fp){
        char rows[10];
        char cols[10];
        snprintf(rows, 10, "%d", canvas.rows);
        snprintf(cols, 10, "%d", canvas.cols);
        for(int i = 0; i < strlen(rows); i++){
            fputc(rows[i], fp);
        }
        fputc(' ', fp);
        for(int i = 0; i < strlen(cols); i++){
            fputc(cols[i], fp);
        }
        fputc('\n', fp);
        for(int row = 0; row < canvas.rows; row++){
            for(int col = 0; col < canvas.cols; col++){
                fputc(canvas.values[row][col], fp);
            }
        }
        fclose(fp);
    }else{
        printf("Failed to open file: %s\n", fileName);
    }
}

void write(int startRow, int startCol, int endRow, int endCol, Matrix canvas){
    if(startRow >= 0 && startCol >= 0 && endRow >= 0 && endCol >= 0 && startRow < canvas.rows && endRow < canvas.rows && startCol < canvas.cols && endCol < canvas.cols){
        if(startRow - endRow == 0){
            horizontalLine(startRow, startCol, endCol, canvas);
        }else if(startCol - endCol == 0){
            verticalLine(startCol, startRow, endRow, canvas);
        }else if(startCol - endCol == startRow - endRow || startCol - endCol == -1 * (startRow - endRow)){
            diagonalLine(startRow, endRow, startCol, endCol, canvas);
        }else{
            printf("Cannot draw the line as it is not straight.\n");
        }
    }else{
        printf("Improper draw command.\n");
    }
}

void print_help(){
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

void getCommand(Matrix canvas){
    print_canvas(canvas.values, canvas.rows, canvas.cols);
    char command[10];
    printf("Enter your command: ");
    scanf("%[^\n]%*c", command);
    if(command[0] == 'a'){
        if(command[2] == 'r'){
            char rowString[10];
            memcpy(rowString, &command[4], 9);
            rowString[9] = '\0';
            int row = atoi(rowString);
            if(row == 0 && rowString[0] != '0'){
                printf("Improper add command.\n");
            }else{
                canvas = addRow(row, canvas);
            }
        }else if(command[2] == 'c'){
            char colString[10];
            memcpy(colString, &command[4], 9);
            colString[9] = '\0';
            int col = atoi(colString);
            if(col == 0 && colString[0] != '0'){
                printf("Improper add command.\n");
            }else{
                canvas = addCol(col, canvas);
            }
        }else{
            printf("Improper add command.\n");
        }
    }else if(command[0] == 'd'){
        if(command[2] == 'r'){
            char rowString[10];
            memcpy(rowString, &command[4], 9);
            rowString[9] = '\0';
            int row = atoi(rowString);
            if(row == 0 && rowString[0] != '0'){
                printf("Improper delete command.\n");
            }else{
                canvas = deleteRow(row, canvas);
            }
        }else if(command[2] == 'c'){
            char colString[10];
            memcpy(colString, &command[4], 9);
            colString[9] = '\0';
            int col = atoi(colString);
            if(col == 0 && colString[0] != '0'){
                printf("Improper delete command.\n");
            }else{
                canvas = deleteCol(col, canvas);
            }
        }else{
            printf("Improper delete command.\n");
        }
    }else if(command[0] == 'e'){
        int row, col;
        char rowString[strlen(command)];
        char colString[strlen(command)];
        for(int i = 2; i < strlen(command); i++){
            if(command[i] == ' '){
                memcpy(rowString, &command[2], i - 2);
                rowString[i - 2] = '\0';
                memcpy(colString, &command[i + 1], strlen(command) - (i + 1));
                colString[strlen(command) - (i + 1)] = '\0';
                row = atoi(rowString);
                col = atoi(colString);
                erase(row, col, canvas);
            }
        }
    }else if(command[0] == 'h' && strlen(command) == 1){
        print_help();
    }else if(command[0] == 'l'){
        char fileName[strlen(command) - 2];
        memcpy(fileName, &command[2], strlen(command) - 2);
        fileName[strlen(command) - 2] = '\0';
        loadFile(fileName, canvas);
    }else if(command[0] == 'q' && strlen(command) == 1){
        exit(0);
    }else if(command[0] == 'r'){
        int rows, cols;
        char rowString[strlen(command)];
        char colString[strlen(command)];
        for(int i = 2; i < strlen(command); i++){
            if(command[i] == ' '){
                memcpy(rowString, &command[2], i - 2);
                rowString[i - 2] = '\0';
                memcpy(colString, &command[i + 1], strlen(command) - (i + 1));
                colString[strlen(command) - (i + 1)] = '\0';
                rows = atoi(rowString);
                cols = atoi(colString);
                canvas = resize(rows, cols, canvas);
            }
        }
    }else if(command[0] == 's'){
        char fileName[strlen(command) - 2];
        memcpy(fileName, &command[2], strlen(command) - 2);
        fileName[strlen(command) - 2] = '\0';
        saveFile(fileName, canvas);
    }else if(command[0] == 'w'){
        int numSpaces = 0;
        int previousSpace = 1;
        int startRow, startCol, endRow, endCol;
        int charachters = 0;
        char currentNumber[100];
        for(int i = 2; i < strlen(command); i++){
            charachters++;
            if(command[i] == ' '){
                for(int a = 0; a < charachters; a++){
                    currentNumber[a] = command[a + previousSpace + 1];
                }
                if(numSpaces == 0){
                    startRow = atoi(currentNumber);
                }else if(numSpaces == 1){
                    startCol = atoi(currentNumber);
                }else if(numSpaces == 2){
                    endRow = atoi(currentNumber);
                    previousSpace = i;
                    for(int a = 0; a < charachters; a++){
                        currentNumber[a] = command[a + previousSpace + 1];
                    }
                    endCol = atoi(currentNumber);
                }
                previousSpace = i;
                numSpaces++;
            }
        }
        if(numSpaces >= 3){
            write(startRow, startCol, endRow, endCol, canvas);
        }else{
            printf("Improper draw command.\n");
        }
    }else{
        printf("Unrecognized command. Type h for help.\n");
    }
    getCommand(canvas);
}
