#include <iostream>

int main()
{
    char input[101];
    
    scanf("%s", input);
    
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            printf("%c", input[i] - 32);
        }
        else
        {
            printf("%c", input[i] + 32);
        }
        
        i++;
    }

    return 0;
}
