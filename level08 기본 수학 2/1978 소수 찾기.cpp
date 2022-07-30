#include <iostream>
#include <cmath>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int countPrime = 0;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        
        if (num == 1) {
            continue;
        }
        
        double sqrtNum = sqrt(num);
        for (int j = 2; j <= sqrtNum; j++) {
            if (num % j == 0) {
                goto NEXT;
            }
        }
        
        countPrime++;
        
    NEXT:;
    }
    
    printf("%d", countPrime);

    return 0;
}
