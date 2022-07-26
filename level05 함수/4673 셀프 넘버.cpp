#include <iostream>

int d(int num)
{
    int result = num;
    
    while (num != 0) {
        result += num % 10;
        num /= 10;
    }
    
    return result;
}

int main(void)
{
    for (int i = 1; i <= 10000; i++) {
        for (int j = 1; j < i; j++) {
            if (d(j) == i) {
                goto next;
            }
        }
        
        printf("%d\n", i);

    next:;
    }
}
