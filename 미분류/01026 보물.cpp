#include <iostream>
#include <algorithm>

int main(void)
{
    const int MAX = 50;

    int N;
    int A[MAX];
    int B[MAX];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }

    std::sort(A, A + N);
    std::sort(B, B + N, std::greater<int>());

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i] * B[i];
    }

    printf("%d", sum);
}
