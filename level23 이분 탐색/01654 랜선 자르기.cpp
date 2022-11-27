#include <iostream>
#include <climits>

int main(void)
{
    int K;
    int N;

    scanf("%d %d", &K, &N);

    long long lines[K];
    for (int i = 0; i < K; i++)
    {
        scanf("%lld", &lines[i]);
    }
    
    long long start = 0;
    long long end = INT_MAX;

    while (start <= end)
    {
        long long mid = (start + end) / 2;

        if (mid == 0)
        {
            break;
        }

        // mid 길이의 랜선을 N개 만들 수 있는가? 로 탐색
        long long count = 0;
        for (int i = 0; i < K; i++)
        {
            count += lines[i] / mid;
        }

        if (count >= N)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    printf("%lld", end);

    return 0;
}
