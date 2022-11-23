#include <iostream>
#include <vector>

#define MAX_M 1000

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	std::cin >> N >> M;
	
	long long countModNums[MAX_M] = { 0, };
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int inputNum;
		std::cin >> inputNum;

		sum = (sum + inputNum) % M;
		countModNums[sum]++;
	}

	long long result = 0;
	for (int i = 0; i < M; i++)
	{
		result += (countModNums[i] * (countModNums[i] - 1)) / 2;
	}
	result += countModNums[0];

	std::cout << result;
}
