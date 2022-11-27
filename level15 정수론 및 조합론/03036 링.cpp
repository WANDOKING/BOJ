#include <iostream>

int GetGCD(int a, int b)
{
    int num1 = a > b ? a : b;
    int num2 = a > b ? b : a;
    
    while(num1 % num2 != 0)
    {
        int r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    
    return num2;
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int firstR;
    scanf("%d", &firstR);
    
    for (int i = 0; i < N - 1; i++)
    {
        int r;
        scanf("%d", &r);
        
        int gcd = GetGCD(firstR, r);
        
        printf("%d/%d\n", firstR / gcd, r / gcd);
    }

    return 0;
}
