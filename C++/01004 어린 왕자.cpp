#include <iostream>
#include <cmath>

struct Planet
{
    int x;
    int y;
    int r;
};

bool IsInside(const Planet& planet, int x, int y)
{
    double distance = sqrt((planet.x - x) * (planet.x - x) + (planet.y - y) * (planet.y - y));

    if (distance < planet.r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    int results[T];
    for (int i = 0; i < T; i++)
    {
        int x1;
        int y1;
        int x2;
        int y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        int n;
        scanf("%d", &n);
        
        Planet planets[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d %d", &planets[j].x, &planets[j].y, &planets[j].r);
        }
        
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            bool bIsPoint1Inside = IsInside(planets[j], x1, y1);
            bool bIsPoint2Inside = IsInside(planets[j], x2, y2);
            
            if (!bIsPoint1Inside && bIsPoint2Inside || bIsPoint1Inside && !bIsPoint2Inside)
            {
                count++;
            }
        }
        
        results[i] = count;
    }
    
    for (int i = 0; i < T; i++)
    {
        printf("%d\n", results[i]);
    }

    return 0;
}
