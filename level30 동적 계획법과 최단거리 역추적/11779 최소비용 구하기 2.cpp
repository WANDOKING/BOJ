#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <climits>

#define MAX_N 1000

int g_graph[MAX_N + 1][MAX_N + 1];

void GetShortestRouteRecursive(int n, const std::vector<int>& prevVertex, std::vector<int>& outResult)
{
    outResult.push_back(n);

    if (n == prevVertex[n])
    {
        std::reverse(outResult.begin(), outResult.end());
        return;
    }

    GetShortestRouteRecursive(prevVertex[n], prevVertex, outResult);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;

    std::cin >> n >> m;

    for (int i = 0; i <= MAX_N; ++i)
    {
        for (int j = 0; j <= MAX_N; ++j)
        {
            g_graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int v1;
        int v2;
        int weight;

        std::cin >> v1 >> v2 >> weight;

        if (weight < g_graph[v1][v2])
        {
            g_graph[v1][v2] = weight;
        }
    }

    int startVertex;
    int endVertex;

    std::cin >> startVertex >> endVertex;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> distanceSelect; // distance, vertex
    std::unordered_set<int> visited;

    std::vector<int> distances(n + 1);
    std::vector<int> prevVertex(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        distances[i] = INT_MAX;
        prevVertex[i] = i;
    }

    distances[startVertex] = 0;
    distanceSelect.push(std::make_pair(0, startVertex));

    while (distanceSelect.empty() == false)
    {
        int vertex = distanceSelect.top().second;
        distanceSelect.pop();

        if (vertex == endVertex)
        {
            break;
        }

        if (visited.find(vertex) != visited.end())
        {
            continue;
        }

        visited.insert(vertex);

        for (int i = 1; i <= n; ++i)
        {
            if (g_graph[vertex][i] == INT_MAX || distances[vertex] == INT_MAX)
            {
                continue;
            }

            if (g_graph[vertex][i] + distances[vertex] < distances[i])
            {
                distances[i] = g_graph[vertex][i] + distances[vertex];
                prevVertex[i] = vertex;

                if (visited.find(i) == visited.end())
                {
                    distanceSelect.push(std::make_pair(distances[i], i));
                }
            }
        }
    }

    std::vector<int> result;
    GetShortestRouteRecursive(endVertex, prevVertex, result);

    std::cout << distances[endVertex] << '\n';
    std::cout << result.size() << '\n';

    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i != 0)
        {
            std::cout << ' ';
        }

        std::cout << result[i];
    }
}
