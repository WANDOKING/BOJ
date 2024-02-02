#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>

#define MAX_V 10000

std::vector<int> g_graph[MAX_V + 1];  // G
std::vector<int> g_graphT[MAX_V + 1]; // GT

// DFS 후위 순회
void DfsPostorderRecursive(int visit, std::unordered_set<int>& visited, std::vector<int>& dfsPostorder)
{
	for (int neighbor : g_graph[visit])
	{
		if (visited.find(neighbor) == visited.end())
		{
			visited.insert(neighbor);
			DfsPostorderRecursive(neighbor, visited, dfsPostorder);
		}
	}

	dfsPostorder.push_back(visit);
}

int main(void)
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int V;
	int E;

	std::cin >> V >> E;

	for (int i = 0; i < E; ++i)
	{
		int v1;
		int v2;

		std::cin >> v1 >> v2;

		g_graph[v1].push_back(v2);
		g_graphT[v2].push_back(v1);
	}

	// 모든 정점에 대해 DFS 후위 순회한 결과를 얻는다.
	std::vector<int> dfsPostorder;
	{
		std::unordered_set<int> visited;

		for (int i = 1; i <= V; ++i)
		{
			if (visited.find(i) != visited.end())
			{
				continue;
			}

			visited.insert(i);
			DfsPostorderRecursive(i, visited, dfsPostorder);
		}
	}

	// 역순으로 뒤집기
	std::reverse(dfsPostorder.begin(), dfsPostorder.end());

	// 위에서 얻은 reversed dfsPostorder 순서대로 각 정점에 대해 DFS 수행 -> SCC
	std::vector<std::pair<int, std::vector<int>>> sccs;
	{
		std::unordered_set<int> visited;

		for (int vertex : dfsPostorder)
		{
			if (visited.find(vertex) != visited.end())
			{
				continue;
			}

			std::stack<int> s;
			std::vector<int> dfsResult;

			s.push(vertex);

			while (s.empty() == false)
			{
				int visit = s.top();
				s.pop();

				if (visited.find(visit) != visited.end())
				{
					continue;
				}

				dfsResult.push_back(visit);
				visited.insert(visit);

				for (int neighbor : g_graphT[visit])
				{
					s.push(neighbor);
				}
			}

			std::sort(dfsResult.begin(), dfsResult.end());
			sccs.push_back(std::make_pair(dfsResult.front(), dfsResult));
		}
	}

	std::sort(sccs.begin(), sccs.end());

	std::cout << sccs.size() << '\n';
	for (auto& scc : sccs)
	{
		for (int vertex : scc.second)
		{
			std::cout << vertex << ' ';
		}
		std::cout << "-1\n";
	}
}
