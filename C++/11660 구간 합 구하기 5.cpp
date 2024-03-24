#include <iostream>

#define MAX_N 1025
int g_nums[MAX_N][MAX_N];
int g_sumsPerLines[MAX_N][MAX_N];
int g_sumsDiagonally[MAX_N][MAX_N];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    // input
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            std::cin >> g_nums[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= N; ++j)
        {
            sum += g_nums[i][j];
            g_sumsPerLines[i][j] = sum;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            g_sumsDiagonally[i][j] = g_sumsDiagonally[i - 1][j] + g_sumsPerLines[i][j];
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int x1;
        int y1;
        int x2;
        int y2;

        std::cin >> x1 >> y1 >> x2 >> y2;

        int area1 = g_sumsDiagonally[x2][y2];
        int area2 = g_sumsDiagonally[x2][y1 - 1];
        int area3 = g_sumsDiagonally[x1 - 1][y2];
        int area4 = g_sumsDiagonally[x1 - 1][y1 - 1];

        int result = area1 - area2 - area3 + area4;
        std::cout << result << '\n';
    }
}
