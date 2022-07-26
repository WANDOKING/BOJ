#include <iostream>

bool isHansu(int num)
{
    if (num < 100) {
        return true;
    }
    
    int digit1 = num % 10;
    num /= 10;
    int digit10 = num % 10;
    num /= 10;
    int digit100 =  num;
    
    if (digit1 - digit10 == digit10 - digit100) {
        return true;
    } else {
        return false;
    }
}

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (isHansu(i)) {
            count++;
        }
    }
    
    printf("%d", count);
}
