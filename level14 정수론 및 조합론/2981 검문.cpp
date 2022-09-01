#include <iostream>
#include <cmath>

int GetGCD(int a, int b)
{
    int num1 = a > b ? a : b;
    int num2 = a > b ? b : a;
    
    while (num1 % num2 != 0)
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
    
    int num1;
    int num2;
    
    scanf("%d", &num1);
    scanf("%d", &num2);
    int prevNum = num2;
    int gcd = abs(num1 - num2); // 차들의 최대공약수
    for (int i = 2; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        
        gcd = GetGCD(abs(num - prevNum), gcd);
    }
    
    // 최대공약수의 약수들을 구해서 출력
    
    int divs[(int)sqrt(gcd)];     // 약수들
    int divsCount = 0; // 약수들의 개수
    
    // sqrt까지의 약수를 구함
    for (int i = 1; i <= sqrt(gcd); i++)
    {
        if (gcd % i == 0)
        {
            divs[divsCount] = i; 
            divsCount++;
        }
    }
    
    for (int i = 1; i < divsCount; i++)
    {
        printf("%d ", divs[i]);
    }
     
    int temp = divsCount;
    for (int i = temp - 1; i >= 0; i--)
    {
        if (gcd / divs[i] == divs[temp - 1])
        {
            continue;
        }
        
        printf("%d ", gcd / divs[i]);
    }

    return 0;
}
