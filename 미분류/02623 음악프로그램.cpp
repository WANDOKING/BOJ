#include <iostream>
#include <vector>
#include <set>
#include <queue>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    size_t N;
    int M;

    std::cin >> N >> M;

    std::vector<int> inDegrees;
    std::vector<std::set<int>> graph;
    inDegrees.reserve(N + 1);
    graph.reserve(N + 1);

    for (int i = 0; i <= N; ++i)
    {
        inDegrees.push_back(0);
        graph.push_back(std::set<int>());

        // 아무 PD도 담당하지 않는 가수가 있는 입력도 주어진다...
        if (i != 0)
        {
            graph[0].insert(i);
            inDegrees[i]++;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int count;
        std::cin >> count;

        int startVertex = 0;
        for (int j = 0; j < count; ++j)
        {
            int endVertex;
            std::cin >> endVertex;

            if (startVertex == endVertex)
            {
                continue;
            }

            else if (graph[startVertex].find(endVertex) == graph[startVertex].end())
            {
                graph[startVertex].insert(endVertex);
                inDegrees[endVertex]++;
            }

            startVertex = endVertex;
        }
    }

    std::queue<int> zeroInDegreesVertex;
    std::vector<int> result;
    zeroInDegreesVertex.push(0);

    while (zeroInDegreesVertex.empty() == false)
    {
        int vertex = zeroInDegreesVertex.front();
        zeroInDegreesVertex.pop();

        if (vertex != 0)
        {
            result.push_back(vertex);
        }

        for (const int neighbor : graph[vertex])
        {
            inDegrees[neighbor]--;

            if (inDegrees[neighbor] == 0)
            {
                zeroInDegreesVertex.push(neighbor);
            }
        }

        graph[vertex].clear();
    }

    if (result.size() == N)
    {
        for (int vertex : result)
        {
            std::cout << vertex << '\n';
        }
    }
    else
    {
        std::cout << 0;
    }
}
