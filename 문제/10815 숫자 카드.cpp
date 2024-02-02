#include <iostream>
#include <cstdlib>

int compare(const void* a, const void* b)
{
    int num1 = *((int*)a);
    int num2 = *((int*)b);
    
    if (num1 > num2) {
        return 1;
    } else if (num1 < num2) {
        return -1;
    } else {
        return 0;
    }
}

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, N, sizeof(int), compare);
    
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        
        bool bHasCard = false;
        int start = 0;
        int end = N - 1;
        
        // binary search : log(n)
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] == target) {
                bHasCard = true;
                break;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        if (bHasCard) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
}
