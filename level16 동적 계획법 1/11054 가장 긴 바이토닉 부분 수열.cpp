#include <iostream>

int main(void)
{
    const int MAX = 1000;

    int nums[MAX];
    int dp[MAX][2]; // dp[][0]은 왼쪽 -> 오른쪽, dp[][1]은 오른쪽 -> 왼쪽

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    // left -> right
    for (int i = 0; i < N; i++)
    {
        int leftMax = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && dp[j][0] > leftMax)
            {
                leftMax = dp[j][0];
            }
        }
        dp[i][0] = leftMax + 1;
    }

    // right -> left
    for (int i = N - 1; i >= 0; i--)
    {
        int rightMax = 0;
        for (int j = N - 1; j > i; j--)
        {
            if (nums[j] < nums[i] && dp[j][1] > rightMax)
            {
                rightMax = dp[j][1];
            }
        }
        dp[i][1] = rightMax + 1;
    }

    // result
    int result = 1;
    for (int i = 0; i < N; i++)
    {
        int length = dp[i][0] + dp[i][1] - 1;
        if (length > result)
        {
            result = length;
        }
    }

    printf("%d", result);
}
