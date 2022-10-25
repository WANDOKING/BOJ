#include <iostream>

int main(void)
{
    int N;
    scanf("%d", &N);

    int nums[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    int v;
    scanf("%d", &v);

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (nums[i] == v)
        {
            count++;
        }
    }

    printf("%d", count);
}
