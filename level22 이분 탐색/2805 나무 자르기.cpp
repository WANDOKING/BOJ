#include <iostream>

int main(void)
{
    int N;
    long long M;
    scanf("%d %lld", &N, &M);

    long long trees[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &trees[i]);
    }

    long long start = 0;
    long long end = 2000000000;
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        long long count = 0;
        for (int i = 0; i < N; i++)
        {
            count += (trees[i] - mid) > 0 ? (trees[i] - mid) : 0;
        }

        if (count >= M)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    printf("%lld", end);
}
