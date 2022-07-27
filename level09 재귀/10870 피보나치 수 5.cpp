#include <iostream>

int FibRecursive(int n)
{
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }
    
    return FibRecursive(n - 1) + FibRecursive(n -2);
}

int main()
{
    int n;
    
    scanf("%d", &n);
    
    printf("%d", FibRecursive(n));

    return 0;
}
