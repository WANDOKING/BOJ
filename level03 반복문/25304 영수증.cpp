#include <iostream>

int main()
{
    int X;
    int N;
    
    scanf("%d", &X);
    scanf("%d", &N);
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        int b;
        
        scanf("%d %d", &a, &b);
        
        sum += a * b;
    }
    
    if (sum == X) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
