#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "connectn.h"


bool input_validation(int argc, char* argv) {
    bool isNumber;
    char numbers[] = "1234567890";
    for(int a = 0; a < strlen(argv); a++){
        isNumber = false;
        for(int b = 0; b < 10; b++){
            if(argv[a] == numbers[b]){
                isNumber = true;
            }
        }
        if(!isNumber){
            return false;
        }
    }
    return true;
}

char** create_board(int rows, int cols){

    char** board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++){
        board[i] = (char*)malloc(cols * sizeof(char));
    }
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            board[row][col] = '*';
        }
    }

    return board;
}

int print_board(char** board, int rows, int cols){
    for(int row = rows - 1; row >= 0; row--){
        printf("%d ", row);
        for(int col = 0; col < cols; col++){
            printf("%c ", board[row][col]);
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

int update_current_player(char* current_player){
    if(*current_player == 'X'){
        *current_player = 'O';
    }else{
        *current_player = 'X';
    }
    return 0;
}

int get_empty_slot(char** board, int play, int rows){
    for(int i = 0; i < rows; i++){
        if(board[i][play] == '*'){
            return i;
        }
    }
    return -1;
}

bool play_is_valid(char** board, int play, int rows, int cols){
    if(play >= 0 && play <= cols && get_empty_slot(board, play, rows) != -1){
        return true;
    }
    return false;
}

int get_play(char** board, int rows, int cols, char* current_player){
    char input[1000];
    int play;
    printf("Enter a column between 0 and %d to play in: ", cols - 1);
    scanf("%s", input);
    if(input_validation(1, input)){
        play = atoi(input);
        if(play_is_valid(board, play, rows, cols)){
            board[get_empty_slot(board, play, rows)][play] = *current_player;
            update_current_player(current_player);
            print_board(board, rows, cols);
        }
    }
    return 0;
}

bool game_won(char winner){
    if(winner == 'X'){
        printf("Player 1 Won!\n");
        exit(1);
    }else if(winner == 'O'){
        printf("Player 2 Won!\n");
        exit(1);
    }
    return true;
}

char row_win(char** board, int rows, int cols, int win_amt){
    char placeholder = '*';
    bool won;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(col + win_amt <= cols){
                placeholder = board[row][col];
                if(placeholder != '*'){
                    won = true;
                    for(int i = 0; i < win_amt; i++){
                        if(board[row][col + i] != placeholder){
                            won = false;
                        }
                    }
                    if(won){
                        game_won(placeholder);
                    }
                }
            }
        }
    }
    return '*';
}

char col_win(char** board, int rows, int cols, int win_amt){
    char placeholder = '*';
    bool won;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(row + win_amt <= rows){
                placeholder = board[row][col];
                if(placeholder != '*'){
                    won = true;
                    for(int i = 0; i < win_amt; i++){
                        if(board[row + i][col] != placeholder){
                            won = false;
                        }
                    }
                    if(won){
                        game_won(placeholder);
                    }
                }
            }
        }
    }
    return '*';
}

char right_diag_win(char** board, int rows, int cols, int win_amt){
    char placeholder = '*';
    bool won;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(row + win_amt <= rows && col + win_amt <= cols){
                placeholder = board[row][col];
                if(placeholder != '*'){
                    won = true;
                    for(int i = 0; i < win_amt; i++){
                        if(board[row + i][col + i] != placeholder){
                            won = false;
                        }
                    }
                    if(won){
                        game_won(placeholder);
                    }
                }
            }
        }
    }
    return '*';
}

int left_diag_win(char** board, int rows, int cols, int win_amt){
    char placeholder = '*';
    bool won;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(row + win_amt <= rows && col - win_amt <= cols){
                placeholder = board[row][col];
                if(placeholder != '*'){
                    won = true;
                    for(int i = 0; i < win_amt; i++){
                        if(board[row + i][col - i] != placeholder){
                            won = false;
                        }
                    }
                    if(won){
                        game_won(placeholder);
                    }
                }
            }
        }
    }
    return '*';
}


bool game_over(char** board, int rows, int cols, int win_amt){
    bool isTie = true;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(board[row][col] == '*'){
                isTie = false;
            }
        }
    }
    if(isTie){
        printf("Tie game!");
        return false;
    }else{
        row_win(board, rows, cols, win_amt);
        col_win(board, rows, cols, win_amt);
        right_diag_win(board, rows, cols, win_amt);
        left_diag_win(board, rows, cols, win_amt);
    }
    return true;
}

int play_game(char** board, int rows, int cols, char* current_player, int win_amt){
    bool game_in_session = true;
    while(game_in_session){
        get_play(board, rows, cols, current_player);
        game_in_session = game_over(board, rows, cols, win_amt);
    }
    return 0;
}
