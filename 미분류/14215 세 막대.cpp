#include <iostream>
#include <algorithm>

int main(void)
{
    int nums[3];

    std::cin >> nums[0] >> nums[1] >> nums[2];

    std::sort(nums, nums + 3);

    if (nums[0] + nums[1] <= nums[2])
    {
        nums[2] -= nums[2] - nums[0] - nums[1] + 1;
    }

    std::cout << nums[0] + nums[1] + nums[2];
}
