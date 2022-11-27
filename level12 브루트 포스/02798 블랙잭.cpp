#include <iostream>

int main()
{
    int N;
    int M;
    
    scanf("%d %d", &N, &M);
    
    int cards[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }
    
    int maxSum = -1;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                
                if (sum <= M && sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
    }
    
    printf("%d", maxSum);

    return 0;
}
