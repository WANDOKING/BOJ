#include <iostream>
#include <vector>

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

		// input
		std::vector<int> nums[2];
		nums[0].reserve(n);
		nums[1].reserve(n);

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int num;
				std::cin >> num;
				nums[i].push_back(num);
			}
		}

		// n == 1 일때의 처리
		if (n == 1)
		{
			std::cout << std::max(nums[0][0], nums[1][0]) << '\n';
			continue;
		}

		// dp
		std::vector<int> dp[2];
		dp[0].reserve(n);
		dp[1].reserve(n);

		dp[0].push_back(nums[0][0]);
		dp[1].push_back(nums[1][0]);

		dp[0].push_back(dp[1][0] + nums[0][1]);
		dp[1].push_back(dp[0][0] + nums[1][1]);

		int max = std::max(dp[0][1], dp[1][1]);

		for (int i = 2; i < n; ++i)
		{
			dp[0].push_back(std::max(dp[1][i - 1], dp[1][i - 2]));
			dp[0][i] += nums[0][i];

			if (dp[0][i] > max)
			{
				max = dp[0][i];
			}

			dp[1].push_back(std::max(dp[0][i - 1], dp[0][i - 2]));
			dp[1][i] += nums[1][i];

			if (dp[1][i] > max)
			{
				max = dp[1][i];
			}
		}

		std::cout << max << '\n';
	}
}
