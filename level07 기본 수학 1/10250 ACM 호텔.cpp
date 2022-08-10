#include <iostream>

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int H;
        int W;
        int N;
        
        scanf("%d %d %d", &H, &W, &N);
        
        // (N - 1) % H + 1 층
        // (N - 1) / H + 1 호
        printf("%d%02d\n", (N - 1) % H + 1, (N - 1) / H + 1);
    }

    return 0;
}
