#include <iostream>

int main()
{
    int x1 = -1;
    int x2 = -1;
    int y1 = -1;
    int y2 = -1;
     
    int x1Count = 0;
    int x2Count = 0;
    int y1Count = 0;
    int y2Count = 0;
    
    for (int i = 0; i < 3; i++) {
        int inputX;
        int inputY;
        
        scanf("%d %d", &inputX, &inputY);
        
        if (x1 == -1 || x1 == inputX) {
            x1 = inputX;
            x1Count++;
        } else {
            x2 = inputX;
            x2Count++;
        }
        
        if (y1 == -1 || y1 == inputY) {
            y1 = inputY;
            y1Count++;
        } else {
            y2 = inputY;
            y2Count++;
        }
    }
    
    int lastPointX = x1Count == 1 ? x1 : x2;
    int lastPointY = y1Count == 1 ? y1 : y2;
    
    printf("%d %d", lastPointX, lastPointY);

    return 0;
}
