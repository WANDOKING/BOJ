#include <iostream>
#include <cstring>

int main(void)
{
    int N;
    scanf("%d", &N);

    const int MAX_SIZE = 10000;

    int queue[MAX_SIZE];
    int front = 0;
    int back = -1;
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            back = (back + 1) % MAX_SIZE;
            scanf("%d", &queue[back]);   
            size++;
        }

        if (strcmp(command, "pop") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", queue[front]);
                front = (front + 1) % MAX_SIZE;
                size--;
            }
        }

        if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size);
        }

        if (strcmp(command, "empty") == 0)
        {
            printf("%d\n", size == 0 ? 1 : 0);
        }

        if (strcmp(command, "front") == 0)
        {
            printf("%d\n", size > 0 ? queue[front] : -1);
        }

        if (strcmp(command, "back") == 0)
        {
            printf("%d\n", size > 0 ? queue[back] : -1);
        }
    }
}
