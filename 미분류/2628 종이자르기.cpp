#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width;
    int height;
    scanf("%d %d", &width, &height);
    
    int cutCount;
    scanf("%d", &cutCount);
    
    if (cutCount == 0)
    {
        printf("%d", width * height);
        return 0;
    }
    
    vector<int> verticalCuts;
    vector<int> horizontalCuts;
    for (int i = 0; i < cutCount; i++)
    {
        int bIsVertical;
        int cutPos;
        scanf("%d %d", &bIsVertical, &cutPos);
        
        if (bIsVertical == 1)
        {
            verticalCuts.push_back(cutPos);
        }
        else
        {
            horizontalCuts.push_back(cutPos);
        }
    }
    
    sort(verticalCuts.rbegin(), verticalCuts.rend());
    sort(horizontalCuts.rbegin(), horizontalCuts.rend());
    
    int prev = width;
    int maxWidth = -1;
    for (int verticalCut : verticalCuts)
    {
        if (prev - verticalCut > maxWidth)
        {
            maxWidth = prev - verticalCut;
        }
        
        prev = verticalCut;
    }
    
    if (prev > maxWidth)
    {
        maxWidth = prev;
    }
    
    prev = height;
    int maxHeight = -1;
    for (int horizontalCut : horizontalCuts)
    {
        if (prev - horizontalCut > maxHeight)
        {
            maxHeight = prev - horizontalCut;
        }
        
        prev = horizontalCut;
    }
    
    if (prev > maxHeight)
    {
        maxHeight = prev;
    }
    
    printf("%d", maxWidth * maxHeight);

    return 0;
}
