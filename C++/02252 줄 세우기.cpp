#include <iostream>
#include <queue>
#include <set>

#define MAX_N 32000

std::set<int> g_graph[MAX_N + 1];
int g_inDegrees[MAX_N + 1];
int g_result[MAX_N + 1];

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	std::cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int A;
		int B;

		std::cin >> A >> B;

		if (g_graph[A].insert(B).second == true)
		{
			g_inDegrees[B]++;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		g_graph[0].insert(i);
		g_inDegrees[i]++;
	}

	std::queue<int> zeroIndegrees;
	zeroIndegrees.push(0);

	int resultElementCount = 0;
	while (zeroIndegrees.empty() == false)
	{
		int vertex = zeroIndegrees.front();
		zeroIndegrees.pop();

		g_result[resultElementCount] = vertex;
		++resultElementCount;

		for (int neighbor : g_graph[vertex])
		{
			g_inDegrees[neighbor] -= 1;

			if (g_inDegrees[neighbor] == 0)
			{
				zeroIndegrees.push(neighbor);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		printf("%d ", g_result[i]);
	}
}
