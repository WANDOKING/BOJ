#include <iostream>
#include <climits>

#define MAX_N 1000

int g_graph[MAX_N + 1][MAX_N + 1];

int main(void)
{
	int N;
	int M;
	int X;

	std::cin >> N >> M >> X;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
			{
				g_graph[i][j] = 0;
			}
			else
			{
				g_graph[i][j] = INT_MAX;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int start;
		int end;
		int weight;

		std::cin >> start >> end >> weight;

		g_graph[start][end] = weight;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (g_graph[i][k] == INT_MAX || g_graph[k][j] == INT_MAX)
				{
					continue;
				}

				if (g_graph[i][k] + g_graph[k][j] < g_graph[i][j])
				{
					g_graph[i][j] = g_graph[i][k] + g_graph[k][j];
				}
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (g_graph[i][X] + g_graph[X][i] > max)
		{
			max = g_graph[i][X] + g_graph[X][i];
		}
	}

	std::cout << max;
}
