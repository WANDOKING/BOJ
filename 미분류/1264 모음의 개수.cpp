#include <iostream>

int main(void)
{
    char input[257];

    while(true)
    {
        fgets(input, 257, stdin);

        if (input[0] == '#')
        {
            break;
        }

        int i = 0;
        int count = 0;
        while (input[i] != '\n')
        {
            input[i] |= 32;
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
            {
                count++;
            }

            i++;
        }

        printf("%d\n", count);
    }
}
