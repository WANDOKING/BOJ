#include <iostream>
#include <unordered_map>

#define DIV 1000000007

// memoization
std::unordered_map<unsigned long long, unsigned long long> g_memo;

unsigned long long FibonacciRecursive(unsigned long long n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    auto memoFound = g_memo.find(n);
    if (memoFound != g_memo.end())
    {
        return memoFound->second;
    }
    
    // F[2n] = F[n] * (2F[n-1] + F[n])
    // F[2n+1] = F[n+1]^2 + F[n]^2
    unsigned long long result;
    if (n % 2 == 0)
    {
        unsigned long long fn = FibonacciRecursive(n / 2);
        unsigned long long fnMinusOne = FibonacciRecursive(n / 2 - 1);

        result = (fn * (((2 * fnMinusOne) % DIV + fn) % DIV) % DIV) % DIV;
    }
    else
    {
        unsigned long long fn = FibonacciRecursive(n / 2);
        unsigned long long fnPlusOne = FibonacciRecursive(n / 2 + 1);

        result = (((fn * fn) % DIV) + ((fnPlusOne * fnPlusOne) % DIV)) % DIV;
    }

    g_memo.insert(std::make_pair(n, result));
    return result;
}

int main(void)
{
    unsigned long long n;
    std::cin >> n;

    std::cout << FibonacciRecursive(n);
}
