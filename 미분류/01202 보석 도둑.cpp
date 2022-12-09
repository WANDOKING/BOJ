#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

int main(void)
{
	int N;
	int K;

	std::cin >> N >> K;

	std::vector<std::pair<int, int>> jewels;
	std::vector<int> bags;

	for (int i = 0; i < N; ++i)
	{
		int weight;
		int value;

		std::cin >> weight >> value;

		jewels.push_back(std::make_pair(weight, value));
	}

	for (int j = 0; j < K; ++j)
	{
		int bagMaxWeight;

		std::cin >> bagMaxWeight;

		bags.push_back(bagMaxWeight);
	}

	// 무게 순으로 오름차순 정렬
	std::sort(jewels.begin(), jewels.end());
	std::sort(bags.begin(), bags.end());

	long long result = 0;
	std::priority_queue<int> jewelValues;

	int j = 0;
	int currentWeight = INT_MAX;
	int weight = INT_MAX;
	int value = INT_MAX;
	for (size_t i = 0; i < bags.size(); ++i)
	{
		int bagMaxWeight = bags[i];

		while (j < jewels.size())
		{
			weight = jewels[j].first;
			value = jewels[j].second;

			if (weight > bagMaxWeight && jewelValues.empty() == false)
			{
				break;
			}
			else
			{
				currentWeight = weight;
				jewelValues.push(value);
			}
			++j;
		}

		// 지금까지 얻어낸 보석 가치들 중 가장 높은 것을 가방에 담음
		if (jewelValues.empty() == false && currentWeight <= bagMaxWeight)
		{
			result += jewelValues.top();
			jewelValues.pop();
		}
	}

	std::cout << result;
}
