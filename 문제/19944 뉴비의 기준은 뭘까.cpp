#include <iostream>

int main(void)
{
    int N;
    int M;

    std::cin >> N >> M;

    if (M == 1 || M == 2)
    {
        std::cout << "NEWBIE!\n";
    }
    else if (M <= N)
    {
        std::cout << "OLDBIE!\n";
    }
    else
    {
        std::cout << "TLE!\n";
    }
}
