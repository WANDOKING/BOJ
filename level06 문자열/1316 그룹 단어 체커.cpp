#include <iostream>
#include <cstring>

int main()
{
    int N;
    
    int groupWordCount = 0;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char input[101];
        bool bAlphabetUsed[26];
        bool bIsGroupWord = true;
        char prevCharacter = 0;
        
        memset(bAlphabetUsed, 0, sizeof(bool) * 26);
        
        scanf("%s", input);
        
        int j = 0;
        while (input[j] != '\0') {
            if (bAlphabetUsed[input[j] - 'a'] == true && prevCharacter != input[j]) {
                bIsGroupWord = false;
                break;
            }
            
            bAlphabetUsed[input[j] - 'a'] = true;
            prevCharacter = input[j];
            j++;
        }
        
        if (bIsGroupWord == true) {
            groupWordCount++;
        }
    }
    
    printf("%d", groupWordCount);

    return 0;
}
