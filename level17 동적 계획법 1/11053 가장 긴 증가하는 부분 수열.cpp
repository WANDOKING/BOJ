#include <iostream>

int main(void)
{
    const int MAX = 1000;

    int nums[MAX];
    int dp[MAX];

    int N;
    scanf("%d", &N);

    scanf("%d", &nums[0]);
    dp[0] = 1;

    int result = 1;
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &nums[i]);

        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && dp[j] > max)
            {
                max = dp[j];
            }
        }
        dp[i] = max + 1;

        if (dp[i] > result)
        {
            result = dp[i];
        }
    }

    printf("%d", result);
}
