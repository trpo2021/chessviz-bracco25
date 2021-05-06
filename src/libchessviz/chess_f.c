#include "chess_f.h"
#include <stdio.h>
#include <stdlib.h>

int right_intput(char* input)
{
    char save[10];
    for (int i = 0; i < 10; i++) {
        save[i] = input[i];
    }

    if (!(save[0] == 'p' || save[0] == 'P' || save[0] == 'R' || save[0] == 'r'
          || save[0] == 'n' || save[0] == 'N' || save[0] == 'B'
          || save[0] == 'b' || save[0] == 'q' || save[0] == 'Q'
          || save[0] == 'K' || save[0] == 'k')) {
        return 0;
    }

    if (!(save[1] >= 'a' && save[1] <= 'h')) {
        return 0;
    }

    if (!(save[2] >= '1' && save[2] < '9')) {
        return 0;
    }

    if ((save[3] != '-' && save[3] != 'x')) {
        return 0;
    }

    if (!(save[4] >= 'a' && save[4] <= 'h')) {
        return 0;
    }

    if (!(save[5] >= '1' && save[5] < '9')) {
        return 0;
    }

    if ((save[6] >= '0' && save[6] < '9') || (save[6] >= 'A' && save[6] <= 'Z')
        || (save[6] >= 'a' && save[6] <= 'z')) {
        return 0;
    }

    return 1;
}

void create_board(char board[][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = '.';
        }
    }

    for (int i = 0; i < 8; i++) {
        board[1 + i][8] = 97 + i;
    }

    for (int i = 0; i < 8; i++) {
        board[0][0 + i] = 49 + i;
    }

    for (int i = 1; i < 9; i++) {
        board[i][1] = 'p';
        board[i][6] = 'P';
    }

    board[1][0] = 'r';
    board[8][0] = 'r';

    board[1][7] = 'R';
    board[8][7] = 'R';

    board[2][0] = 'n';
    board[7][0] = 'n';

    board[2][7] = 'N';
    board[7][7] = 'N';

    board[3][0] = 'b';
    board[6][0] = 'b';

    board[3][7] = 'B';
    board[6][7] = 'B';

    board[4][0] = 'q';
    board[5][0] = 'k';

    board[4][7] = 'Q';
    board[5][7] = 'K';
}

void display(char array[][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", array[j][i]);
        }
        printf("\n");
    }
}

void translate_to_digit(char* input)
{
    for (int i = 0; i < 5; i++) { // перевод массива в числа - теперь будем
        // смотреть на фигуры по ASCI-коду
        if ((input[i] >= 97) && (input[i] <= 104)) {
            input[i] = input[i] - 48;
        }
    }
}

int move(char board[][9], char* input)
{
    translate_to_digit(input);

    int start_x, start_y, end_x, end_y;

    start_x = (int)input[1];
    start_y = (int)input[2];
    end_x = (int)input[4];
    end_y = (int)input[5];

    start_x = start_x - 48; //перевод в координаты доски
    start_y = start_y - 48 - 1;
    end_x = end_x - 48;
    end_y = end_y - 48 - 1;
    printf("\n");

    int check = 0;
    check = all_check(board, input, start_x, start_y, end_x, end_y);
    if (check != 1) {
        return 0;
    }

    char tmp;
    if (board[start_x][start_y] != 46) {
        tmp = board[start_x][start_y];
        board[start_x][start_y] = 46;
        board[end_x][end_y] = tmp;
    }

    int end = 0;
    end = found_king(board);

    if (end == 0) {
        return 1;
    } else {
        return 0;
    }
}

int all_check(
        char board[][9],
        char* input,
        int start_x,
        int start_y,
        int end_x,
        int end_y)
{
    int result = 1;

    char figure = input[0];
    if (figure == '2') {
        figure = 'b';
    }

    char moving = input[3];

    result = chekc_to_figure(board, figure, start_x, start_y);
    if (result != 1) {
        printf("ERROR: неверно выбранная фигура\n");
        return 0;
    }
    result = check_to_right_move(start_x, start_y, end_x, end_y);
    if (result != 1) {
        printf("ERROR: неверный ход (выход за доску)\n");
        return 0;
    }
    result = chekc_to_moving(board, moving, end_x, end_y);

    if (result != 1) {
        printf("неверные значения хода. неверный тип хода");
        return 0;
    }

    return result;
}

int chekc_to_figure(char board[][9], char figure, int start_x, int start_y)
{
    if (figure == board[start_x][start_y]) {
        return 1;
    } else {
        return 0;
    }
}

int check_to_right_move(int start_x, int start_y, int end_x, int end_y)
{
    if ((start_x > 8) || (start_y > 8) || (end_x > 8) || (end_y > 8)) {
        return 0;
    } else {
        return 1;
    }
}

int chekc_to_moving(char board[][9], char moving, int end_x, int end_y)
{
    if (moving == '-') {
        if (board[end_x][end_y] == '.') {
            return 1;
        } else {
            return 0;
        }
    }

    if (moving == 'x') {
        if (board[end_x][end_y] != '.') {
            return 1;
        } else {
            return 0;
        }
    }

    return 0;
}

int found_king(char board[][9])
{
    int found_K = 0;
    int found_k = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 'k') {
                found_k = 1;
            }

            if (board[i][j] == 'K') {
                found_K = 1;
            }
        }
    }

    if (found_k == 0) {
        printf("ИГРА ОКОНЧЕНА \n победил нижний игрок!!!\n");
        return 1;
    }

    if (found_K == 0) {
        printf("ИГРА ОКОНЧЕНА \n победил верхний игрок!!!\n");
        return 1;
    }

    return 0;
}