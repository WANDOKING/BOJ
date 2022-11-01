#include <iostream>

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    while (1)
    {
        char input[5];
    
        std::cin >> input;
        
        if (input[0] == '0')
        {
            break;
        }
    
        int result = 1;
        int i = 0;
        while (input[i] != '\0')
        {
            if (input[i] == '1')
            {
                result += 3;
            }
            else if (input[i] == '0')
            {
                result += 5;
            }
            else
            {
                result += 4;
            }
            i++;
        }
        
        std::cout << result << '\n';
    }

    return 0;
}
