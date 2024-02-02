#include <iostream>

int main(void)
{
    int A;
    int B;
    int N;

    std::cin >> A >> B >> N;

    int answer = 0;
    int currentPoint = 0;

    while (true)
    {
        if (A < B)
        {
            answer = 0;
            A *= 10;
        }
        else
        {
            answer = A / B;
            A = (A % B) * 10;
        }

        if (currentPoint == N)
        {
            break;
        }

        currentPoint++;
    }

    std::cout << answer;
}
