#include <iostream>
#include <algorithm>

int main(void)
{
	const int COUNT = 9;

	int nums[COUNT];

	for (int i = 0; i < COUNT; ++i)
	{
		std::cin >> nums[i];
	}

	std::sort(nums, nums + COUNT);

	for (int excludeIndex1 = 0; excludeIndex1 < COUNT - 1; ++excludeIndex1)
	{
		for (int excludeIndex2 = excludeIndex1 + 1; excludeIndex2 < COUNT; ++excludeIndex2)
		{
			int sum = 0;

			for (int i = 0; i < COUNT; ++i)
			{
				if (i == excludeIndex1 || i == excludeIndex2)
				{
					continue;
				}

				sum += nums[i];
			}

			if (sum == 100)
			{
				for (int i = 0; i < COUNT; ++i)
				{
					if (i == excludeIndex1 || i == excludeIndex2)
					{
						continue;
					}

					std::cout << nums[i] << '\n';
				}
				return 0;
			}
		}
	}
}
