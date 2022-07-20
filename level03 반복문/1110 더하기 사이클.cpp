#include <iostream>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    
    if (N < 10) {
        N *= 10;
    }
    
    int newNum = N;
    int cycleCount = 0;
    
    do {
        cycleCount++;
        
        int newNumDigits10 = newNum % 10;
        int newNumDigits1 = (newNum / 10 + newNum % 10) % 10;
        newNum = newNumDigits10 * 10 + newNumDigits1;
    } while (N != newNum);

    printf("%d", cycleCount);
    return 0;
}
