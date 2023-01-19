#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 100000

std::pair<int, int> g_planetX[MAX_N];
std::pair<int, int> g_planetY[MAX_N];
std::pair<int, int> g_planetZ[MAX_N];

int g_parent[MAX_N];

int GetParentRecursive(int n)
{
    if (g_parent[n] == n)
    {
        return n;
    }

    g_parent[n] = GetParentRecursive(g_parent[n]);
    return g_parent[n];
}

void Union(int a, int b)
{
    int parentA = GetParentRecursive(a);
    int parentB = GetParentRecursive(b);

    int min = std::min(parentA, parentB);

    g_parent[parentA] = min;
    g_parent[parentB] = min;
}

bool Find(int a, int b)
{
    return GetParentRecursive(a) == GetParentRecursive(b);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int x;
        int y;
        int z;

        std::cin >> x >> y >> z;

        g_planetX[i].first = x;
        g_planetY[i].first = y;
        g_planetZ[i].first = z;

        g_planetX[i].second = i;
        g_planetY[i].second = i;
        g_planetZ[i].second = i;
    }

    for (int i = 0; i < N; ++i)
    {
        g_parent[i] = i;
    }

    // x, y, z에 대해서 정렬해놓고 각 좌표간 최소 차들을 가지고 간선을 만들 것
    std::sort(g_planetX, g_planetX + N);
    std::sort(g_planetY, g_planetY + N);
    std::sort(g_planetZ, g_planetZ + N);

    std::vector<std::tuple<int, int, int>> edges;
    edges.reserve(N * 3);

    for (int i = 0; i < N - 1; ++i)
    {
        int weight = g_planetX[i + 1].first - g_planetX[i].first;
        edges.push_back(std::make_tuple(weight, g_planetX[i + 1].second, g_planetX[i].second));
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int weight = g_planetY[i + 1].first - g_planetY[i].first;
        edges.push_back(std::make_tuple(weight, g_planetY[i + 1].second, g_planetY[i].second));
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int weight = g_planetZ[i + 1].first - g_planetZ[i].first;
        edges.push_back(std::make_tuple(weight, g_planetZ[i + 1].second, g_planetZ[i].second));
    }

    std::sort(edges.begin(), edges.end());

    // 크러스컬
    long long result = 0;
    for (const auto& edge : edges)
    {
        int weight = std::get<0>(edge);
        int start = std::get<1>(edge);
        int end = std::get<2>(edge);

        if (Find(start, end) == true)
        {
            continue;
        }

        Union(start, end);
        result += weight;
    }

    std::cout << result;
}
