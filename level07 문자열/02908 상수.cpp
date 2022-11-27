#include <iostream>
#include <cmath>

int main()
{
    char A[4];
    char B[4];
    
    scanf("%s %s", A, B);
    
    int sangsuNum1 = 0;
    for (int i = 0; i < 3; i++) {
        sangsuNum1 += (A[i] - '0') * pow(10, i);
    }
    
    int sangsuNum2 = 0;
    for (int i = 0; i < 3; i++) {
        sangsuNum2 += (B[i] - '0') * pow(10, i);
    }
    
    if (sangsuNum1 > sangsuNum2) {
        printf("%d", sangsuNum1);
    } else {
        printf("%d", sangsuNum2);
    }

    return 0;
}
