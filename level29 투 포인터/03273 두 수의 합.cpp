#include <iostream>
#include <algorithm>

#define MAX_N 100000

int g_nums[MAX_N];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> g_nums[i];
    }
    
    int x;
    std::cin >> x;

    std::sort(g_nums, g_nums + n);

    int index1 = 0;
    int index2 = n - 1;

    int result = 0;
    while (index1 < index2)
    {
        int sum = g_nums[index1] + g_nums[index2];

        if (sum == x)
        {
            ++result;
        }

        if (sum <= x)
        {
            ++index1;
        }
        else
        {
            --index2;
        }
    }

    std::cout << result;
}
