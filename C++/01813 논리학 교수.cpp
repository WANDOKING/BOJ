#include <iostream>

#define MAX_N 50
#define MAX_NUM 50

int g_numCount[MAX_N + 1];

int main(void)
{
    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int num;

        std::cin >> num;

        g_numCount[num] += 1;
    }

    int result = -1;

    for (int i = 0; i <= MAX_NUM; ++i)
    {
        if (g_numCount[i] == i)
        {
            result = i;
        }
    }

    std::cout << result;
}
