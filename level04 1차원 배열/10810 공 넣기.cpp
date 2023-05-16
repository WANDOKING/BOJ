#include <iostream>

#define MAX_N 100
#define MAX_M 100

int g_arr[MAX_N];

int main(void)
{
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    for (int loopCount = 0; loopCount < M; ++loopCount)
    {
        int i;
        int j;
        int k;

        std::cin >> i >> j >> k;

        for (int indexArr = i - 1; indexArr <= j - 1; ++indexArr)
        {
            g_arr[indexArr] = k;
        }
    }

    for (int loopCount = 0; loopCount < N; ++loopCount)
    {
        printf("%d ", g_arr[loopCount]);
    }
}
