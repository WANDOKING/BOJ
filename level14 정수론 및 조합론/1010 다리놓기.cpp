#include <iostream>

int bridgeMemo[30][30] = { 0, }; // DP

int BridgeRecursive(int N, int M)
{
    if (bridgeMemo[N][M] != 0)
    {
        return bridgeMemo[N][M];
    }
    
    if (N == 1)
    {
        return M;
    }
    
    int sum = 0;
    for (int i = 1; i <= M - N + 1; i++)
    {
        sum += BridgeRecursive(N - 1, M - i);
    }
    
    bridgeMemo[N][M] = sum;
    return sum;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++)
    {
        int N;
        int M;
        
        scanf("%d %d", &N, &M);
        
        printf("%d\n", BridgeRecursive(N, M));
    }

    return 0;
}
