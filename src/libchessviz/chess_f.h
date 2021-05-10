#pragma once

void display(char array[][9]);
int move(char board[][9], char input[]);
void create_board(char board[][9]);
void translate_to_digit(char* input);
int check_to_right_move(int start_x, int start_y, int end_x, int end_y);
int chekc_to_figure(char board[][9], char figure, int start_x, int start_y);
int all_check(
        char board[][9],
        char* input,
        int start_x,
        int start_y,
        int end_x,
        int end_y);
int chekc_to_moving(char board[][9], char moving, int end_x, int end_y);
int found_king(char board[][9]);
int right_intput(char* input);