#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T;

    std::cin >> T;

    for (int testCount = 0; testCount < T; ++testCount)
    {
        int N;
        int M;

        std::cin >> N >> M;

        std::vector<int> sejunSoldiers;
        sejunSoldiers.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            int soldierPower;
            std::cin >> soldierPower;
            sejunSoldiers.push_back(soldierPower);
        }

        std::sort(sejunSoldiers.rbegin(), sejunSoldiers.rend());

        std::vector<int> saebiSoldiers;
        saebiSoldiers.reserve(M);
        for (int i = 0; i < M; ++i)
        {
            int soldierPower;
            std::cin >> soldierPower;
            saebiSoldiers.push_back(soldierPower);
        }

        std::sort(saebiSoldiers.rbegin(), saebiSoldiers.rend());

        while (true)
        {
            if (sejunSoldiers.back() >= saebiSoldiers.back())
            {
                saebiSoldiers.pop_back();
            }
            else
            {
                sejunSoldiers.pop_back();
            }

            if (sejunSoldiers.empty())
            {
                std::cout << "B\n";
                break;
            }
            else if (saebiSoldiers.empty())
            {
                std::cout << "S\n";
                break;
            }
        }
    }
}
