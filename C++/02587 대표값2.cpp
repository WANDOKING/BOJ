#include <iostream>
#include <algorithm>

#define MAX 5

int main(void)
{
    int nums[MAX];
    int sum = 0;
    
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", nums + i);
        sum += nums[i];
    }
    
    std::sort(nums, nums + MAX);
    
    printf("%d\n", sum / MAX);
    printf("%d\n", nums[MAX / 2]);
}
