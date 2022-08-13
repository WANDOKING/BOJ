#include <iostream>

int GetBunhaehap(int num)
{
    int result = num;
    
    while (num > 0) {
        result += num % 10;
        num /= 10;
    }
    
    return result;
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (GetBunhaehap(i) == N) {
            result = i;
            break;
        }
    }
    
    printf("%d", result);

    return 0;
}
