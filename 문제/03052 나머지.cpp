#include <iostream>

using namespace std;

int main()
{
    const int NUM_DIVIDE = 42;
    bool bIsRest[NUM_DIVIDE] = { false, };
    
    for (int i = 0; i < 10; i++) {
        int input;
        
        scanf("%d", &input);
        
        bIsRest[input % NUM_DIVIDE] = true;
    }
    
    int numCount = 0;
    for (int i = 0; i < NUM_DIVIDE; i++) {
        if (bIsRest[i] == true) {
            numCount++;
        }
    }
    
    printf("%d", numCount);

    return 0;
}
