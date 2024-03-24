#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		int costTimes[MAX_N + 1];
		int dp[MAX_N + 1];
		int inDegrees[MAX_N + 1] = { 0, };
		bool graph[MAX_N + 1][MAX_N + 1] = { false, };

		int N;
		int K;
		std::cin >> N >> K;

		for (int i = 1; i <= N; ++i)
		{
			std::cin >> costTimes[i];
			dp[i] = costTimes[i];
		}

		for (int i = 0; i < K; ++i)
		{
			int v1;
			int v2;

			std::cin >> v1 >> v2;

			graph[v1][v2] = true;
			inDegrees[v2]++;
		}

		int W;
		std::cin >> W;

		while (true)
		{
			for (int i = 1; i <= N; ++i)
			{
				if (inDegrees[i] != 0)
				{
					continue;
				}

				inDegrees[i] = -1;

				// 진입차수가 0인 노드에 대해
				for (int j = 1; j <= N; ++j)
				{
					if (graph[i][j] == true)
					{
						if (dp[j] < dp[i] + costTimes[j])
						{
							dp[j] = dp[i] + costTimes[j];
						}

						graph[i][j] = false;
						inDegrees[j]--;
					}
				}

				if (i == W)
				{
					goto END_OF_TEST_CASE;
				}
				
				break;
			}
		}

	END_OF_TEST_CASE:
		std::cout << dp[W] << '\n';
	}
}
