#include <iostream>

int main(void)
{
    std::string N;

    std::cin >> N;

    for (int i = 0; i < N.length() - 1; ++i)
    {
        int frontProduct = 1;
        int backProduct = 1;

        for (int j = 0; j <= i; ++j)
        {
            frontProduct *= N[j] - '0';
        }

        for (int j = i + 1; j < N.length(); ++j)
        {
            backProduct *= N[j] - '0';
        }

        if (frontProduct == backProduct)
        {
            std::cout << "YES";
            return 0;
        }
    }

    std::cout << "NO";
}
