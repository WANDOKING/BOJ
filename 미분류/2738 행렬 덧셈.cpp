#include <iostream>

int main(void)
{
    int N;
    int M;

    scanf("%d %d", &N, &M);

    int A[N][M];
    int B[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // A = A + B
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] += B[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", A[i][j]);
        }

        printf("\n");
    }

    return 0;
}
