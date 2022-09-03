#include <iostream>

int main()
{
    int nck[1001][1001]; // 파스칼의 삼각형
    
    nck[0][0] = 1;
    nck[1][0] = 1;
    nck[1][1] = 1;
    for (int i = 0; i < 1001; i++)
    {
        nck[i][0] = 1;
        
        for (int j = 1; j < i; j++)
        {
            nck[i][j] = (nck[i - 1][j - 1] + nck[i - 1][j]) % 10007;
        }
        
        nck[i][i] = 1;
    }
    
    int N;
    int K;
    
    scanf("%d %d", &N, &K);
    
    printf("%d", nck[N][K]);

    return 0;
}
