#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int A;
    int B;
    int C;
    
    char numStr[50];
    int numCount[10] = { 0, };
    
    cin >> A >> B >> C;
    
    sprintf(numStr ,"%d", A * B * C);
    
    int numLength = strlen(numStr);
    for (int i = 0; i < numLength; i++) {
        numCount[numStr[i] - '0']++;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", numCount[i]);
    }
    
    return 0;
}
