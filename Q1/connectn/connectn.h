#ifndef CONNECTN_H
#define CONNECTN_H

bool input_validation(int argc, char* argv);
char** create_board(int rows, int cols);
int print_board(char** board, int rows, int cols);
int update_current_player(char* current_player);
int get_empty_slot(char** board, int play, int rows);
bool play_is_valid(char** board, int play, int rows, int cols);
int get_play(char** board, int rows, int cols, char* current_player);
bool game_won(char winner);
char row_win(char** board, int rows, int cols, int win_amt);
char col_win(char** board, int rows, int cols, int win_amt);
char right_diag_win(char** board, int rows, int cols, int win_amt);
int left_diag_win(char** board, int rows, int cols, int win_amt);
bool game_over(char** board, int rows, int cols, int win_amt);
int play_game(char** board, int rows, int cols, char* current_player, int win_amt);
int get_number_input();

#endif
