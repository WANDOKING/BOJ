#include <iostream>
#include <cstring>

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int R;
        char S[21];
        scanf("%d %s", &R, S);
        
        int length = strlen(S);
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < R; k++) {
                putchar(S[j]);
            }
        }
        
        printf("\n");
    }

    return 0;
}
