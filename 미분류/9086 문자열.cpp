#include <iostream>
#include <cstring>

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++)
    {
        char input[1000];
        scanf("%s", input);
        printf("%c%c\n", input[0], input[strlen(input) - 1]);
    }

    return 0;
}
