#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000

int g_nums[MAX_N];
int g_dp[MAX_N];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> g_nums[i];
    }

    int result = -1;
    for (int i = 0; i < N; ++i)
    {
        int max = 0;
        for (int j = 0; j < i; ++j)
        {
            if (g_nums[j] < g_nums[i] && g_dp[j] > max)
            {
                max = g_dp[j];
            }
        }

        g_dp[i] = max + 1;

        if (g_dp[i] > result)
        {
            result = g_dp[i];
        }
    }

    std::vector<int> lis;

    int lisCount = result;
    for (int i = N - 1; i >= 0; --i)
    {
        if (g_dp[i] == lisCount)
        {
            lis.push_back(g_nums[i]);
            --lisCount;
        }

        if (lisCount < 0)
        {
            break;
        }
    }

    std::cout << result << '\n';
    for (auto it = lis.rbegin(); it != lis.rend(); ++it)
    {
        std::cout << *it << ' ';
    }
}
