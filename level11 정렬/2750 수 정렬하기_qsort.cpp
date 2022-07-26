#include <iostream>
#include <cstdlib>

int compare(const void* a, const void* b)
{
    int num1 = *((int*)a);
    int num2 = *((int*)b);
    
    return num1 - num2;
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
    
    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }
}
