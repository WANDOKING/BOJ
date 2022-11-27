#include <iostream>

#define NONE 0
#define BALL 1

int main(void)
{
    int M;
    std::cin >> M;

    int cups[4] = {NONE, };
    cups[1] = BALL;
    for (int i = 0; i < M; i++)
    {
        int X;
        int Y;
        std::cin >> X >> Y;

        int temp = cups[X];
        cups[X] = cups[Y];
        cups[Y] = temp;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (cups[i] == BALL)
        {
            std::cout << i;
        }
    }
}
