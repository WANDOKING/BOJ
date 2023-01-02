#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

#define MAX_N 5000

long long g_nums[MAX_N];

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

    std::sort(g_nums, g_nums + N);

    int resultTargetIndex = INT_MAX;
    int resultIndex1 = INT_MAX;
    int resultIndex2 = INT_MAX;
    long long minDifference = INT64_MAX;

    for (int i = 0; i < N; ++i)
    {
        long long targetValue = g_nums[i]; // 하나를 고정해놓고 나머지 둘로 투포인터
        int index1 = 0;
        int index2 = N - 1;

        while (index1 < index2)
        {
            if (index1 == i)
            {
                ++index1;
                continue;
            }

            if (index2 == i)
            {
                --index2;
                continue;
            }

            long long sum = g_nums[index1] + g_nums[index2] + targetValue;
            long long diff = std::abs(sum);

            if (diff < minDifference)
            {
                resultTargetIndex = i;
                resultIndex1 = index1;
                resultIndex2 = index2;
                minDifference = diff;
            }

            if (sum == 0)
            {
                break;
            }
            else if (sum < 0)
            {
                ++index1;
            }
            else
            {
                --index2;
            }
        }

        if (minDifference == 0)
        {
            break;
        }
    }

    long long result[3];
    result[0] = g_nums[resultIndex1];
    result[1] = g_nums[resultIndex2];
    result[2] = g_nums[resultTargetIndex];
    std::sort(result, result + 3);

    std::cout << result[0] << ' ' << result[1] << ' ' << result[2];
}
