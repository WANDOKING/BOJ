#include <iostream>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    for (int i = 2; i <= N; i++) {
        while (N % i == 0) {
            printf("%d\n", i);
            N /= i;
        }
    }

    return 0;
}
