#include <iostream>
#include <queue>
#include <unordered_set>

#define MAX_N 10000

unsigned char g_graph[MAX_N + 1][MAX_N + 1];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    // input
    for (int i = 0; i < n - 1; ++i)
    {
        int v1;
        int v2;
        int weight;

        std::cin >> v1 >> v2 >> weight;

        g_graph[v1][v2] = weight;
        g_graph[v2][v1] = weight;
    }

    // 트리의 지름 : 최장거리 한 번, 최장거리에서 한 번 더 총 2번 수행
    int bfsStartVertex = 1;
    int maxLength = -1;
    int maxLengthVertex = -1;
    for (int i = 0; i < 2; i++)
    {
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(bfsStartVertex, 0));

        std::unordered_set<int> visited;

        maxLength = -1;
        maxLengthVertex = -1;
        while (q.empty() == false)
        {
            int visit = q.front().first;
            int weight = q.front().second;
            q.pop();

            if (visited.find(visit) != visited.end())
            {
                continue;
            }

            visited.insert(visit);

            if (weight > maxLength)
            {
                maxLength = weight;
                maxLengthVertex = visit;
            }

            for (int j = 1; j <= n; ++j)
            {
                if (g_graph[visit][j] == 0)
                {
                    continue;
                }

                q.push(std::make_pair(j, weight + g_graph[visit][j]));
            }
        }

        bfsStartVertex = maxLengthVertex;
    }

    std::cout << maxLength;
    
}
