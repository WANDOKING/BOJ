#include <iostream>
#include <cstring>

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    char buffer[100];
    int num = 666;
    int count = 0;
    while (true) {
        
        sprintf(buffer, "%d", num);
        
        if (strstr(buffer, "666") != NULL) {
            count++;
        }
        
        if (count == N) {
            break;
        }
        num++;
    }
    
    printf("%d", num);
}
