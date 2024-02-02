#include <iostream>

int GetResultRecursive(int height)
{
    if (height == 1)
    {
        return 2;
    }

    return GetResultRecursive(height - 1) * 2;
}

int main(void)
{
    int N;

    std::cin >> N;

    std::cout << GetResultRecursive(N);
}
