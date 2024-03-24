#include <iostream>
#include <algorithm>

#define MAX_N 8

int g_nums[MAX_N];
int g_N;
int g_M;

int backtrackingNums[MAX_N];

void BacktrackingRecursive(int depth = 0)
{
    // print
    if (depth == g_M)
    {
        for (int i = 0; i < g_M; i++)
        {
            printf("%d ", backtrackingNums[i]);
        }
        putchar('\n');
        return;
    }

    int prevNum = 0;
    if (depth > 0)
    {
        prevNum = backtrackingNums[depth - 1];
    }

    for (int i = 0; i < g_N; i++)
    {
        if (g_nums[i] < prevNum)
        {
            continue;
        }

        backtrackingNums[depth] = g_nums[i];
        BacktrackingRecursive(depth + 1);
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> g_N >> g_M;

    for (int i = 0; i < g_N; i++)
    {
        std::cin >> g_nums[i];
    }

    std::sort(g_nums, g_nums + g_N);

    BacktrackingRecursive();
}
