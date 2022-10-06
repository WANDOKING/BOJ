#include <iostream>

int main(void)
{
    int N;
    scanf("%d", &N);

    int youngsikSum = 0;
    int minsikSum = 0;
    for (int i = 0; i < N; i++)
    {
        int callingTime;

        scanf("%d", &callingTime);

        youngsikSum += 10 + (callingTime / 30) * 10;
        minsikSum += 15 + (callingTime / 60) * 15;
    }

    int result = youngsikSum < minsikSum ? youngsikSum : minsikSum;

    if (result == youngsikSum)
    {
        printf("Y ");
    }
    if (result == minsikSum)
    {
        printf("M ");
    }

    printf("%d", result);
}
