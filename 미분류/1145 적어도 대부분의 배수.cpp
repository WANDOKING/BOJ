#include <iostream>
#include <climits>

int main(void)
{
    const int MAX = 5;
    int nums[MAX];
    
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &nums[i]);
    }
    
    for (int i = 1; i < INT_MAX; i++)
    {
        int count = 0;
        for (int j = 0; j < MAX; j++)
        {
            if (i % nums[j] == 0)
            {
                count++;
            }
        }
        
        if (count >= 3)
        {
            printf("%d", i);
            break;
        }
    }
}
