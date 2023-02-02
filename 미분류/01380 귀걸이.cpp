#include <iostream>

#define MAX_N 100
#define MAX_NAME_LENGTH 62

char g_students[MAX_N][MAX_NAME_LENGTH];
int g_isReturned[MAX_N];

int main(void)
{
    int scenarioNum = 1;
    while (true)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; ++i)
        {
            g_isReturned[i] = 0;
        }

        fgets(g_students[0], MAX_NAME_LENGTH, stdin);

        for (int i = 0; i < n; ++i)
        {
            fgets(g_students[i], MAX_NAME_LENGTH, stdin);
        }

        for (int i = 0; i < n * 2 - 1; ++i)
        {
            int num;
            char alphabet;

            scanf("%d %c", &num, &alphabet);

            g_isReturned[num - 1]++;
        }

        for (int i = 0; i < n; ++i)
        {
            if (g_isReturned[i] == 1)
            {
                printf("%d %s", scenarioNum, g_students[i]);
                break;
            }
        }

        scenarioNum++;
    }
}
