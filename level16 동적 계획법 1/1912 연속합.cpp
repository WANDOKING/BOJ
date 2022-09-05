#include <iostream>
#include <climits>

int main(void)
{
    int n;

    scanf("%d", &n);

    int prevSum = INT_MIN;
    int result = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);

        if (prevSum < 0)
        {
            prevSum = 0;
        }

        prevSum += num;  

        if (prevSum > result)
        {
            result = prevSum;
        }
    }

    printf("%d", result);

    return 0;
}
