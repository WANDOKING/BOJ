#include <iostream>
#include <cstdlib>

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
    int k;
    
    scanf("%d %d", &N, &k);
    
    int nums[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    
    qsort(nums, N, sizeof(int), compare);
    
    printf("%d", nums[k - 1]);

    return 0;
}
