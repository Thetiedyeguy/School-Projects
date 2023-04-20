#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "connectn.h"

void initial_input_validation(int argc, char* argv[]){
    if(argc < 4){
        printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    if(argc > 4){
        printf("Too many arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    for(int i = 1; i < argc; i++){
        if(!input_validation(argc, argv[i])){
            printf("Invalid input\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
            exit(0);
        }
    }
}

int main(int argc, char* argv[]){
    int rows, cols, win_amt;
    initial_input_validation(argc, argv);
    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    win_amt = atoi(argv[3]);
    char** board;
    char current_player = 'X';
    board = create_board(rows, cols);
    print_board(board, rows, cols);
    play_game(board, rows, cols, &current_player, win_amt);
}
