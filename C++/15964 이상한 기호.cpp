#include <iostream>

int main(void)
{
    long long A;
    long long B;
    
    scanf("%lld %lld", &A, &B);
    
    printf("%lld", (A + B) * (A - B));
    
    return 0;
}
