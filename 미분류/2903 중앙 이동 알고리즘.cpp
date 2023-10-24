#include <iostream>

int main(void)
{
    int N;

    std::cin >> N;

    int temp = 3;
    
    for (int i = 1; i <= 15; ++i)
    {
        long long result = temp * temp;

        if (i == N)
        {
            std::cout << result;
        }

        temp += temp - 1;
    }
}
