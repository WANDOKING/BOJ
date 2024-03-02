#include <iostream>

int main(void)
{
    int N;
    int F;

    std::cin >> N >> F;

    int baseNumber = N / 100 * 100;
    int lastTwoNumber = 0;

    while (true)
    {
        int currentNumber = baseNumber + lastTwoNumber;

        if (currentNumber % F == 0)
        {
            break;
        }

        lastTwoNumber++;
    }

    printf("%02d", lastTwoNumber);
}
