#include <iostream>
#include <tuple>
#include <unordered_map>
#include <algorithm>

#define MAX_N 100

std::tuple<int, int, int> g_students[MAX_N]; // score / country / studentNumber

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int country;
        int studentNumber;
        int score;

        std::cin >> country >> studentNumber >> score;

        std::get<0>(g_students[i]) = score;
        std::get<1>(g_students[i]) = country;
        std::get<2>(g_students[i]) = studentNumber;
    }

    std::sort(g_students, g_students + N);

    std::unordered_map<int, int> countryCount;
    int medalRemainingCount = 3;

    int i = N - 1;
    while (medalRemainingCount > 0)
    {
        int score = std::get<0>(g_students[i]);
        int country = std::get<1>(g_students[i]);
        int studentNumber = std::get<2>(g_students[i]);

        if (countryCount.find(country) == countryCount.end())
        {
            countryCount.insert(std::make_pair(country, 1));
        }
        else
        {
            countryCount[country]++;
        }

        if (countryCount.find(country)->second <= 2)
        {
            std::cout << country << ' ' << studentNumber << '\n';
            medalRemainingCount--;
        }

        i--;
    }
}
