#include <iostream>
#include <climits>

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    // N의 진짜 약수가 모두 주어지므로 최소값과 최대값을 곱함
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        
        if (num < min) {
            min = num;
        }
        
        if (num > max) {
            max = num;
        }
    }
    
    printf("%d", max * min);
    
    return 0;
}
