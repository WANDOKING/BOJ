#include <iostream>

#define MAX_CITY 100

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int graph[MAX_CITY][MAX_CITY] = { 0, };

    int n;
    int m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int start;
        int end;
        int cost;

        std::cin >> start >> end >> cost;

        if (graph[start - 1][end - 1] == 0 || graph[start - 1][end - 1] > cost)
        {
            graph[start - 1][end - 1] = cost;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (graph[i][k] == 0 || graph[k][j] == 0)
                {
                    continue;
                }

                if (graph[i][j] == 0 || graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << graph[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
