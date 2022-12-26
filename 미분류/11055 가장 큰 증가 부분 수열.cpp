#include <iostream>

#define MAX_N 1000

int g_nums[MAX_N];
int g_dp[MAX_N];

int main(void)
{
	int N;

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> g_nums[i];
	}

	g_dp[0] = g_nums[0];
	int result = g_dp[0];

	for (int i = 1; i < N; ++i)
	{
		int max = 0;
		for (int j = 0; j < i; ++j)
		{
			if (g_nums[j] < g_nums[i] && g_dp[j] > max)
			{
				max = g_dp[j];
			}
		}
		g_dp[i] = max + g_nums[i];

		if (g_dp[i] > result)
		{
			result = g_dp[i];
		}
	}

	std::cout << result;
}
