#include <iostream>

int main(void)
{
    const int MAX = 50;

    char input[MAX + 3];
    int N;

    scanf("%d", &N);
    getchar();
    
    for (int i = 1; i <= N; i++)
    {
        fgets(input, sizeof(char) * (MAX + 3), stdin);
        printf("%d. %s", i, input);
    }
}
