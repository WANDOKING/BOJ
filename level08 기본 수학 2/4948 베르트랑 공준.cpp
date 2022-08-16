#include <iostream>
#include <cstring>

int main()
{
    const int MAX_NUM = 123456;
    bool bIsPrime[MAX_NUM * 2 + 1];
    
    memset(bIsPrime, true , sizeof(bool) * (MAX_NUM * 2 + 1));
    
    bIsPrime[1] = false;
    
    for (int i = 2; i <= MAX_NUM * 2 + 1; i++) {
        if (bIsPrime[i] == true) {
            for (int j = i * 2; j <= MAX_NUM * 2 + 1; j += i) {
                bIsPrime[j] = false;
            }
        }
    }
    
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        
        int count = 0;
        for (int i = n + 1; i <= n * 2; i++) {
            if (bIsPrime[i] == true) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }

    return 0;
}
