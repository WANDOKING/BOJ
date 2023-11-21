#include <iostream>

#define MAX_N 100'000

int g_intervals[MAX_N];

int GetGCD(int num1, int num2)
{
    while (true)
    {
        if (num1 % num2 == 0)
        {
            return num2;
        }

        int nextNum1 = num2;
        int nextNum2 = num1 % num2;

        num1 = nextNum1;
        num2 = nextNum2;
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::iostream::sync_with_stdio(false);

    int N;

    std::cin >> N;

    int prevPosition;

    std::cin >> prevPosition;

    for (int inputCount = 0; inputCount < N - 1; ++inputCount)
    {
        int currentPosition;

        std::cin >> currentPosition;

        g_intervals[inputCount] = currentPosition - prevPosition;

        prevPosition = currentPosition;
    }

    int gcd = GetGCD(g_intervals[0], g_intervals[1]);

    for (int i = 2; i < N - 1; ++i)
    {
        gcd = GetGCD(g_intervals[i], gcd);
    }

    int result = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        result += g_intervals[i] / gcd - 1;
    }

    std::cout << result;
}
