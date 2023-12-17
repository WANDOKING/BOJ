#include <iostream>

int main(void)
{
    int N;

    std::cin >> N;

    int result = 0;

    for (int i = 0; i < N; ++i)
    {
        int num;

        std::cin >> num;

        result += num;
    }

    result -= N - 1;

    std::cout << result;
}
