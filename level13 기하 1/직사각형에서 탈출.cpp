#include <iostream>

int main(void)
{
    int x;
    int y;
    int w;
    int h;
    
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    int minDistance = x;
    minDistance = (w - x < minDistance) ? w - x : minDistance;
    minDistance = (y < minDistance) ? y : minDistance;
    minDistance = (h - y < minDistance) ? h - y : minDistance;
    
    printf("%d", minDistance);
}
