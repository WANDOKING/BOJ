#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

std::vector<int> g_houses;
std::vector<int> g_chickens;
std::vector<bool> g_selected;

int g_result = INT_MAX;

int CalculateChickenDistance()
{
    std::vector<int> minDistances;
    minDistances.reserve(g_houses.size());

    for (size_t i = 0; i < g_houses.size(); ++i)
    {
        minDistances.push_back(INT_MAX);
    }

    for (size_t i = 0; i < g_chickens.size(); ++i)
    {
        if (g_selected[i] == false)
        {
            continue;
        }

        int chickenX = g_chickens[i] % 100;
        int chickenY = g_chickens[i] / 100;

        for (size_t j = 0; j < g_houses.size(); ++j)
        {
            int houseX = g_houses[j] % 100;
            int houseY = g_houses[j] / 100;

            int distance = std::abs(houseX - chickenX) + std::abs(houseY - chickenY);

            if (minDistances[j] > distance)
            {
                minDistances[j] = distance;
            }
        }
    }

    int result = 0;
    for (int minDistance : minDistances)
    {
        result += minDistance;
    }

    return result;
}

void BackTracking(int M, int i = 0, int depth = 0)
{
    if (depth == M)
    {
        int cityChickenDistance = CalculateChickenDistance();

        if (cityChickenDistance < g_result)
        {
            g_result = cityChickenDistance;
        }

        return;
    }

    for (; i < g_selected.size(); ++i)
    {
        if (g_selected[i] == true)
        {
            continue;
        }

        g_selected[i] = true;
        BackTracking(M, i + 1, depth + 1);
        g_selected[i] = false;
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int input;
            std::cin >> input;

            if (input == 1)
            {
                g_houses.push_back(j * 100 + i);
            }
            else if (input == 2)
            {
                g_chickens.push_back(j * 100 + i);
                g_selected.push_back(false);
            }
        }
    }

    BackTracking(M);
    std::cout << g_result;
}
