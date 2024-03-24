#include <iostream>
#include <unordered_set>
#include <queue>
#include <climits>

#define MAX_N 1000

int g_graph[MAX_N + 1][MAX_N + 1];
int g_minDistances[MAX_N + 1];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    for (int i = 0; i <= MAX_N; ++i)
    {
        for (int j = 0; j <= MAX_N; ++j)
        {
            g_graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i <= MAX_N; ++i)
    {
        g_minDistances[i] = INT_MAX;
    }

    int N;
    int M;
    int startVertex;
    int endVertex;

    std::cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int start;
        int end;
        int weight;

        std::cin >> start >> end >> weight;

        if (weight < g_graph[start][end])
        {
            g_graph[start][end] = weight;
        }
    }

    std::cin >> startVertex >> endVertex;

    g_minDistances[startVertex] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> distanceSelect;
    std::unordered_set<int> visited;

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

        // neighbors
        for (int i = 1; i <= MAX_N; ++i)
        {
            if (g_graph[vertex][i] == INT_MAX)
            {
                continue;
            }

            int newDistance = g_graph[vertex][i] + g_minDistances[vertex];

            if (newDistance < g_minDistances[i])
            {
                g_minDistances[i] = newDistance;
                
                if (visited.find(i) == visited.end())
                {
                    distanceSelect.push(std::make_pair(newDistance, i));
                }
            }
        }
    }

    std::cout << g_minDistances[endVertex];
}
