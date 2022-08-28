#include <iostream>
#include <cmath>

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int x1;
        int y1;
        int r1;
        int x2;
        int y2;
        int r2;
        
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        
        double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        
        // 작은 원의 중심이 큰 원 내부에 있을 때를 처리하기 위함
        int maxR = r1 > r2 ? r1 : r2;
        int minR = r1 > r2 ? r2 : r1;
        
        int intersectionCount;
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            intersectionCount = -1;
        } else if (distance == r1 + r2 || distance + minR == maxR) {
            intersectionCount = 1;
        } else if (distance > r1 + r2 || distance + minR < maxR) {
            intersectionCount = 0;
        } else {
            intersectionCount = 2;
        }
        
        printf("%d\n", intersectionCount);
    }

    return 0;
}
