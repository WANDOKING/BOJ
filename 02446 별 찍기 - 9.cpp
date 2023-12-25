#include <iostream>

int main(void)
{
    int N;

    std::cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < (2 * N) - 1 - (2 * i); ++j)
        {
            std::cout << '*';
        }

        for (int j = 0; j < i; ++j)
        {
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < i * 2 + 1; ++j)
        {
            std::cout << '*';
        }

        for (int j = 0; j < N - i - 1; ++j)
        {
            std::cout << ' ';
        }

        std::cout << '\n';
    }
}
