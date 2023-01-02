#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 4000050

bool g_bIsPrime[MAX_N + 1];

int main(void)
{
    memset(g_bIsPrime, 1, sizeof(g_bIsPrime));

    for (int i = 2; i <= MAX_N; ++i)
    {
        if (g_bIsPrime[i] == false)
        {
            continue;
        }

        for (int j = i * 2; j <= MAX_N; j += i)
        {
            g_bIsPrime[j] = false;
        }
    }

    std::vector<long long> primeNumbers;
    primeNumbers.reserve(MAX_N);
    primeNumbers.push_back(0);

    long long sum = 0;
    for (int i = 2; i <= MAX_N; ++i)
    {
        if (g_bIsPrime[i] == true)
        {
            sum += i;
            primeNumbers.push_back(sum);
        }
    }

    int N;
    std::cin >> N;

    int index1 = 1;
    int index2 = 1;
    int result = 0;

    while (index1 <= index2)
    {
        long long sum = primeNumbers[index2] - primeNumbers[index1 - 1];

        if (sum == N)
        {
            ++result;
            ++index1;
        }
        else if (sum < N)
        {
            ++index2;
        }
        else
        {
            ++index1;
        }
    }

    std::cout << result;
}
