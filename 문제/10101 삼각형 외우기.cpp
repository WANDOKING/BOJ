#include <iostream>

int main(void)
{
    int a;
    int b;
    int c;

    std::cin >> a >> b >> c;

    if (a + b + c != 180)
    {
        std::cout << "Error";
        return 0;
    }

    if (a == 60 && b == 60 && c == 60)
    {
        std::cout << "Equilateral";
        return 0;
    }

    if (a == b || b == c || a == c)
    {
        std::cout << "Isosceles";
    }
    else
    {
        std::cout << "Scalene";
    }
}
