#include <iostream>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    while (true)
    {
        int a;

        std::cin >> a;

        if (a == 0)
        {
            break;
        }

        int result = 1;
        for (int i = 0; i < a; ++i)
        {
            int splittingFactor;
            int cutCount;

            std::cin >> splittingFactor >> cutCount;

            result *= splittingFactor;
            result -= cutCount;
        }

        std::cout << result << '\n';
    }
}
