#include <iostream>

int main(void)
{
    int N;
    int M;
    scanf("%d %d", &N, &M);

    int sums[N + 1];
    int sum = 0;
    sums[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        sum += num;
        sums[i] = sum;
    }

    for (int i = 0; i < M; i++)
    {
        int start;
        int end;
        scanf("%d %d", &start, &end);

        printf("%d\n", sums[end] - sums[start - 1]);
    }
}
