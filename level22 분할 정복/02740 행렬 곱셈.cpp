#include <iostream>

#define MAX 100

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int A[MAX][MAX];
    int B[MAX][MAX];
    
    int N;
    int M;
    int K;
    
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> A[i][j];
        }
    }
    
    std::cin >> M >> K;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            std::cin >> B[i][j];
        }
    }
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            int sum = 0;
            for (int k = 0; k < M; ++k)
            {
                sum += A[i][k] * B[k][j];
            }
            std::cout << sum << ' ';
        }
        std::cout << '\n';
    }


    return 0;
}
