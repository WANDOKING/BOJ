#include <iostream>

int main(void)
{
    int N;
    int L;
    std::cin >> N >> L;

    int resultStart = -1;
    int resultLength = -1;

    // N = x + (x + 1) + (x + 2) + ... + (x + L - 1)
    // = Lx + (1 + 2 + ... + L - 1)
    // Lx + (L - 1)L / 2
    // -> x = (N - ((L - 1)L / 2) / L
    for (int i = L; i <= 100; i++)
    {
        int temp = (i - 1) * i / 2;

        // x는 정수이므로 (N- temp)가 L로 나누어 떨어지고, 0 이상이여야 함
        if ((N - temp) % i == 0 && (N - temp) / i >= 0)
        {
            resultStart = (N - temp) / i;
            resultLength = i;
            break;
        }
    }

    if (resultStart == -1)
    {
        std::cout << -1;
    }
    else
    {
        for (int i = 0; i < resultLength; i++)
        {
            std::cout << resultStart + i << ' ';
        }
    }
        
    return 0;
}
