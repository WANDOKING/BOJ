#include <iostream>

int main()
{
    int N;
    int K;
    
    scanf("%d %d", &N, &K);
    
    int a = 1;
    for (int i = N; i >= K + 1; i--)
    {
        a *= i;
    }
    
    int b = 1;
    for (int i = 2; i <= (N - K); i++)
    {
        b *= i;
    }
    
    printf("%d", a / b);

    return 0;
}
