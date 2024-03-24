#include <iostream>

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int A;
        int B;
        
        scanf("%d %d", &A, &B);
        
        int j = 1;
        while ((A * j) % B != 0) {
            j++;
        }
        
        printf("%d\n", A * j);
    }

    return 0;
}
