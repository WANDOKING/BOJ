#include <iostream>
#include <stack>
#include <set>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    std::set<std::string> names;

    int result = 0;
    
    for (int i = 0; i < N; ++i)
    {
        std::string input;

        std::cin >> input;

        if (input == "ENTER")
        {
            names.clear();
        }
        else
        {
            if (names.find(input) == names.end())
            {
                result++;
                names.insert(input);
            }
        }
    }

    std::cout << result;
}
