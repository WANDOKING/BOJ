#include <iostream>
#include <climits>

int main(void)
{
    const int MAX = 50000;
    int dp[MAX + 1];
    dp[0] = 0;
    dp[1] = 1;

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int minCount = INT_MAX;
        int num = 1;
        int squareNum = 1;
        while (squareNum <= i)
        {
            if (dp[i - squareNum] < minCount)
            {
                minCount = dp[i - squareNum];
            }

            num++;
            squareNum = num * num;
        }

        dp[i] = minCount + 1;
    }

    printf("%d", dp[n]);
}
