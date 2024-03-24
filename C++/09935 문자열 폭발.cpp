#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>

#define MAX_STR_LENGTH 1000000
#define MAX_BOMB_STR_LENGTH 36

char g_str[MAX_STR_LENGTH + 1];
char g_bomb[MAX_BOMB_STR_LENGTH + 1];

int main(void)
{
    std::cin >> g_str >> g_bomb;

    int bombLength = strlen(g_bomb);
    char bombLastCharacter = g_bomb[bombLength - 1];

    std::stack<int> s;

    for (int i = 0; g_str[i] != '\0'; ++i)
    {
        s.push(g_str[i]);

        if (g_str[i] != bombLastCharacter)
        {
            continue;
        }

        bool bIsBomb = true;
        char temp[MAX_BOMB_STR_LENGTH + 1];
        int tempIndex = 0;
        for (int j = bombLength - 1; j >= 0; --j)
        {
            if (s.empty() == true || g_bomb[j] != s.top())
            {
                bIsBomb = false;
                break;
            }

            temp[tempIndex] = s.top();
            s.pop();
            ++tempIndex;
        }

        if (bIsBomb == false)
        {
            for (int j = tempIndex - 1; j >= 0; --j)
            {
                s.push(temp[j]);
            }
        }
    }

    if (s.empty() == true)
    {
        std::cout << "FRULA";
    }
    else
    {
        std::string result = "";
        while (s.empty() == false)
        {
            result += s.top();
            s.pop();
        }

        std::reverse(result.begin(), result.end());
        std::cout << result;
    }
}
