#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

#define MAX_N 100000

int g_parents[MAX_N + 1];
std::vector<int> g_graph[MAX_N + 1];

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 1; i < N; i++)
	{
		int v1;
		int v2;

		std::cin >> v1 >> v2;

		g_graph[v1].push_back(v2);
		g_graph[v2].push_back(v1);
	}

	std::queue<int> q;
	q.push(1);

	std::unordered_set<int> visited;

	while (q.empty() == false)
	{
		int visit = q.front();
		q.pop();

		if (visited.find(visit) != visited.end())
		{
			continue;
		}

		visited.insert(visit);

		for (int neighbor : g_graph[visit])
		{
			if (visited.find(neighbor) != visited.end())
			{
				continue;
			}

			g_parents[neighbor] = visit;
			q.push(neighbor);
		}
	}

	for (int i = 2; i <= N; i++)
	{
		std::cout << g_parents[i] << '\n';
	}
}
