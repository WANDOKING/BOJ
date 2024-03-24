#include <iostream>

int main(void)
{
    std::string input;

    std::cin >> input;

    int result = 0;

    for (const char ch : input)
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            result++;
            break;
        }
    }

    std::cout << result;
}
