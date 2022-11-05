#include <iostream>

#define MAX 100

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    short graph[MAX][MAX];

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (graph[i][j] == 1)
                {
                    continue;
                }

                if (graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                }
            }
        }
    }

        for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << graph[i][j] << ' ';
        }

        std::cout << '\n';
    }
}
