#include <iostream>
#include <cstring>
#include <climits>

int main()
{
    const int MAX_NUM = 10000;
    bool bIsPrime[MAX_NUM + 1];
    
    memset(bIsPrime, true , sizeof(bool) * (MAX_NUM + 1));
    
    bIsPrime[1] = false;
    
    for (int i = 2; i <= MAX_NUM + 1; i++) {
        if (bIsPrime[i] == true) {
            for (int j = i * 2; j <= MAX_NUM + 1; j += i) {
                bIsPrime[j] = false;
            }
        }
    }
    
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        
        int minGap = INT_MAX;
        int minGapJ;
        for (int j = 2; j <= n / 2; j++) {
            if (bIsPrime[j] == false || bIsPrime[n - j] == false) {
                continue;
            }
            
            if ((n - j) - j < minGap) {
                minGap = (n - j) - j;
                minGapJ = j;
            }
        }
        
        printf("%d %d\n", minGapJ, n - minGapJ);
    }

    return 0;
}
