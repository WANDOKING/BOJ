#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int V;

	std::cin >> V;

	std::vector<std::unordered_map<int, int>> graph;
	graph.reserve(V + 1);

	for (int i = 0; i <= V; i++)
	{
		graph.push_back(std::unordered_map<int, int>());
	}

	for (int i = 0; i < V; i++)
	{
		int vStart;
		std::cin >> vStart;

		while (true)
		{
			int vEnd;
			int distance;

			std::cin >> vEnd;

			if (vEnd == -1)
			{
				break;
			}

			std::cin >> distance;
			graph[vStart].insert(std::make_pair(vEnd, distance));
		}
	}

	// Dfs를 두 번 할 것.
	// 처음에는 임의의 정점에서 DFS를 한 번 해 가장 멀리 있는 정점을 찾는다
	// 두 번째 루프에서는 첫 번째에서 찾은 가장 먼 정점에 대해서 가장 먼 거리를 찾는다
	int startVertex = 1; // 임의의 정점
	int maxDistance = -1;
	for (int i = 0; i < 2; i++)
	{
		std::stack<std::pair<int, int>> s;
		s.push(std::make_pair(startVertex, 0));

		std::unordered_set<int> visited;

		while (s.empty() == false)
		{
			int vertex = s.top().first;
			int distance = s.top().second;
			s.pop();

			if (visited.find(vertex) != visited.end())
			{
				continue;
			}

			visited.insert(vertex);

			if (distance > maxDistance)
			{
				startVertex = vertex;
				maxDistance = distance;
			}

			for (auto neighbor : graph[vertex])
			{
				s.push(std::make_pair(neighbor.first, distance + neighbor.second));
			}
		}
	}

	std::cout << maxDistance;
}
