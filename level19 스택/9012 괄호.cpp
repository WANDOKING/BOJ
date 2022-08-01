#include <iostream>
#include <cstring>

enum { STACK_MAX_SIZE = 50 };

char stack[STACK_MAX_SIZE];
int stackNumCount = 0;

void push(int n) {
    stack[stackNumCount] = n;
    stackNumCount++;
}

char pop(int n) {
    if (stackNumCount == 0) {
        return -1;
    }
    
    stackNumCount--;
    return stack[stackNumCount];
} 

int main(void)
{
    const int MAX_LENGTH = 50;
    
    int T;
    char input[MAX_LENGTH + 1];
    
    scanf("%d", &T);
    
    bool bIsValid = true;
    for (int i = 0; i < T; i++)
    {
        scanf("%s", input);
        
        int length = strlen(input);
        for (int j = 0; j < length; j++) {
            if (input[j] == '(') {
                push(input[j]);
            } else if (input[j] == ')') {
                if (pop(input[j]) == -1) {
                    bIsValid = false;
                    break;
                }
            }
        }
        
        if (stackNumCount > 0) {
            bIsValid = false;
        }
        
        if (bIsValid) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        bIsValid = true;
        stackNumCount = 0;
    }
}
