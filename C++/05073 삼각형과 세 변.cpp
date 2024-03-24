#include <iostream>
#include <algorithm>

int main(void)
{
    while (true)
    {
        int nums[3];

        std::cin >> nums[0] >> nums[1] >> nums[2];

        if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0)
        {
            break;
        }

        std::sort(nums, nums + 3);

        if (nums[0] + nums[1] <= nums[2])
        {
            std::cout << "Invalid\n";
        }
        else if (nums[0] == nums[1] && nums[1] == nums[2])
        {
            std::cout << "Equilateral\n";
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
        {
            std::cout << "Isosceles\n";
        }
        else
        {
            std::cout << "Scalene\n";
        }
    }
}
