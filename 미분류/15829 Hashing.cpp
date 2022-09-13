#include <iostream>
#include <cmath>

int main(void)
{
    int L;
    scanf("%d", &L);
    
    char s[L + 1];
    scanf("%s", s);
    
    long long H = 0;
    for (int i = 0; i < L; i++)
    {
        long long temp = (s[i] - 'a' + 1);
        
        for (int j = 0; j < i; j++)
        {
            temp *= 31;
            temp %= 1234567891;
        }
        
        H += temp;
    }
    
    H %= 1234567891;
    
    printf("%lld", H);
    
    return 0;
}
