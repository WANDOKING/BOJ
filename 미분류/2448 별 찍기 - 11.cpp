#include <iostream>
#include <cstring>

#define MAX_WIDTH 6143
#define MAX_HEIGHT 3072

char g_board[MAX_HEIGHT][MAX_WIDTH];

// N에 대한 총 그림의 너비를 얻기
int GetWidth(int N)
{
    if (N == 3)
    {
        return 5;
    }

    return GetWidth(N / 2) * 2 + 1;
}

// N에 대한 그림을 g_board에 그린다
void DrawRecursive(int y, int x, int N)
{
    // base case - 가장 작은 삼각형
    if (N == 3)
    {
        g_board[y][x] = '*';
        g_board[y][x + 1] = '*';
        g_board[y][x + 2] = '*';
        g_board[y][x + 3] = '*';
        g_board[y][x + 4] = '*';

        g_board[y - 1][x + 1] = '*';
        g_board[y - 1][x + 3] = '*';

        g_board[y - 2][x + 2] = '*';
        return;
    }

    // recursvie logic
    int smallTriangleWidth = GetWidth(N / 2);
    int smallTriangleHeight = N / 2;

    DrawRecursive(y, x, N / 2);
    DrawRecursive(y, x + smallTriangleWidth + 1, N / 2);
    DrawRecursive(y - smallTriangleHeight, x + smallTriangleWidth / 2 + 1, N / 2);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int width = GetWidth(N);
    int height = N;

    memset(g_board, ' ', MAX_WIDTH * MAX_HEIGHT);

    DrawRecursive(N - 1, 0, N);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            putchar(g_board[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
