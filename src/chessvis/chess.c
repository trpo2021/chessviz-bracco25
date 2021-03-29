#include <libchessvis/chess_f.h>

int main()
{
    // заполнение доски
    char board[9][9];

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

    display(board);

    char qwer[6];

    FILE* turn;
    turn = fopen("turn.txt", "r");

    while (!feof(turn)) {
        fscanf(turn, "%s", qwer);

        move(board, qwer);
    }

    return 0;
}