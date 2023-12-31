#include <iostream>

int g_count[100];

int main(void)
{
    int S1;
    int S2;
    int S3;

    std::cin >> S1 >> S2 >> S3;

    for (int i = 1; i <= S1; ++i)
    {
        for (int j = 1; j <= S2; ++j)
        {
            for (int k = 1; k <= S3; ++k)
            {
                g_count[i + j + k]++;
            }
        }
    }

    int mostFrequentSum = 0;
    int mostFrequentSumCount = 0;

    for (int i = 1; i < 100; ++i)
    {
        if (g_count[i] > mostFrequentSumCount)
        {
            mostFrequentSum = i;
            mostFrequentSumCount = g_count[i];
        }
    }

    std::cout << mostFrequentSum;
}
