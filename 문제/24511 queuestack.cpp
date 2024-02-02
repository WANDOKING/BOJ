#include <iostream>
#include <queue>

#define MAX_N 100'000

int g_bIsStack[MAX_N];
int g_nums[MAX_N];

int main(void)
{
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::queue<int> q;

    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> g_bIsStack[i];
    }

    for (int i = 0; i < N; ++i)
    {
        std::cin >> g_nums[i];
    }

    for (int i = N - 1; i >= 0; --i)
    {
        if (g_bIsStack[i])
        {
            continue;
        }

        q.push(g_nums[i]);
    }

    int M;

    std::cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int inputNum;

        std::cin >> inputNum;

        q.push(inputNum);
    }

    for (int i = 0; i < M; ++i)
    {
        std::cout << q.front() << ' ';

        q.pop();
    }
}
