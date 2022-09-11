#include <iostream>
#include <cstring>
#include <cassert>

int main(void)
{
    int MAX_SIZE = 10000;
    int deque[MAX_SIZE];
    int front = 0;
    int back = 0;
    int size = 0;

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char input[11];
        scanf("%s", input);

        if (strcmp(input, "push_front") == 0)
        {

            front = (front - 1 + MAX_SIZE) % MAX_SIZE;
            scanf("%d", &deque[front]);

            if (size == 0)
            {
                back = front;
            }

            size++;
        }
        else if (strcmp(input, "push_back") == 0)
        {
            back = (back + 1) % MAX_SIZE;
            scanf("%d", &deque[back]);

            if (size == 0)
            {
                front = back;
            }

            size++;
        }
        else if (strcmp(input, "pop_front") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", deque[front]);
                front = (front + 1) % MAX_SIZE;
                size--;
            }
        }
        else if (strcmp(input, "pop_back") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", deque[back]);
                back = (back - 1 + MAX_SIZE) % MAX_SIZE;
                size--;
            }
        }
        else if (strcmp(input, "size") == 0)
        {
            printf("%d\n", size);
        }
        else if (strcmp(input, "empty") == 0)
        {
            printf("%d\n", size == 0 ? 1 : 0);
        }
        else if (strcmp(input, "front") == 0)
        {
            printf("%d\n", size > 0 ? deque[front] : -1);
        }
        else if (strcmp(input, "back") == 0)
        {
            printf("%d\n", size > 0 ? deque[back] : -1);
        }
        else
        {
            assert(false);
        }
    }
}
