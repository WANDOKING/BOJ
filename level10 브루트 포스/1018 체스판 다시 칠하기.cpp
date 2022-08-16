#include <iostream>
#include <climits>

const char BOARD_BLACK_START[8][8] = {
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
};

const char BOARD_WHITE_START[8][8] = {
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
};

int main(void)
{
    int N;
    int M;
    
    scanf("%d %d", &N, &M);
    
    // input
    char board[N][M];
    getchar();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = getchar();
        }
        
        getchar();
    }
    
    int minCount = INT_MAX;
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            
            int countPaintBlack = 0;
            int countPaintWhite = 0;
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    if (board[k][l] != BOARD_WHITE_START[k - i][l - j]) {
                        countPaintWhite++;
                    }
            
                    if (board[k][l] != BOARD_BLACK_START[k - i][l - j]) {
                        countPaintBlack++;
                    }
                }
            }
            
            int count;
            if (countPaintBlack > countPaintWhite) {
               count = countPaintWhite;
            } else {
                count = countPaintBlack;
            }
            
            if (count < minCount) {
                minCount = count;
            }
        }
    }
    
    
    printf("%d", minCount);
}
