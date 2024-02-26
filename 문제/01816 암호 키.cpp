#include <iostream>
#include <cstring>

#define BIG_PRIME_NUM_MIN 1'000'000

bool g_bIsPrimeNum[BIG_PRIME_NUM_MIN + 1];

int main(void)
{

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    // BIG_PRIME_NUM_MIN 까지의 소수 판정

    memset(g_bIsPrimeNum, true, BIG_PRIME_NUM_MIN + 1);

    for (int i = 2; i <= BIG_PRIME_NUM_MIN; ++i)
    {
        if (g_bIsPrimeNum[i] == false)
        {
            continue;
        }

        for (int j = i * 2; j <= BIG_PRIME_NUM_MIN; j += i)
        {
            g_bIsPrimeNum[j] = false;
        }
    }

    for (int inputCount = 0; inputCount < N; ++inputCount)
    {
        long long cipher;
        std::cin >> cipher;

        bool bCipherValid = true;

        for (int i = 2; i <= BIG_PRIME_NUM_MIN; ++i)
        {
            if (g_bIsPrimeNum[i] == false)
            {
                continue;
            }

            if (cipher % i == 0)
            {
                bCipherValid = false;
                break;
            }
        }

        if (bCipherValid)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}
