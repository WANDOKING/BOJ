#include <iostream>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    // N = 3a + 5b -> b = (N - 3a) / 5
    // 5를 쓸 수 있다면 많이 쓸 수록 좋음
    // 단, N - 3a가 5의 배수가 되어야 하므로 3을 최소한으로 뺀다
    int temp = N;
    while (true) {
        if (temp < 0) {
            printf("%d", -1);
            break;
        }
        
        if (temp == 0) {
            printf("%d", N / 3);
            break;
        }
        
        if (temp % 5 == 0) {
            printf("%d", temp / 5 + (N - temp) / 3);
            break;
        }
        
        temp -= 3;
    }

    return 0;
}
