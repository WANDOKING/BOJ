#include <iostream>
#include <cstdlib>

int compare(const void* a, const void* b) {
    int num1 = *((int*)a);
    int num2 = *((int*)b);
    
    if (num1 == num2) {
        return 0;
    } else if (num1 > num2) {
        return 1;
    } else {
        return -1;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, N, sizeof(int), compare);
    
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        
        bool bFind = false;
        int start = 0;
        int end = N - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
        
            if (arr[mid] == target) {
                bFind = true;
                break;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        if (bFind == true) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    

    return 0;
}
