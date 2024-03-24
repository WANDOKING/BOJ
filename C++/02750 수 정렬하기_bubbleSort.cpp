#include <iostream>

void BubbleSort(int nums[], size_t length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    
    BubbleSort(nums, N);
    
    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}
