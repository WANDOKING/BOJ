#include <iostream>

#define MAX_N 100000

char g_board[MAX_N][3];
int g_dpMin[2][3];
int g_dpMax[2][3];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int num;
            std::cin >> num;

            g_board[i][j] = num;
        }
    }

    g_dpMin[0][0] = g_board[0][0];
    g_dpMin[0][1] = g_board[0][1];
    g_dpMin[0][2] = g_board[0][2];

    g_dpMax[0][0] = g_board[0][0];
    g_dpMax[0][1] = g_board[0][1];
    g_dpMax[0][2] = g_board[0][2];

    for (int i = 1; i < N; ++i)
    {
        g_dpMin[1][0] = std::min(g_dpMin[0][0], g_dpMin[0][1]);
        g_dpMin[1][0] += g_board[i][0];

        g_dpMin[1][1] = std::min(g_dpMin[0][0], std::min(g_dpMin[0][1], g_dpMin[0][2]));
        g_dpMin[1][1] += g_board[i][1];

        g_dpMin[1][2] = std::min(g_dpMin[0][1], g_dpMin[0][2]);
        g_dpMin[1][2] += g_board[i][2];

        g_dpMax[1][0] = std::max(g_dpMax[0][0], g_dpMax[0][1]);
        g_dpMax[1][0] += g_board[i][0];

        g_dpMax[1][1] = std::max(g_dpMax[0][0], std::max(g_dpMax[0][1], g_dpMax[0][2]));
        g_dpMax[1][1] += g_board[i][1];

        g_dpMax[1][2] = std::max(g_dpMax[0][1], g_dpMax[0][2]);
        g_dpMax[1][2] += g_board[i][2];

        g_dpMin[0][0] = g_dpMin[1][0];
        g_dpMin[0][1] = g_dpMin[1][1];
        g_dpMin[0][2] = g_dpMin[1][2];

        g_dpMax[0][0] = g_dpMax[1][0];
        g_dpMax[0][1] = g_dpMax[1][1];
        g_dpMax[0][2] = g_dpMax[1][2];
    }

    int minResult = std::min(g_dpMin[0][0], std::min(g_dpMin[0][1], g_dpMin[0][2]));
    int maxResult = std::max(g_dpMax[0][0], std::max(g_dpMax[0][1], g_dpMax[0][2]));

    std::cout << maxResult << ' ' << minResult;
}
