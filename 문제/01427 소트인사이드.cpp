#include <iostream>

int main()
{
    int counts[10] = { 0, }; // counting sort
    
    while (true) {
        char c = getchar();
        
        if (c == EOF) {
            break;
        }
        
        counts[c - '0']++;
    }
    
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < counts[i]; j++) {
            printf("%d", i);
        }
    }

    return 0;
}
