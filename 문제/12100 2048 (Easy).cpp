#include <iostream>
#include <cstring>

#define MAX_N 20
#define MAX_DEPTH 5

int g_board[MAX_N][MAX_N];
int g_result = 2;
int N = 0;

void MoveLeft()
{
    for (int i = 0; i < N; ++i)
    {
        int newIndex = 0;
        bool bMerged = false;

        for (int j = 0; j < N; ++j)
        {
            if (g_board[i][j] == 0)
            {
                continue;
            }

            int temp = g_board[i][j];
            g_board[i][j] = 0;

            if (newIndex == 0)
            {
                g_board[i][newIndex] = temp;
                newIndex++;
            }
            else if (!bMerged && g_board[i][newIndex - 1] == temp)
            {
                g_board[i][newIndex - 1] *= 2;
                bMerged = true;
            }
            else
            {
                g_board[i][newIndex] = temp;
                newIndex++;
                bMerged = false;
            }
        }
    }
}

void MoveRight()
{
    for (int i = 0; i < N; ++i)
    {
        int newIndex = N - 1;
        bool bMerged = false;

        for (int j = N - 1; j >= 0; --j)
        {
            if (g_board[i][j] == 0)
            {
                continue;
            }

            int temp = g_board[i][j];
            g_board[i][j] = 0;

            if (newIndex == N - 1)
            {
                g_board[i][newIndex] = temp;
                newIndex--;
            }
            else if (!bMerged && g_board[i][newIndex + 1] == temp)
            {
                g_board[i][newIndex + 1] *= 2;
                bMerged = true;
            }
            else
            {
                g_board[i][newIndex] = temp;
                newIndex--;
                bMerged = false;
            }
        }
    }
}

void MoveUp()
{
    for (int i = 0; i < N; ++i)
    {
        int newIndex = 0;
        bool bMerged = false;

        for (int j = 0; j < N; ++j)
        {
            if (g_board[j][i] == 0)
            {
                continue;
            }

            int temp = g_board[j][i];
            g_board[j][i] = 0;

            if (newIndex == 0)
            {
                g_board[newIndex][i] = temp;
                newIndex++;
            }
            else if (!bMerged && g_board[newIndex - 1][i] == temp)
            {
                g_board[newIndex - 1][i] *= 2;
                bMerged = true;
            }
            else
            {
                g_board[newIndex][i] = temp;
                newIndex++;
                bMerged = false;
            }
        }
    }
}

void MoveDown()
{
    for (int i = 0; i < N; ++i)
    {
        int newIndex = N - 1;
        bool bMerged = false;

        for (int j = N - 1; j >= 0; --j)
        {
            if (g_board[j][i] == 0)
            {
                continue;
            }

            int temp = g_board[j][i];
            g_board[j][i] = 0;

            if (newIndex == N - 1)
            {
                g_board[newIndex][i] = temp;
                newIndex--;
            }
            else if (!bMerged && g_board[newIndex + 1][i] == temp)
            {
                g_board[newIndex + 1][i] *= 2;
                bMerged = true;
            }
            else
            {
                g_board[newIndex][i] = temp;
                newIndex--;
                bMerged = false;
            }
        }
    }
}

int GetMaxBlockSize()
{
    int ret = 2;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (g_board[i][j] > ret)
            {
                ret = g_board[i][j];
            }
        }
    }

    return ret;
}

void BacktackingRecursive(int depth = 0)
{
    if (depth == MAX_DEPTH)
    {
        int maxBlockSize = GetMaxBlockSize();

        if (maxBlockSize > g_result)
        {
            g_result = maxBlockSize;
        }

        return;
    }

    int* backup = (int*)malloc(sizeof(int) * MAX_N * MAX_N);
    memcpy(backup, g_board, sizeof(int) * MAX_N * MAX_N);

    
    MoveLeft();
    BacktackingRecursive(depth + 1);
    memcpy(g_board, backup, sizeof(int) * MAX_N * MAX_N);

    MoveRight();
    BacktackingRecursive(depth + 1);
    memcpy(g_board, backup, sizeof(int) * MAX_N * MAX_N);

    MoveUp();
    BacktackingRecursive(depth + 1);
    memcpy(g_board, backup, sizeof(int) * MAX_N * MAX_N);

    MoveDown();
    BacktackingRecursive(depth + 1);
    memcpy(g_board, backup, sizeof(int) * MAX_N * MAX_N);

    free(backup);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> g_board[i][j];
        }
    }

    BacktackingRecursive();

    std::cout << g_result;
}
