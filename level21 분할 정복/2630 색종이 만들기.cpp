#include <iostream>
#define MAX 128

using namespace std;

int g_board[MAX][MAX];

// (x, y) 위치에서 width길이의 정사각형이 color색인지
bool IsColoredSquareRecursive(int x, int y, int width, int color)
{
    if (width == 1)
    {
        return g_board[y][x] == color;
    }

    bool bIsColoredSquare1 = IsColoredSquareRecursive(x + width / 2, y, width / 2, color);
    bool bIsColoredSquare2 = IsColoredSquareRecursive(x, y, width / 2, color);
    bool bIsColoredSquare3 = IsColoredSquareRecursive(x, y + width / 2, width / 2, color);
    bool bIsColoredSquare4 = IsColoredSquareRecursive(x + width / 2, y + width / 2, width / 2, color);

    return bIsColoredSquare1 && bIsColoredSquare2 && bIsColoredSquare3 && bIsColoredSquare4;
}

int countColoredSquareRecursive(int x, int y, int width, int color)
{
    if (IsColoredSquareRecursive(x, y, width, color) == true)
    {
        return 1;
    }

    if (width == 1)
    {
        if (g_board[y][x] == color)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int count = 0;
    count += countColoredSquareRecursive(x + width / 2, y, width / 2, color);
    count += countColoredSquareRecursive(x, y, width / 2, color);
    count += countColoredSquareRecursive(x, y + width / 2, width / 2, color);
    count += countColoredSquareRecursive(x + width / 2, y + width / 2, width / 2, color);

    return count;
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> g_board[i][j];
        }
    }

    int whiteCount = countColoredSquareRecursive(0, 0, N, 0);
    int blueCount = countColoredSquareRecursive(0, 0, N, 1);
    
    cout << whiteCount << '\n';
    cout << blueCount << '\n';
}
