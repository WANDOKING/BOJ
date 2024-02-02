#include <iostream>
#include <cmath>

bool IsPrime(unsigned long long number)
{
    if (number <= 1)
    {
        return false;
    }

    if (number == 2)
    {
        return true;
    }

    unsigned long long sq = static_cast<unsigned long long>(sqrt(number));

    bool answer = true;

    for (unsigned long long i = 2; i <= sq; ++i)
    {
        if (number % i == 0)
        {
            answer = false;
            break;
        }
    }

    return answer;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    unsigned long long testCaseCount;

    std::cin >> testCaseCount;

    for (unsigned long long i = 0; i < testCaseCount; ++i)
    {
        unsigned long long n;

        std::cin >> n;

        while (!IsPrime(n))
        {
            ++n;
        }

        std::cout << n << '\n';
    }
}
