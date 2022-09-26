#include <iostream>

int main()
{
    const long long TO_DIV = 1000000000;
    
    int N;
    long long dp[101];                 // dp[N] = N에 대한 정답
    long long dpLastNumCount[101][10]; // 길이가 i인 수들 중 끝자리가 j인 수의 개수
    scanf("%d", &N);
    
    dp[1] = 9;
    dpLastNumCount[1][0] = 0;
    for (int i = 1; i <= 9; i++)
    {
        dpLastNumCount[1][i] = 1;
    }
    
    for (int i = 2; i <= N; i++)
    {
        long long sum = 0;
        dpLastNumCount[i][0] = dpLastNumCount[i - 1][1];
        sum = (sum + dpLastNumCount[i][0]) % TO_DIV;
        for (int j = 1; j <= 8; j++)
        {
            dpLastNumCount[i][j] = (dpLastNumCount[i - 1][j - 1] + dpLastNumCount[i - 1][j + 1]) % TO_DIV;
            sum = (sum + dpLastNumCount[i][j]) % TO_DIV;
        }
        dpLastNumCount[i][9] = dpLastNumCount[i - 1][8];
        sum = (sum + dpLastNumCount[i][9]) % TO_DIV;
        
        dp[i] = sum;
    }
    
    printf("%lld", dp[N] % TO_DIV);

    return 0;
}
