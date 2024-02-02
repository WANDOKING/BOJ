#include <iostream>

#define MAX_N 1'000'000

bool g_bIsPrime[MAX_N + 1];

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    for (int i = 0; i <= MAX_N; ++i)
    {
        g_bIsPrime[i] = true;
    }

    for (int i = 2; i <= MAX_N; ++i)
    {
        if (g_bIsPrime[i] == false)
        {
            continue;
        }

        for (int j = i * 2; j <= MAX_N; j += i)
        {
            g_bIsPrime[j] = false;
        }
    }

    int T;

    std::cin >> T;

    for (int testCaseCount = 0; testCaseCount < T; ++testCaseCount)
    {
        int N;

        std::cin >> N;

        int goldbachPartitionCount = 0;

        for (int i = 2; i <= N / 2; ++i)
        {
            int num1 = i;
            int num2 = N - i;

            if (g_bIsPrime[num1] && g_bIsPrime[num2])
            {
                goldbachPartitionCount++;
            }
        }

        std::cout << goldbachPartitionCount << '\n';
    }
}
