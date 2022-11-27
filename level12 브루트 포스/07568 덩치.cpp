#include <iostream>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int weights[N];
    int heights[N];
    int ranking[N];
    
    for (int i = 0; i < N; i++) {
        int x;
        int y;
        scanf("%d %d", &x, &y);
        
        weights[i] = x;
        heights[i] = y;
        ranking[i] = 1;
    }
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (weights[i] > weights[j] && heights[i] > heights[j]) {
                ranking[j]++;
            } else if (weights[i] < weights[j] && heights[i] < heights[j]) {
                ranking[i]++;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", ranking[i]);
    }

    return 0;
}
