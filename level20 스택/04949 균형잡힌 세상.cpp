#include <iostream>
#include <cstring>

enum { STACK_MAX_SIZE = 50 };

char stack[STACK_MAX_SIZE];
int stackNumCount = 0;

void push(char n) {
    stack[stackNumCount] = n;
    stackNumCount++;
}

char pop() {
    if (stackNumCount == 0) {
        return -1;
    }
    
    stackNumCount--;
    return stack[stackNumCount];
} 

int main(void)
{
    const int MAX_LENGTH = 100;
    
    char input[MAX_LENGTH + 2];
    
    bool bIsBalanced = true;
    while (fgets(input, sizeof(char) * (MAX_LENGTH + 2), stdin) != NULL) {
        int length = strlen(input);
        
        // 종료조건
        if (length == 2 && input[0] == '.') {
            break;
        }
        
        for (int i = 0; i < length; i++) {
            if (input[i] == '(' || input[i] == '[') {
                push(input[i]);
            } else if (input[i] == ')') {
                if (pop() != '(') {
                    bIsBalanced = false;
                }
            } else if (input[i] == ']') {
                if (pop() != '[') {
                    bIsBalanced = false;
                }
            } else if (input[i] == '.') {
                if (stackNumCount > 0) {
                    bIsBalanced = false;
                }
                break;
            }
        }
        
        if (bIsBalanced) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
        
        bIsBalanced = true;
        stackNumCount = 0;
    }
    
}
