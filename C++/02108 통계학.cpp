#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cmath>

int compare(const void* a, const void* b)
{
    int num1 = *((int*)a);
    int num2 = *((int*)b);
    
    if (num1 == num2) {
        return 0;
    } else if (num1 > num2) {
        return -1;
    } else {
        return 1;
    }
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int nums[N];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    
    int average = round((float)sum / N);
    
    qsort(nums, N, sizeof(int), compare);
    
    int median = nums[N / 2];
    
    int mode;
    int modeSecond;
    int modeCount = 0;
    for (int i = 0; i < N; ) {
        int count = 1;
        int j;
        for (j = i; j < N; j++) {
            if (nums[j] == nums[i]) {
                count++;
            } else {
                break;
            }
        }
        
        if (count > modeCount) {
            mode = nums[i];
            modeCount = count;
            modeSecond = INT_MIN;
        } else if (count == modeCount) {
            modeSecond = mode;
            mode = nums[i];
        }
        
        i = j;
    }
    
    if (modeSecond != INT_MIN) {
        mode = modeSecond;
    }
    
    int range = nums[0] - nums[N - 1];
    
    printf("%d\n", average);
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);

    return 0;
}
