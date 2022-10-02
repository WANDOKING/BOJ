#include <iostream>

int main(void)
{
    int nums[3];

    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);

    for (int i = 0; i < 3; i++)
    {
        int maxNum = 0;

        for (int j = 0; j < 2 - i; j++)
        {
            if (nums[j + 1] < nums[j])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    printf("%d %d %d", nums[0], nums[1], nums[2]);
}
