#include <stdio.h>


// void move(char *array, int size, int *a, int* b, int *c, int *d);
int main()
{
    char board[9][9];


    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = 46;
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
        board[i][1] = 112;
        board[i][6] = 80;
    }

    board[1][0] = 114;
    board[8][0] = 114;

    board[1][7] = 114 - 32;
    board[8][7] = 114 - 32;

    board[2][0] = 110;
    board[7][0] = 110;

    board[2][7] = 110 - 32;
    board[7][7] = 110 - 32;

    board[3][0] = 98;
    board[6][0] = 98;

    board[3][7] = 98 - 32;
    board[6][7] = 98 - 32;

    board[4][0] = 113;
    board[5][0] = 107;

    board[4][7] = 113 - 32; 
    board[5][7] = 107 - 32;




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
    
    int a, b, c, d;

    a =(int)input[0];
    b =(int)input[1];
    c =(int)input[3];
    d =(int)input[4];

    printf("\n");
    a = a - 48;
    b = b - 48 - 1;
    c = c - 48;
    d = d - 48 - 1;
    printf("\n");

    if((a >= 8) || (b >= 8 ) || (c >= 8) || (d >= 8))
    {
        printf("неверные значения хода");
        return 0;
    }


    
    
    char tmp;
    if(board[a][b] != 46)
    {
        tmp = board[a][b];
        board[a][b] = 46;
        board[c][d] = tmp;
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


// void move(char *array, int size, int *a, int* b, int *c, int *d)
// {
//     for(int i = 0; i < size; i++)
//     {
//         if((array[i] >= 97) && (array[i] <= 104))
//         {
//             array[i] = array[i] - 48;
//         }
//     }
 
//     // char a, b, c, d;
//     // a = array[0];
//     // b = array[1];
//     // c = array[3];
//     // d = array[4];
//     a =(int)array[0];
//     b =(int)array[1];
//     c =(int)array[3];
//     d =(int)array[4];


//     char tmp;

//     // if(board[b][a] != 46)
//     // {
//     //     tmp = board[b][a];
//     //     board[b][a] = 46;
//     //     board[d][c] = tmp;
//     // }

// }

