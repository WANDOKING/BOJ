#include <iostream>
#include <climits>

int main(void)
{
    int N;
    int K;

    scanf("%d %d", &N, &K);

    int sum = 0;
    int sums[N + 1];
    sums[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        sum += num;
        sums[i] = sum;
    }

    int max = INT_MIN;
    for (int i = K; i <= N; i++)
    {
        if (max < sums[i] - sums[i - K])
        {
            max = sums[i] - sums[i - K];
        }
    }

    printf("%d", max);
}
