#include <libchessviz/chess_f.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char board[9][9];

    create_board(board);
    display(board);

    char qwer[10];

    FILE* turn;
    turn = fopen("bin/turn.txt", "r");

    int check = 1;
    int gr = 1;

    while (!feof(turn)) {
        fscanf(turn, "%s", qwer);

        gr = right_intput(qwer);
        if (gr != 1) {
            return 0;
        }

        check = move(board, qwer);

        if (check != 1) {
            return 0;
        }
        display(board);
    }
    fclose(turn);
    return 0;
}