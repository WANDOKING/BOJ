#include <iostream>
#include <cstring>

int g_callCount = 0;

int Recursion(const char* s, int l, int r)
{
    g_callCount++;

    if (l >= r)
    {
        return 1;
    }
    else if (s[l] != s[r])
    {
        return 0;
    }

    return Recursion(s, l + 1, r - 1);
}

int IsPalindrome(const char* s)
{
    return Recursion(s, 0, strlen(s) - 1);
}


int main(void)
{
    const int S_MAX_LEN = 1000;
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        g_callCount = 0;

        char input[S_MAX_LEN + 1];
        scanf("%s", input);

        int isPalindrome = IsPalindrome(input);
        printf("%d %d\n", isPalindrome, g_callCount);
    }

    return 0;
}
