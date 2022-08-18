#include <iostream>
#include <cstdlib>

typedef struct point {
    int x;
    int y;
} Point;

int compare(const void* a, const void* b)
{
    Point* point1 = (Point*)a;
    Point* point2 = (Point*)b;
    
    if (point1->y == point2->y) {
        if (point1->x == point2->x) {
            return 0;
        } else if (point1->x > point2->x) {
            return 1;
        } else {
            return -1;
        }
    } else if (point1->y > point2->y) {
        return 1;
    } else {
        return -1;
    }
}

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    Point points[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    
    qsort(points, N, sizeof(Point), compare);
    
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }
    
    return 0;
}
