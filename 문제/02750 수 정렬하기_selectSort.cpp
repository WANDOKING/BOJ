#include <iostream>
#include <climits>

void SelectSort(int nums[], size_t length)
{
    for (int i = 0; i < length; i++) {
        int min = INT_MAX;
        int minIndex = -1;
        
        for (int j = i; j < length; j++) {
            if (nums[j] < min) {
                min = nums[j];
                minIndex = j;
            }
        }
        
        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp;
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
    
    SelectSort(nums, N);
    
    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}
