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

CTEST(move, figure_2)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"vc7-cf"};

    const int result = move(board, qwer);

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

CTEST(move, start_1)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc5-c5"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, start_2)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pc2-c4"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, end_1)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"pc2-c9"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, end_2)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"pc2-v4"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, figure_4)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"kc2-c4"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"pc2xc4"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn_2)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"pc2-c7"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn_3)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"pc2-c9"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn_4)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pe5-c5"};

    const int result = move(board, qwer);

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

CTEST(move, turn_5)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pe5Xc5"};

    const int result = move(board, qwer);

    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(move, turn_6)
{
    char board[9][9];
    create_board(board);
    char qwer[10] = {"Pe5-c5"};

    const int result = move(board, qwer);

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