#include <iostream>
#include <string>
#include <map>
#include <climits>

#define MAX_N 100000

std::pair<std::string, int> g_auctions[MAX_N];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int U;
    int N;

    std::cin >> U >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> g_auctions[i].first >> g_auctions[i].second;
    }

    int leastFrequentCount = INT_MAX;

    std::map<int, int> costCounts;
    for (int i = 0; i < N; ++i)
    {
        if (costCounts.find(g_auctions[i].second) == costCounts.end())
        {
            costCounts.insert(std::make_pair(g_auctions[i].second, 0));
        }

        costCounts[g_auctions[i].second]++;
    }

    for (auto& costCount : costCounts)
    {
        int count = costCount.second;

        if (count < leastFrequentCount)
        {
            leastFrequentCount = count;
        }
    }

    int resultCost = INT_MAX;
    for (auto& costCount : costCounts)
    {
        int cost = costCount.first;
        int count = costCount.second;

        if (count == leastFrequentCount && cost < resultCost)
        {
            resultCost = cost;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (g_auctions[i].second == resultCost)
        {
            std::cout << g_auctions[i].first << ' ' << g_auctions[i].second;
            break;
        }
    }
}
