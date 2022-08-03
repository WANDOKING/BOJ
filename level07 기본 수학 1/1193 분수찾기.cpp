#include <iostream>

int main()
{
    int X;
    
    scanf("%d", &X);
    
    int sumAB = 2; // a와 b의 합
    int x = 1;     // x_(k-1) + 1 ~ x_k의 sumAB_k
    while (true) {
        
        if (x >= X) {
            break;
        }
        
        x += sumAB;
        sumAB++;
    }
    
    // a + b = sumAB인 가장 작은 x부터 루프를 돈다
    int a = sumAB - 1; 
    int b = 1;
    for (int i = x - sumAB + 2; i < X; i++) {
        a--;
        b++;
    }
    
    // a + b가 홀수인지 짝수인지에 따라 출력 순서만 바꿔줌
    if (sumAB % 2 == 0) {
        printf("%d/%d\n", a, b);
    } else {
        printf("%d/%d\n", b, a);
    }

    return 0;
}
