#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 8

int g_nums[MAX_N];
int g_backtrackingNums[MAX_N];
bool g_bUsed[MAX_N] = { false, };

void Recursive(const int N, const int M, int depth = 0)
{
    if (depth == M)
    {
        std::string result = "";
        result += std::to_string(g_backtrackingNums[0]);
        for (int i = 1; i < M; ++i)
        {
            result += ' ';
            result += std::to_string(g_backtrackingNums[i]);
        }

        std::cout << result << '\n';
        return;
    }

    int prevNum = -1;
    for (int i = 0; i < N; ++i)
    {
        if (g_bUsed[i] == true)
        {
            continue;
        }

        if (prevNum == g_nums[i])
        {
            continue;
        }

        g_backtrackingNums[depth] = g_nums[i];
        g_bUsed[i] = true;
        Recursive(N, M, depth + 1);
        g_bUsed[i] = false;
        prevNum = g_nums[i];
    }
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
        std::cin >> g_nums[i];   
    }

    std::sort(g_nums, g_nums + N);

    Recursive(N, M);
}
