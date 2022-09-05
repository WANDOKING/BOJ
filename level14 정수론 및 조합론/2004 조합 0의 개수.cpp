#include <iostream>

int main(void)
{
    int n;
    int m;
    scanf("%d %d", &n, &m);

    // n!, m!, (n-m)!의 인수들 중 2의 개수와 5의 개수를 구할 것
    int factNTwoCount = 0;
    int factMTwoCount = 0;
    int factNminusMTwoCount = 0;

    int factNFiveCount = 0;
    int factMFiveCount = 0;
    int factNminusMFiveCount = 0;
    
    for (uint64_t i = 2; i <= n; i *= 2)
    {
        factNTwoCount += n / i;

        if (i <= m)
        {
            factMTwoCount += m / i;
        }

        if (i <= n - m)
        {
            factNminusMTwoCount += (n - m) / i;
        }
    }

    for (uint64_t i = 5; i <= n; i *= 5)
    {
        factNFiveCount += n / i;

        if (i <= m)
        {
            factMFiveCount += m / i;
        }

        if (i <= n - m)
        {
            factNminusMFiveCount += (n - m) / i;
        }
    }

    int totalTwoCount = factNTwoCount - factMTwoCount - factNminusMTwoCount;
    int totalFiveCount = factNFiveCount - factMFiveCount - factNminusMFiveCount;
    
    int result = totalTwoCount < totalFiveCount ? totalTwoCount : totalFiveCount;
    printf("%d", result);
}
