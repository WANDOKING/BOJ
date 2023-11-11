#include <iostream>
#include <string>
#include <set>

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;

    std::cin >> n;

    std::set<std::string> employees;

    for (int i = 0; i < n; ++i)
    {
        std::string name;
        std::string enterOrLeave;

        std::cin >> name >> enterOrLeave;

        if (enterOrLeave == "enter")
        {
            employees.insert(name);
        }
        else
        {
            employees.erase(name);
        }
    }

    for (auto it = employees.rbegin(); it != employees.rend(); ++it)
    {
        std::cout << *it << '\n';
    }
}
