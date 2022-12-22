#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 100000

int g_parent[MAX_N + 1];

int GetparentRecursive(int n)
{
    if (n == g_parent[n])
    {
        return n;
    }

    g_parent[n] = GetparentRecursive(g_parent[n]);
    return g_parent[n];
}

bool Find(int a, int b)
{
    int parentA = GetparentRecursive(a);
    int parentB = GetparentRecursive(b);

    return parentA == parentB;
}

void Union(int a, int b)
{
    int parentA = GetparentRecursive(a);
    int parentB = GetparentRecursive(b);

    g_parent[parentA] = std::min(parentA, parentB);
    g_parent[parentB] = std::min(parentA, parentB);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        g_parent[i] = i;
    }

    std::vector<std::tuple<int, int, int>> edges; // weight, v1, v2
    edges.reserve(M);

    for (int i = 0; i < M; ++i)
    {
        int v1;
        int v2;
        int weight;

        std::cin >> v1 >> v2 >> weight;

        edges.push_back(std::make_tuple(weight, v1, v2));
    }

    std::sort(edges.begin(), edges.end());

    long long sum = 0;
    int max = -1;
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
        sum += weight;
        if (weight > max)
        {
            max = weight;
        }
    }

    std::cout << (sum - max);
}
