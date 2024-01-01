#include <iostream>
#include <cmath>

int main(void)
{
    int num1;
    int num2;

    std::cin >> num1 >> num2;

    int num1Row = (num1 + 3) % 4;
    int num1Col = (num1 - 1) / 4;
    int num2Row = (num2 + 3) % 4;
    int num2Col = (num2 - 1) / 4;

    std::cout << abs(num1Row - num2Row) + abs(num1Col - num2Col);
}
