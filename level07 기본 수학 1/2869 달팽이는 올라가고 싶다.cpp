#include <iostream>

int main()
{
    int A;
    int B;
    int V;
    
    scanf("%d %d %d", &A, &B, &V);
    
    // (A - B)(T - 1) + A >= V
    int result = (V - A) / (A - B) + 1;
    
    if ((V - A) % (A - B) != 0) {
        result++;
    }
    
    printf("%d", result);

    return 0;
}
