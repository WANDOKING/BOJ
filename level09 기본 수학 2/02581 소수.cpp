#include <stdio.h>
#include <cstring>

int main()
{
    const int MAX_NUM = 10000;
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
    
    scanf("%d", &M);
    scanf("%d", &N);
    
    int sum = 0;
    int minNum = 0;
    for (int i = M; i <= N; i++) {
        if (bIsPrime[i] == true) {
            sum += i;
            
            if (minNum == 0) {
                minNum = i;
            }
        }
    }
    
    if (minNum == 0) {
        printf("-1");
    } else {
        printf("%d\n%d", sum, minNum);
    }

    return 0;
}
