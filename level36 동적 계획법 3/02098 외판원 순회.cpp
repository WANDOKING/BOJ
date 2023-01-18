#include <iostream>
#include <stack>
#include <climits>

#define MAX_N 16

int g_graph[MAX_N][MAX_N];

// 방문 정보를 비트 필드로 표현
// 즉, g_costs[i][j] 는 i번 정점을 j방문기록 상태로 방문했을 때의 정보
// ex. g_costs[2][0x0003] 은 현재 2번 정점이고, 1번, 2번 정점을 방문한 상태에서의 최솟값
int g_costs[MAX_N][USHRT_MAX + 1];

struct DfsInfo
{
	int Cost;
	unsigned short VisitInfo;
	unsigned char Vertex;
};

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> g_graph[i][j];
		}
	}

	unsigned short visitAll = 0;
	for (int i = 0; i < N; ++i)
	{
		visitAll <<= 1;
		visitAll += 1;
	}

	std::stack<DfsInfo> s; // cost, visit info, vertex

	DfsInfo start;
	start.Cost = 0;
	start.VisitInfo = 0x0001;
	start.Vertex = 0;

	s.push(start);
	g_costs[start.Cost][start.VisitInfo] = 0;

	int result = INT_MAX;
	while (s.empty() == false)
	{
		int cost = s.top().Cost;
		unsigned short visited = s.top().VisitInfo;
		unsigned char vertex = s.top().Vertex;
		s.pop();

		for (int i = 0; i < N; ++i)
		{
			if (g_graph[vertex][i] == 0)
			{
				continue;
			}

			if ((visited & (0x0001 << i)) != 0)
			{
				continue;
			}

			if (g_costs[i][visited | (0x0001 << i)] != 0 && g_costs[i][visited | (0x0001 << i)] <= cost + g_graph[vertex][i])
			{
				continue;
			}

			DfsInfo next;
			next.Cost = cost + g_graph[vertex][i];
			next.VisitInfo = visited | (0x0001 << i);
			next.Vertex = i;

			g_costs[i][visited | (0x0001 << i)] = cost + g_graph[vertex][i];

			if ((visited | (0x0001 << i)) == visitAll)
			{
				if (g_graph[i][0] != 0 && g_costs[i][visitAll] + g_graph[i][0] < result)
				{
					result = g_costs[i][visitAll] + g_graph[i][0];
				}
			}
			else
			{
				s.push(next);
			}
		}
	}

	std::cout << result;
}
