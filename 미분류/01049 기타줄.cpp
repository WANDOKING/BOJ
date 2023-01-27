#include <iostream>
#include <climits>
#include <cmath>

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	std::cin >> N >> M;

	int minPackageCost = INT_MAX;
	int minSingleCost = INT_MAX;

	for (int i = 0; i < M; ++i)
	{
		int packageCost;
		int singleCost;
		std::cin >> packageCost >> singleCost;

		if (packageCost < minPackageCost)
		{
			minPackageCost = packageCost;
		}

		if (singleCost < minSingleCost)
		{
			minSingleCost = singleCost;
		}
	}

	int result = 0;

	if (N >= 6)
	{
		int needPackageCount = N / 6;
		int minCost = std::min(minPackageCost, minSingleCost * 6) * needPackageCount;

		result += minCost;
		N -= needPackageCount * 6;
	}

	int needSingleCount = N;
	int minCost = std::min(minPackageCost, minSingleCost * needSingleCount);
	result += minCost;

	std::cout << result;
}
