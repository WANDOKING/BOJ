#include <iostream>

void printHanoiRecursive(int N, int from, int to) {
    if (N == 1) {
        printf("%d %d\n", from, to);
        return;
    }
    
    int temp = 6 - from - to;
    printHanoiRecursive(N - 1, from, temp);
    printf("%d %d\n", from, to);
    printHanoiRecursive(N - 1, temp, to);
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int K = 1;
    for (int i = 1; i < N; i++) {
        K = K*2 + 1;
    }
    printf("%d\n", K);
    printHanoiRecursive(N, 1, 3);

    return 0;
}
