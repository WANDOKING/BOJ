#include <iostream>
#include <climits>
#include <cmath>

#define MAX_N 100000

int g_nums[MAX_N];

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

    size_t index1 = 0;
    size_t index2 = N - 1;

    size_t resultIndex1 = 0;
    size_t resultIndex2 = 0;
    int minAbs = INT_MAX;

    while (index1 < index2)
    {
        int absValue = std::abs(g_nums[index1] + g_nums[index2]);

        if (absValue < minAbs)
        {
            minAbs = absValue;
            resultIndex1 = index1;
            resultIndex2 = index2;
        }

        if (g_nums[index1] + g_nums[index2] == 0)
        {
            break;

        }
        else if (g_nums[index1] + g_nums[index2] > 0)
        {
            --index2;
        }
        else
        {
            ++index1;
        }
    }

    std::cout << g_nums[resultIndex1] << ' ' << g_nums[resultIndex2];
}
