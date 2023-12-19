#include <iostream>
#include <string>
#include <unordered_set>

int main(void)
{
    int N;

    std::cin >> N;

    std::unordered_set<std::string> dancingPeople;

    dancingPeople.insert("ChongChong");

    for (int i = 0; i < N; ++i)
    {
        std::string name1;
        std::string name2;

        std::cin >> name1 >> name2;

        if (dancingPeople.find(name1) != dancingPeople.end())
        {
            dancingPeople.insert(name2);
        }
        else if (dancingPeople.find(name2) != dancingPeople.end())
        {
            dancingPeople.insert(name1);
        }
    }

    std::cout << dancingPeople.size();
}
