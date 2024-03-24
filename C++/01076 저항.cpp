#include <iostream>
#include <string>
#include <cassert>

long long GetValue(const std::string& color)
{
    if (color == "black")           return 0;
    else if (color == "brown")      return 1;
    else if (color == "red")        return 2;
    else if (color == "orange")     return 3;
    else if (color == "yellow")     return 4;
    else if (color == "green")      return 5;
    else if (color == "blue")       return 6;
    else if (color == "violet")     return 7;
    else if (color == "grey")       return 8;
    else if (color == "white")      return 9;
    else                            assert(false);
}

int main(void)
{
    std::string colorFirst;
    std::string colorSecond;
    std::string colorThird;

    std::cin >> colorFirst >> colorSecond >> colorThird;

    long long result = GetValue(colorFirst) * 10 + GetValue(colorSecond);

    int loopCount = GetValue(colorThird);
    for (int i = 0; i < loopCount; ++i)
    {
        result *= 10;
    }

    std::cout << result;
}
