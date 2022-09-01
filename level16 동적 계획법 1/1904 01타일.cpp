#include <iostream>

int main()
{
    const int toDivide = 15746;
    int N;
    
    scanf("%d", &N);
    
    int counts[N + 1]; // grid
    counts[1] = 1;
    counts[2] = 2;
    
    for (int i = 3; i <= N; i++)
    {
        counts[i] = (counts[i - 2] + counts[i - 1]) % toDivide;
    }
    
    printf("%d", counts[N] % toDivide);

    return 0;
}
