#include <iostream>

long long int FactorialRecursive(long long int n)
{
    if (n == 0)
    {
        return 1;
    }

    return FactorialRecursive(n - 1) * n;
}

int main(void)
{
    int N;

    std::cin >> N;

    std::cout << FactorialRecursive(N);
}
