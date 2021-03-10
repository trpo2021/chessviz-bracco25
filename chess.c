#include <stdio.h>


int main()
{
    char board[9][9];


    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = '.';
        }
    }

    for (int i =0; i < 9; i++)
    {
        board[1+i][8] = 97+i;
    }
    
    for (int i =0; i < 8; i++)
    {
        board[0][0+i] = 49+i;
    }

    for (int i =1; i < 9; i++)
    {
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




    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%c ", board[j][i]);
        }
        printf("\n");
    }
    char input[5];
    FILE* turn;
    turn = fopen("turn.txt", "r");

     for(int i = 0; i < 5;i++)
    {
        fscanf(turn,"%c",&input[i]);        
    }
    fclose(turn);
    
    for(int i = 0; i < 5; i++)
    {
        if((input[i] >= 97) && (input[i] <= 104))
        {
            input[i] = input[i] - 48;
        }
    }
    printf("\n");
    printf("\n");
    
    int start_x, start_y, end_x, end_y;

    start_x =(int)input[0];
    start_y =(int)input[1];
    end_x =(int)input[3];
    end_y =(int)input[4];

    printf("\n");
    start_x = start_x - 48;
    start_y = start_y - 48 - 1;
    end_x = end_x - 48;
    end_y = end_y - 48 - 1;
    printf("\n");

    if((start_x >= 8) || (start_y >= 8 ) || (end_x >= 8) || (end_y >= 8))
    {
        printf("неверные значения хода");
        return 0;
    }


    
    
    char tmp;
    if(board[start_x][start_y] != 46)
    {
        tmp = board[start_x][start_y];
        board[start_x][start_y] = 46;
        board[end_x][end_y] = tmp;
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%c ", board[j][i]);
        }
        printf("\n");
    }

    return 0;
}
