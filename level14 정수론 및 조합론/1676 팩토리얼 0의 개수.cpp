#include <iostream>

int main(void)
{
    int N;
    scanf("%d", &N);

    int fiveCount = 0;

    for (int i = 1; i <= N; i++)
    {
        int temp = i;
        while (temp % 5 == 0)
        {
            fiveCount++;
            temp /= 5;
        }
    }

    printf("%d", fiveCount);
}
