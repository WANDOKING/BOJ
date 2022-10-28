#include <iostream>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T;
    
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        int a;
        int b;

        std::cin >> a >> b;

        int result = 1;
        
        for (int j = 0; j < b; j++)
        {
            result *= a;
            result %= 10;
        }

        if (result == 0)
        {
            result = 10;
        }

        std::cout << result << '\n';
    }
}
