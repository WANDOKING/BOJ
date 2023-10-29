#include <iostream>
#include <vector>

#define MAX_N 100'000

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::vector<int> divisors;
    divisors.reserve(MAX_N);

    while (true)
    {
        int n;

        std::cin >> n;

        if (n == -1)
        {
            break;
        }

        divisors.clear();

        int sum = 1;

        for (int i = 2; i < n; ++i)
        {
            if (n % i == 0)
            {
                sum += i;
                divisors.push_back(i);
            }
        }

        if (sum != n)
        {
            std::cout << n << " is NOT perfect.\n";
        }
        else
        {
            std::cout << n << " = 1";

            for (int num : divisors)
            {
                std::cout << " + " << num;
            }

            std::cout << '\n';
        }
    }
}
