#include <iostream>
#include <climits>

#define MAX 9

int main(void)
{
    int max = INT_MIN;
    int maxI = -1;
    int maxJ = -1;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            int num;
            scanf("%d", &num);

            if (num > max)
            {
                max = num;
                maxI = i;
                maxJ = j;
            }
        }
    }

    printf("%d\n", max);
    printf("%d %d\n", maxI + 1, maxJ + 1);
}
