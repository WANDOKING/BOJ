#include <iostream>

#define WIDTH 6
#define HEIGHT 6

bool g_board[HEIGHT][WIDTH];

bool IsValidKnightMove(int startX, int startY, int endX, int endY)
{
    bool bMove1 = endX == startX - 1 && endY == startY - 2;
    bool bMove2 = endX == startX + 1 && endY == startY - 2;

    bool bMove3 = endX == startX - 1 && endY == startY + 2;
    bool bMove4 = endX == startX + 1 && endY == startY + 2;

    bool bMove5 = endX == startX + 2 && endY == startY - 1;
    bool bMove6 = endX == startX + 2 && endY == startY + 1;

    bool bMove7 = endX == startX - 2 && endY == startY - 1;
    bool bMove8 = endX == startX - 2 && endY == startY + 1;

    return bMove1 || bMove2 || bMove3 || bMove4 || bMove5 || bMove6 || bMove7 || bMove8;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    const int INPUT_COUNT = 36;

    char prevX;
    char prevY;

    std::cin >> prevX >> prevY;
    prevX -= 'A';
    prevY = 5 - (prevY - '1');
    g_board[prevY][prevX] = true;

    char startX = prevX;
    char startY = prevY;

    bool bResult = true;

    for (int i = 1; i < INPUT_COUNT; ++i)
    {
        char x;
        char y;

        std::cin >> x >> y;

        x -= 'A';
        y = 5 - (y - '1');

        if (IsValidKnightMove(prevX, prevY, x, y) == false)
        {
            bResult = false;
        }

        g_board[y][x] = true;

        prevX = x;
        prevY = y;
    }

    if (IsValidKnightMove(prevX, prevY, startX, startY) == false)
    {
        bResult = false;
    }

    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (g_board[i][j] == false)
            {
                bResult = false;
            }
        }
    }

    if (bResult == false)
    {
        std::cout << "Invalid";
    }
    else
    {
        std::cout << "Valid";
    }
}
