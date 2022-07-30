#include <iostream>
#include <cstring>

int main()
{
    char buffer[1000002];
    
    fgets(buffer, sizeof(buffer), stdin);
    
    int length = strlen(buffer);
    
    int startIndex;
    if (buffer[0] == ' ') {
        startIndex = 1;
    } else {
        startIndex = 0;
    }
    
    int countBlank = 1;
    for (int i = startIndex; i < length - 1; i++) {
        if (buffer[i] == ' ') {
            countBlank++;
        } 
    }
    
    if (buffer[length - 2] == ' ') {
        countBlank--;
    }
    
    printf("%d", countBlank);

    return 0;
}
