#include <iostream>

int main(void)
{
    int T;
    scanf("%d", &T);
    
    int memo[11];
    
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    
    for (int i = 3; i < 11; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    
    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", memo[n]);
    }
}
