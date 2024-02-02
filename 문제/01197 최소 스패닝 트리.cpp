#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#define MAX_V 10000

int g_parent[MAX_V + 1];

int GetParentRecursive(int n)
{
    if (g_parent[n] == n)
    {
        return n;
    }

    g_parent[n] = GetParentRecursive(g_parent[n]);
    return g_parent[n];
}

bool Find(int a, int b)
{
    int parentA = GetParentRecursive(a);
    int parentB = GetParentRecursive(b);

    return parentA == parentB;
}

void Union(int a, int b)
{
    int parentA = GetParentRecursive(a);
    int parentB = GetParentRecursive(b);

    g_parent[parentA] = std::min(parentA, parentB);
    g_parent[parentB] = std::min(parentA, parentB);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int V;
    int E;

    std::cin >> V >> E;

    for (int i = 1; i <= V; ++i)
    {
        g_parent[i] = i;
    }

    std::vector<std::tuple<int, int, int>> edges; // weight, v1, v2
    edges.reserve(E);

    for (int i = 0; i < E; ++i)
    {
        int v1;
        int v2;
        int weight;

        std::cin >> v1 >> v2 >> weight;

        edges.push_back(std::make_tuple(weight, v1, v2));
    }

    // Kruskal Algorithm

    std::sort(edges.begin(), edges.end());

    int result = 0;
    for (const auto& edge : edges)
    {
        int weight = std::get<0>(edge);
        int v1 = std::get<1>(edge);
        int v2 = std::get<2>(edge);

        if (Find(v1, v2) == true)
        {
            continue;
        }

        Union(v1, v2);
        result += weight;
    }

    std::cout << result;
}
