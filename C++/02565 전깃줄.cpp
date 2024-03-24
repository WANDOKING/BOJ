#include <iostream>
#include <vector>

#define MAX_WIRE_NUM 500

int main(void)
{
    int countWire;
    std::cin >> countWire;

    int linkedWireNum[MAX_WIRE_NUM + 1] = { 0, };
    for (int i = 0; i < countWire; i++)
    {
        int wireStart;
        int wireEnd;

        std::cin >> wireStart >> wireEnd;

        linkedWireNum[wireStart] = wireEnd;
    }

    std::vector<int> nums;
    nums.reserve(countWire);
    for (int i = 1; i <= MAX_WIRE_NUM; i++)
    {
        if (linkedWireNum[i] == 0)
        {
            continue;
        }

        nums.push_back(linkedWireNum[i]);
    }

    // LIS
    std::vector<int> dp;
    dp.reserve(countWire);
    int lisLength = 0;
    for (int i = 0; i < countWire; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && dp[j] > max)
            {
                max = dp[j];
            }
        }

        if (max + 1 > lisLength)
        {
            lisLength = max + 1;
        }

        dp.push_back(max + 1);
    }

    std::cout << (countWire - lisLength);
}
