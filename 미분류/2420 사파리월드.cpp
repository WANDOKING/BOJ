#include <iostream>
#include <cstdlib>

int main(void)
{
    long long N;
    long long M;

    std::cin >> N >> M;

    std::cout << llabs(N - M) << std::endl;
}
