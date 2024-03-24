#include <iostream>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    long long N;
    std::cin >> N;

    long long result = 0;

    for (long long x = 1; x < N; ++x)
    {
        result += x * N + x;
    }

    std::cout << result;
}
