#include <libchessviz/chess_f.h>

#include <ctest.h>

CTEST(move, firure)
{
    char board[9][9];
    create_board(board);
    char qwer[6] = {"Pc7-c5"};

    const int result = move(board, qwer);

    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_2)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-c5f"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_1)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-cf"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, chekc_to_figure_1)
{
    char board[9][9];
    create_board(board);
    char figure = 'b';
    int start_x = 5;
    int start_y = 7;

    const int result = chekc_to_figure(board, figure, start_x, start_y);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, figure_3)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"P47-c5"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, chekc_to_figure_2)
{
    char board[9][9];
    create_board(board);
    char figure = 'b';
    int start_x = 2;
    int start_y = 1;

    const int result = chekc_to_figure(board, figure, start_x, start_y);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, end_1)
{
    char board[9][9];
    create_board(board);
    char moving = '-';
    int end_x = 2;
    int end_y = 6;

    const int result = chekc_to_moving(board, moving, end_x, end_y);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, end_2)
{
    char board[9][9];
    create_board(board);
    char moving = '-';
    int end_x = 9;
    int end_y = 6;

    const int result = chekc_to_moving(board, moving, end_x, end_y);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn)
{
    char board[9][9];
    create_board(board);

    char moving = 'x';

    const int result = chekc_to_moving(board, moving, 5, 3);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn_2)
{
    char board[9][9];
    create_board(board);

    char moving = '-';

    const int result = chekc_to_moving(board, moving, 5, 6);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn_3)
{
    char board[9][9];
    create_board(board);

    char moving = 'x';

    const int result = chekc_to_moving(board, moving, 6, 3);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, figure_4)
{
    char board[9][9];
    create_board(board);

    const int result = chekc_to_figure(board, 'P', 1, 1);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_3)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc6-c5"};

    const int result = right_intput(qwer);

    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_4)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7&c5"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_5)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7(c5"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_6)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7*c5"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_7)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-y5"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_8)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-c   5"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_9)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc 7-c5"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_10)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-c5f"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_11)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-c5wer"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_12)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-c5t"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, right_name_1)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"pc7-c5"};

    const int result = right_intput(qwer);

    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, right_name_2)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc7-c5"};

    const int result = right_intput(qwer);

    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input, error_name_13)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc9-c9"};

    const int result = right_intput(qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}