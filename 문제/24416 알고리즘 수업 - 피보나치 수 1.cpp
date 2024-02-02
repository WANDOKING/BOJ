#include <iostream>

int recursiveCount = 0;
int DPCount = 0;

int FibRecursive(int n)
{
    if (n == 1 || n == 2) {
        recursiveCount++;
        return 1;
    }
    
    return FibRecursive(n - 1) + FibRecursive(n - 2);
}

int main(void)
{
    int n;
    
    scanf("%d", &n);
    
    int fibNums[41];
    
    fibNums[1] = 1;
    fibNums[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        fibNums[i] = fibNums[i - 1] + fibNums[i - 2];
        DPCount++;
    }
    
    FibRecursive(n);
    
    printf("%d %d", recursiveCount, DPCount);
}
