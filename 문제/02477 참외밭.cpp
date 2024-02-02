#include <iostream>

typedef enum direction {
    EAST = 1,
    WEST = 2,
    SOUTH = 3,
    NORTH = 4
} direction_t;

int main()
{
    int K;
    
    scanf("%d", &K);
    
    direction_t directions[6];
    int lengths[6];
    int maxXLengthIndex = -1;
    int maxYLengthIndex = -1;
    
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", (int*)&directions[i], &lengths[i]);
        
        if (directions[i] <= WEST && (maxXLengthIndex == -1 || lengths[i] > lengths[maxXLengthIndex])) {
            maxXLengthIndex = i;
        }
        
        if (directions[i] >= SOUTH && (maxYLengthIndex == -1 || lengths[i] > lengths[maxYLengthIndex])) {
            maxYLengthIndex = i;
        }
    }
    
    int largeRectangleArea = lengths[maxXLengthIndex] * lengths[maxYLengthIndex];
    int smallRectangleArea = lengths[(maxXLengthIndex + 3) % 6] * lengths[(maxYLengthIndex + 3) % 6];
    
    printf("%d", K * (largeRectangleArea - smallRectangleArea));

    return 0;
}
