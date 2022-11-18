#include <iostream>
#include <string>
#include <cmath>

#define MAX_N 1000

int g_dp[MAX_N + 1][MAX_N + 1];

int main(void)
{
	std::string input1;
	std::string input2;

	std::cin >> input1 >> input2;

	// LCS 초기화
	for (size_t i = 0; i <= input1.size(); ++i)
	{
		g_dp[0][i] = 0;
	}

	for (size_t i = 0; i <= input2.size(); ++i)
	{
		g_dp[i][0] = 0;
	}

	// LCS 시작
	for (size_t i = 1; i <= input1.size(); ++i)
	{
		for (size_t j = 1; j <= input2.size(); ++j)
		{
			// 점화식
			if (input1[i - 1] == input2[j - 1])
			{
				g_dp[i][j] = g_dp[i - 1][j - 1] + 1;
			}
			else
			{
				g_dp[i][j] = std::max(g_dp[i - 1][j], g_dp[i][j - 1]);
			}
		}
	}

	std::cout << g_dp[input1.size()][input2.size()];
}
