#include <iostream>
#include <cstring>

int main()
{
    const int MAX_NUM = 1000000;
    
    // 편의를 위해 bIsPrime[0] 은 사용하지 않을 것
    bool bIsPrime[MAX_NUM + 1];
    
    memset(bIsPrime, true, sizeof(bool) * (MAX_NUM + 1));
    
    bIsPrime[1] = false;
    
    for (int i = 2; i <= MAX_NUM; i++) {
        if (bIsPrime[i] == true) {
            for (int j = i * 2; j <= MAX_NUM; j += i) {
                bIsPrime[j] = false;
            }
        }
    }
    
    int M;
    int N;
    
    scanf("%d %d", &M, &N);
    
    for (int i = M; i <= N; i++) {
        if (bIsPrime[i] == true) {
            printf("%d\n", i);
        }
    }

    return 0;
}
