#include <iostream>

int main(void)
{
    int N;
    int K;

    std::cin >> N >> K;

    int count = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (N % i == 0)
        {
            count++;

            if (count == K)
            {
                std::cout << i;
                return 0;
            }
        }
    }

    std::cout << 0;
}
