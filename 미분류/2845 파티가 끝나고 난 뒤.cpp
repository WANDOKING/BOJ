#include <iostream>

int main(void)
{
    int L;
    int P;

    std::cin >> L >> P;

    for (int i = 0; i < 5; i++)
    {
        int num;
        std::cin >> num;
        std::cout << num - L * P << ' ';
    }
}
