#include <iostream>

int main()
{
    const int MAX_LENGTH = 100;
    
    char input[MAX_LENGTH + 1];
    
    scanf("%s", input);
    
    int i = 0;
    int alphabetCount = 0;
    while (input[i] != '\0') {
        
        if (input[i] == 'c') {
            if (input[i + 1] == '=') {
                i++;
            }
            if (input[i + 1] == '-') {
                i++;
            }
        }
        
        if (input[i] == 'd') {
            if (input[i + 1] == 'z' && input[i + 2] == '=') {
                i += 2;
            }
            if (input[i + 1] == '-') {
                i++;
            }
        }
        
        if (input[i] == 'l' && input[i + 1] == 'j') {
            i++;
        }
        
        if (input[i] == 'n' && input[i + 1] == 'j') {
            i++;
        }
        
        if (input[i] == 's' && input[i + 1] == '=') {
            i++;
        }
        
        if (input[i] == 'z' && input[i + 1] == '=') {
            i++;
        }
        
        alphabetCount++;
        i++;
    }
    
    printf("%d", alphabetCount);

    return 0;
}
