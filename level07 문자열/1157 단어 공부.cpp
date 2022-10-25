#include <iostream>
#include <cstring>
#include <cctype>

int main()
{
    const int MAX_LENGTH = 1000000;
    
    char buffer[MAX_LENGTH + 1];
    int countAlphabet[26] = { 0, };
    
    scanf("%s", buffer);
    
    int modeAlphabetCount = 0;
    char modeAlphabet = 0;
    
    int length = strlen(buffer);
    for (int i = 0; i < length; i++) {
        char character = toupper(buffer[i]);
        
        countAlphabet[character - 'A']++;
        if (countAlphabet[character - 'A'] > modeAlphabetCount) {
            modeAlphabetCount = countAlphabet[character - 'A'];
            modeAlphabet = character;
        } else if (countAlphabet[character - 'A'] == modeAlphabetCount) {
            modeAlphabet = '?';
        }
    }
    
    printf("%c", modeAlphabet);

    return 0;
}
