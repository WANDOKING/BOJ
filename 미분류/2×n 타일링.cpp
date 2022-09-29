#include <iostream>

int main(void)
{
    const int MAX = 1000;
    const int TO_DIV = 10007;

    int n;

    scanf("%d", &n);

    int dp[MAX + 1];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % TO_DIV;
    }

    printf("%d", dp[n]);
}
