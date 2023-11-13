#include <iostream>

long long int GetGCD(long long int a, long long int b)
{
    while (a % b != 0)
    {
        long long int nextA = b;
        long long int nextB = a % b;

        a = nextA;
        b = nextB;
    }

    return b;
}

long long int GetLCM(long long int a, long long int b)
{
    return a * b / GetGCD(a, b);
}

int main(void)
{
    long long int A;
    long long int B;

    std::cin >> A >> B;

    std::cout << GetLCM(A, B);
}
