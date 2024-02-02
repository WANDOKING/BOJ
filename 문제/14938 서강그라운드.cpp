#include <iostream>
#include <unordered_set>
#include <queue>

#define MAX_AREA_COUNT 100

int g_countItems[MAX_AREA_COUNT + 1];
int g_graph[MAX_AREA_COUNT + 1][MAX_AREA_COUNT + 1];

int n;
int m;

int GetMaxItemCount(int startVertexNum)
{
    int result = 0;

    std::queue<std::pair<int, int>> q; // vertex, distance
    std::unordered_set<int> visited;

    q.push(std::make_pair(startVertexNum, 0));

    while (q.empty() == false)
    {
        int vertex = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (distance > m)
        {
            continue;
        }

        if (visited.find(vertex) == visited.end())
        {
            result += g_countItems[vertex];
            visited.insert(vertex);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (g_graph[vertex][i] == 0)
            {
                continue;
            }

            q.push(std::make_pair(i, distance + g_graph[vertex][i]));
        }
    }

    return result;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int r;

    std::cin >> n >> m >> r;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> g_countItems[i];
    }

    for (int i = 0; i < r; ++i)
    {
        int v1;
        int v2;
        int weight;

        std::cin >> v1 >> v2 >> weight;

        g_graph[v1][v2] = weight;
        g_graph[v2][v1] = weight;
    }

    int result = -1;
    for (int i = 1; i <= n; ++i)
    {
        int itemCount = GetMaxItemCount(i);

        if (itemCount > result)
        {
            result = itemCount;
        }
    }

    std::cout << result;
}
