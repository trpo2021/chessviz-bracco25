#include "chess_f.h"
#include <stdio.h>
#include <stdlib.h>

void display(char array[][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", array[j][i]);
        }
        printf("\n");
    }
}

void move(char board[][9], char* input)
{
    for (int i = 0; i < 5; i++) {
        if ((input[i] >= 97) && (input[i] <= 104)) {
            input[i] = input[i] - 48;
        }
    }
    printf("\n");
    printf("\n");

    int start_x, start_y, end_x, end_y;

    start_x = (int)input[0];
    start_y = (int)input[1];
    end_x = (int)input[3];
    end_y = (int)input[4];

    printf("\n");
    start_x = start_x - 48;
    start_y = start_y - 48 - 1;
    end_x = end_x - 48;
    end_y = end_y - 48 - 1;
    printf("\n");

    if ((start_x >= 8) || (start_y >= 8) || (end_x >= 8) || (end_y >= 8)) {
        printf("неверные значения хода");
        return;
    }

    char tmp;
    if (board[start_x][start_y] != 46) {
        tmp = board[start_x][start_y];
        board[start_x][start_y] = 46;
        board[end_x][end_y] = tmp;
    }

    display(board);
}