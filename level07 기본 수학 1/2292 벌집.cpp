#include <iostream>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    if (N == 1) {
        printf("%d", 1);
        return 0;
    }
    
    int k = 2;
    while (true) {
        // 점화식 - 망원급수
        int temp = 3 * (k - 2) * (k - 1) + 2;
        
        if (N < temp) {
            printf("%d", k - 1);
            break;
        }
        
        k++;
    }

    return 0;
}
