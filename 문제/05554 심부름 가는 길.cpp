#include <iostream>
#include <vector>

int main(void)
{
    int sum = 0;

    for (int i = 0; i < 4; ++i)
    {
        int num;
        std::cin >> num;

        sum += num;
    }

    std::cout << sum / 60 << std::endl;
    std::cout << sum % 60 << std::endl;
}
