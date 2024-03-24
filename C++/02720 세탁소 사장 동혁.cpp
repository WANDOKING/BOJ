#include <iostream>

int main(void)
{
    int T;

    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int num;

        std::cin >> num;

        std::cout << num / 25 << ' ';
        num %= 25;
        std::cout << num / 10 << ' ';
        num %= 10;
        std::cout << num / 5 << ' ';
        num %= 5;
        std::cout << num;

        std::cout << '\n';
    }
}
