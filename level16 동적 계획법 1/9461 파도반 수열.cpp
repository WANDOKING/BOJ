#include <iostream>
#include <cstdint>

int main()
{
    uint64_t P[101];
    
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    for (int i = 6; i <= 100; i++)
    {
        P[i] = P[i - 5] + P[i - 1];
    }
    
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        printf("%ld\n", P[N]);
    }

    return 0;
}
