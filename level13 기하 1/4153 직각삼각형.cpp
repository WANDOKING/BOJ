#include <iostream>

int main()
{
    int a;
    int b;
    int c;
    
    while (true) {
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        
        int max;
        if (a >= b && a >= c) {
            max = a;
            a = c;
            c = max;
        } else if (b >= a && b >= c) {
            max = b;
            b = c;
            c = max;
        }
        
        if (a * a + b * b == c * c) {
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }

    return 0;
}
