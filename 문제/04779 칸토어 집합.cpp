#include <iostream>
#include <cstring>
#include <cmath>

#define MAX_STRING_LENGTH 531441 // 3 ^ 12

char g_result[MAX_STRING_LENGTH + 1];

void SplitRecursive(char str[], const int length)
{
    if (length == 1)
    {
        return;
    }

    for (int i = 0; i < length / 3; ++i)
    {
        str[length / 3 + i] = ' ';
    }

    SplitRecursive(str, length / 3);
    SplitRecursive(str + (length / 3 * 2), length / 3);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    while (std::cin >> N)
    {
        int length = pow(3, N);

        memset(g_result, '-', length);

        SplitRecursive(g_result, length);
        g_result[length] = '\0';

        std::cout << g_result << '\n';
    }
}
