#include <iostream>

int GetGCD(int num1, int num2)
{
    while (true)
    {
        if (num1 % num2 == 0)
        {
            return num2;
        }

        int nextNum1 = num2;
        int nextNum2 = num1 % num2;

        num1 = nextNum1;
        num2 = nextNum2;
    }
}

int main(void)
{
    int numerator1;
    int denominator1;

    int numerator2;
    int denominator2;

    std::cin >> numerator1 >> denominator1;
    std::cin >> numerator2 >> denominator2;

    int answerNumerator = numerator1 * denominator2 + numerator2 * denominator1;
    int answerDenominator = denominator1 * denominator2;

    int tempGCD = GetGCD(answerDenominator, answerNumerator);

    answerNumerator /= tempGCD;
    answerDenominator /= tempGCD;

    std::cout << answerNumerator << ' ' << answerDenominator;
}
