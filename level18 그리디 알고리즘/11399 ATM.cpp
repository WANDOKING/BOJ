#include <iostream>
#include <cstdlib>

int compare(const void* a, const void* b)
{
    int num1 = *((int*)a);
    int num2 = *((int*)b);

    if (num1 == num2)
    {
        return 0;
    }
    else if (num1 > num2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int P[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }

    qsort(P, N, sizeof(int), compare);

    int sum = 0;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        sum += P[i];
        result += sum;
    }

    printf("%d", result);
}
