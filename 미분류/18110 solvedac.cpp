#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int nums[300'000];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;

    std::cin >> n;

    if (n == 0)
    {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    std::sort(nums, nums + n);

    int excludeCount = std::round(n * 0.15);
    int sum = 0;

    for (int i = excludeCount; i < n - excludeCount; ++i)
    {
        sum += nums[i];
    }

    std::cout << (int)round((float)sum / (n - excludeCount * 2));

    return 0;
}
