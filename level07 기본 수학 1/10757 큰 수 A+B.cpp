#include <iostream>
#include <cstring>

int main()
{
    char A[10001];
    char B[10001];
    char result[10002];
    
    scanf("%s", A);
    scanf("%s", B);
    
    int AIndex = strlen(A) - 1;
    int BIndex = strlen(B) - 1;
    int resultIndex = 0;
    
    int prevCarry = 0;
    
    // A와 B를 다 더하고, 남은 carry도 없으면 종료
    while (AIndex >= 0 || BIndex >= 0 || prevCarry != 0) {
        int numAIndex;
        if (AIndex >= 0) {
            numAIndex = A[AIndex] - '0';
        } else {
            numAIndex = 0;
        }
        
        int numBIndex;
        if (BIndex >= 0) {
            numBIndex = B[BIndex] - '0';
        } else {
            numBIndex = 0;
        }
        
        int sum = (numAIndex + numBIndex + prevCarry) % 10;
        int currentCarry = (numAIndex + numBIndex + prevCarry) / 10;
        result[resultIndex] = sum + '0';
        
        prevCarry = currentCarry;
        
        resultIndex++;
        AIndex--;
        BIndex--;
    }
    
    result[resultIndex] = '\0';
    
    // 역순으로 출력
    for (int i = strlen(result) - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    return 0;
}
