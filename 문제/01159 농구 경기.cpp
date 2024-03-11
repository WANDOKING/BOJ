#include <iostream>

#define ALPHABET_COUNT 26

int g_firstCharCount[ALPHABET_COUNT];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string name;

        std::cin >> name;

        g_firstCharCount[name[0] - 'a'] += 1;
    }

    bool bCanGoGame = false;

    for (int i = 0; i < ALPHABET_COUNT; ++i)
    {
        if (g_firstCharCount[i] >= 5)
        {
            std::cout << static_cast<char>('a' + i);
            bCanGoGame = true;
        }
    }

    if (bCanGoGame == false)
    {
        std::cout << "PREDAJA";
    }
}
