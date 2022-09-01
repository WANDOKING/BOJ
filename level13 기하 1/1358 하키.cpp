#include <iostream>
#include <cmath>

int main()
{
    int W;
    int H;
    int X;
    int Y;
    int P;
    
    scanf("%d %d %d %d %d", &W, &H, &X, &Y, &P);
    
    int playersX[P];
    int playersY[P];
    for (int i = 0; i < P; i++)
    {
        scanf("%d %d", &playersX[i], &playersY[i]);
    }
    
    int count = 0;
    for (int i = 0; i < P; i++)
    {
        bool bWidthCheck = playersX[i] >= X && playersX[i] <= X + W;
        bool bHeightCheck = playersY[i] >= Y && playersY[i] <= Y + H;
        bool bIsInsideRectangle = bWidthCheck && bHeightCheck;
        
        if (bIsInsideRectangle == true)
        {
            count++;
            continue;
        }
        
        double distLeftCircle = sqrt((X - playersX[i]) * (X - playersX[i]) + (Y + H / 2 - playersY[i]) * (Y + H / 2 - playersY[i]));
        bool bInsideLeftCircle = distLeftCircle <= H / 2;
        if (bInsideLeftCircle == true)
        {
            count++;
            continue;
        }
        
        double distRightCircle = sqrt((X + W  - playersX[i]) * (X + W - playersX[i]) + (Y + H / 2 - playersY[i]) * (Y + H / 2 - playersY[i]));
        bool bInsideRightCircle = distRightCircle <= H / 2;
        if (bInsideRightCircle == true)
        {
            count++;
        }
    }
    
    printf("%d", count);
    

    return 0;
}
