#include <iostream>
#include <climits>

#define MAX_N 100000

int g_sums[MAX_N + 1]; // 누적합 계산 편의를 위해 g_sums[0]을 그냥 0으로 둘 것

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int S;

	std::cin >> N >> S;

	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		int num;
		std::cin >> num;
		sum += num;
		g_sums[i] = sum;
	}

	int start = 1;
	int end = 1;
	int minLength = INT_MAX;
	while (end <= N)
	{
		int prefixSum = g_sums[end] - g_sums[start - 1];

		if (prefixSum >= S)
		{
			int length = end - start + 1;

			if (length < minLength)
			{
				minLength = length;
			}

			start++;
		}
		else
		{
			end++;
		}
	}

	if (minLength == INT_MAX)
	{
		std::cout << 0;
	}
	else
	{
		std::cout << minLength;
	}
}
