#include <iostream>
#include <cstring>

int main(void)
{
    const int MAX = 50;
    char expr[MAX + 1];

    scanf("%s", expr);

    int sum = 0;
    int num;
    sscanf(expr, "%d", &num);
    sum += num;

    bool bMinusMode = false;
    for (int i = 0; i < strlen(expr); i++)
    {
        if (expr[i] >= '0' && expr[i] <= '9')
        {
            continue;
        }
        
        if (expr[i] == '-')
        {
            bMinusMode = true;
        }

        sscanf(expr + i + 1, "%d", &num);

        if (bMinusMode == true)
        {
            sum -= num;
        }
        else
        {
            sum += num;
        }
    }

    printf("%d", sum);
}
