#include <iostream>
#include <cstring>

int main()
{
    int alphabetIndex[26];
    for (int i = 0; i < 26; i++) {
        alphabetIndex[i] = -1;
    }
    char input[101];
    
    scanf("%s", input);
    
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        if (alphabetIndex[input[i] - 'a'] == -1) {
            alphabetIndex[input[i] - 'a'] = i;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        printf("%d ", alphabetIndex[i]);
    }

    return 0;
}
