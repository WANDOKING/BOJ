#include <iostream>
#include <cstring>

int main(void)
{
    const int MAX_STUDENT = 30;
    const int COUNT_INPUT = 28;

    bool bSubmit[MAX_STUDENT + 1];
    memset(bSubmit, false, MAX_STUDENT + 1);

    for (int i = 0; i < COUNT_INPUT; i++)
    {
        int num;
        scanf("%d", &num);
        bSubmit[num] = true;
    }

    for (int i = 1; i <= MAX_STUDENT; i++)
    {
        if (bSubmit[i] == false)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
