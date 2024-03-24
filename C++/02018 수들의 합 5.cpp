#include <iostream>

int main(void)
{
	int N;

	std::cin >> N;

	int result = 0;

	// Two Pointer
	int start = 1;
	int end = 1;
	int sum = 1;

	while (start <= end)
	{
		if (sum == N)
		{
			result++;
		}

		if (sum < N)
		{
			end++;
			sum += end;
		}
		else
		{
			sum -= start;
			start++;
		}
	}

	std::cout << result;
}
