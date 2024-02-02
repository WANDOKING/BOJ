#include <iostream>
#include <climits>

#define MAX_N 800

int g_graph[MAX_N + 1][MAX_N + 1];

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	for (int i = 1; i <= MAX_N; ++i)
	{
		for (int j = 1; j <= MAX_N; ++j)
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

	int N;
	int E;

	std::cin >> N >> E;

	for (int i = 0; i < E; ++i)
	{
		int a;
		int b;
		int c;

		std::cin >> a >> b >> c;

		g_graph[a][b] = c;
		g_graph[b][a] = c;
	}

	int v1;
	int v2;

	std::cin >> v1 >> v2;

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

	// 나올 수 있는 두 가지 경로
	int distance1;
	if (g_graph[1][v1] == INT_MAX || g_graph[v1][v2] == INT_MAX || g_graph[v2][N] == INT_MAX)
	{
		distance1 = INT_MAX;
	}
	else
	{
		distance1 = g_graph[1][v1] + g_graph[v1][v2] + g_graph[v2][N];
	}

	int distance2;
	if (g_graph[1][v2] == INT_MAX || g_graph[v2][v1] == INT_MAX || g_graph[v1][N] == INT_MAX)
	{
		distance2 = INT_MAX;
	}
	else
	{
		distance2 = g_graph[1][v2] + g_graph[v2][v1] + g_graph[v1][N];
	}
	 
	int result = std::min(distance1, distance2);
	if (result == INT_MAX)
	{
		std::cout << "-1";
	}
	else
	{
		std::cout << result;
	}
	
}
