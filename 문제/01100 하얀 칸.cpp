#include <iostream>

int main(void)
{
    constexpr int BOARD_SIZE = 8;
    constexpr char HORSE = 'F';

    char board[BOARD_SIZE][BOARD_SIZE];

    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            std::cin >> board[row][col];
        }
    }

    int horseCount = 0;

    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = row % 2; col < BOARD_SIZE; col += 2)
        {
            if (board[row][col] == HORSE)
            {
                ++horseCount;
            }
        }
    }

    std::cout << horseCount;
}
