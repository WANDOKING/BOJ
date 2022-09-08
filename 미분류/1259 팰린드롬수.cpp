#include <iostream>
#include <cstring>

int main(void)
{
    while (true)
    {
        char input[6];
        scanf("%s", &input);

        if (input[0] == '0')
        {
            break;
        }

        int length = strlen(input);
        for (int i = 0; i < length / 2; i++)
        {
            if (input[i] != input[length - 1 - i])
            {
                printf("no\n");
                goto NEXT;
            }
        }

        printf("yes\n");

    NEXT:;
    }
    return 0;
}
