#include <iostream>

int main(void) {
    int T;
    
    scanf("%d" ,&T);
    
    for (int i = 0; i < T; i++) {
        int N;
        int M;
        
        scanf("%d %d", &N, &M);
        
        for (int j = 0; j < M; j++) {
            int a;
            int b;
            
            scanf("%d %d", &a, &b);
        }
        
        printf("%d\n", N - 1);
    }
}
