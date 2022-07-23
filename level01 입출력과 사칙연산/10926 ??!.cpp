#include <iostream>

#include <cstring>

int main()
{
    char id[54];
    
    scanf("%s", id);
    
    int idLength = strlen(id);
    
    id[idLength] = '?';
    id[idLength + 1] = '?';
    id[idLength + 2] = '!';
    id[idLength + 3] = '\0';
    
    printf("%s", id);

    return 0;
}
