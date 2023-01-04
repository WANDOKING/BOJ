#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

#define MAX_N 100000

int g_nums[MAX_N];

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> g_nums[i];
	}

	std::sort(g_nums, g_nums + N);

	int index1 = 0;
	int index2 = N - 1;

	int resultIndex1 = INT_MAX;
	int resultIndex2 = INT_MAX;
	int minAbs = INT_MAX;

	while (index1 < index2)
	{
		int sum = g_nums[index2] + g_nums[index1];
		int abs = std::abs(sum);

		if (abs < minAbs)
		{
			resultIndex1 = index1;
			resultIndex2 = index2;
			minAbs = abs;
		}

		if (sum == 0)
		{
			break;
		}
		else if (sum < 0)
		{
			++index1;
		}
		else
		{
			--index2;
		}
	}

	std::cout << g_nums[resultIndex1] << ' ' << g_nums[resultIndex2];
}
