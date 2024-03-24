#include <iostream>
#include <string>
#include <algorithm>

int Rev(int X)
{
    std::string str(std::to_string(X));
    std::reverse(str.begin(), str.end());
    return std::stoi(str);
}

int main(void)
{
    int X;
    int Y;

    std::cin >> X >> Y;

    std::cout << Rev(Rev(X) + Rev(Y));
}
