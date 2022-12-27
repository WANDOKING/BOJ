#include <iostream>
#include <unordered_set>

#define MAX_N 100000

int g_select[MAX_N + 1];
bool g_bVisited[MAX_N + 1];

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		int n;
		std::cin >> n;

		int result = n;

		for (int i = 1; i <= n; ++i)
		{
			std::cin >> g_select[i];

			if (g_select[i] == i)
			{
				g_bVisited[i] = true;
				result--;
			}
			else
			{
				g_bVisited[i] = false;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			if (g_bVisited[i] == true)
			{
				continue;
			}

			// DFS
			std::unordered_set<int> visited;
			int visit = i;
			bool bCanBeTeam;

			while (true)
			{
				if (visited.find(visit) != visited.end())
				{
					bCanBeTeam = true;
					break;
				}

				if (g_bVisited[visit] == true)
				{
					bCanBeTeam = false;
					break;
				}

				visited.insert(visit);
				g_bVisited[visit] = true;
				visit = g_select[visit];
			}

			// 사이클을 찾았다면, 사이클에 포함된 정점의 수만큼 결과값에서 빼준다
			if (bCanBeTeam == true)
			{
				std::unordered_set<int> teamVisited;

				while (teamVisited.find(visit) == teamVisited.end())
				{
					teamVisited.insert(visit);
					visit = g_select[visit];
					result--;
				}
			}
		}

		std::cout << result << '\n';
	}
}
