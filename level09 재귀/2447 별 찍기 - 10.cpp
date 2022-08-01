#include <iostream>
#include <cstring>

// canvas의 (x, y)에서 n크기의 패턴 그리기
void DrawStarRecursive(char** canvas, int x, int y, int n)
{
    // 종료 조건 : n = 3의 패턴 그리기
    if (n == 3) {
        *(*(canvas + y) + x) = '*';
        *(*(canvas + y) + x + 1) = '*';
        *(*(canvas + y) + x + 2) = '*';
        
        *(*(canvas + y + 1) + x) = '*';
        *(*(canvas + y + 1) + x + 1) = ' ';
        *(*(canvas + y + 1) + x + 2) = '*';
        
        *(*(canvas + y + 2) + x) = '*';
        *(*(canvas + y + 2) + x + 1) = '*';
        *(*(canvas + y + 2) + x + 2) = '*';
        return;
    }
    
    // 재귀 로직 : 각 위치에서 1/3사이즈의 패턴을 그려라
    n /= 3;
    
    DrawStarRecursive(canvas, x, y, n);
    DrawStarRecursive(canvas, x + n, y, n);
    DrawStarRecursive(canvas, x + n * 2, y, n);
    DrawStarRecursive(canvas, x, y + n, n);
    /********** 가운데는 그리지 않음 **********/
    DrawStarRecursive(canvas, x + n * 2, y + n, n);
    DrawStarRecursive(canvas, x, y + n * 2, n);
    DrawStarRecursive(canvas, x + n, y + n * 2, n);
    DrawStarRecursive(canvas, x + n * 2, y + n * 2, n);
    
    return;
}

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    // 내부 배열 형태의 2차원배열
    char* canvas[N];
    for (int i = 0; i < N; i++) {
        canvas[i] = new char[N];
        memset(canvas[i], ' ', sizeof(char) * N);
    }
    
    DrawStarRecursive(canvas, 0, 0, N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", canvas[i][j]);
        }
        
        printf("\n");
    }
}
