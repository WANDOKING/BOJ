#include <iostream>

using namespace std;

int main()
{
    int A;
    int B;
    int C;
    
    scanf("%d %d %d", &A, &B, &C);
    
    // C - B > 0 이라면,
    // A + BN < CN -> A/(C-B) < N
    if (C - B <= 0) {
        printf("%d", -1);
    } else {
        printf("%d", A / (C - B) + 1);
    }
    
    return 0;
}
