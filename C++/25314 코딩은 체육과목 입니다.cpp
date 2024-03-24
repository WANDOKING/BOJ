#include <iostream>

int main(void)
{
    int N;

    std::string result("long");

    std::cin >> N;

    for (int i = 1; i < N / 4; ++i)
    {
        result += " long";
    }

    result += " int";

    std::cout << result;
}
