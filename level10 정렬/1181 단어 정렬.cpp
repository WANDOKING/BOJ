#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX_LENGTH 50

int compare(const void* a, const void* b)
{
    const char* str1 = (const char*)a;
    const char* str2 = (const char*)b;
    
    if (strlen(str1) > strlen(str2)) {
        return 1;
    } else if (strlen(str1) < strlen(str2)) {
        return -1;
    }
    
    if (strcmp(str1, str2) == 0) {
        return 0;
    } else if (strcmp(str1, str2) > 0) {
        return 1;
    } else {
        return -1;
    }
}

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    char (*words)[MAX_LENGTH + 1] = (char(*)[MAX_LENGTH + 1])malloc(sizeof(char) * N * (MAX_LENGTH + 1));
    
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }
    
    qsort(words, N, sizeof(char) * (MAX_LENGTH + 1), compare);
    
    
    printf("%s\n", words[0]);
    for (int i = 1; i < N; i++) {
        if (strcmp(words[i - 1], words[i]) == 0) {
            continue;
        }
        
        printf("%s\n", words[i]);
    }
    
    free(words);
}
