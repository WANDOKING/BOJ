#include <iostream>
#include <cstdlib>

typedef struct point {
    int x;
    int y;
} point_t;

int compare(const void* a, const void* b)
{
    const point_t point1 = *(point_t*)a;
    const point_t point2 = *(point_t*)b;
    
    if (point1.x == point2.x) {
        if (point1.y == point2.y) {
            return 0;
        } else if (point1.y > point2.y) {
            return 1;
        } else {
            return -1;
        }
    } else if (point1.x > point2.x) {
        return 1;
    } else {
        return -1;
    }
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    point_t points[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    
    qsort(points, N, sizeof(point_t), compare);
    
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    return 0;
}
