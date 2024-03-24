#include <iostream>
#include <cmath>

#define MAX_N 50
#define MAX_M 50

char g_board[MAX_N][MAX_M];

bool IsCorrect(int y, int x, int length)
{
    if (length == 1)
    {
        return true;
    }

    char a = g_board[y][x];
    char b = g_board[y][x + length - 1];
    char c = g_board[y + length - 1][x];
    char d = g_board[y + length - 1][x + length - 1];

    return (a == b) && (b == c) && (c == d);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    int M;

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> g_board[i][j];
        }
    }

    int length = std::min(N, M);

    while (length > 0)
    {
        for (int i = 0; i <= N - length; ++i)
        {
            for (int j = 0; j <= M - length; ++j)
            {
                if (IsCorrect(i, j, length) == true)
                {
                    std::cout << length * length;
                    return 0;
                }
            }
        }
        
        length--;
    }
}
