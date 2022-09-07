#include <iostream>
#include <cstring>

int count = 0;

void QueenRecursive(bool *board, int N, int depth = 1)
{
    int i = depth - 1;

    for (int j = 0; j < N; j++)
    {
        if (*(board + i * N + j) == true)
        {
            continue;
        }

        if (depth == N)
        {
            count++;
            return;
        }

        // 이전 보드 상태 저장
        bool *revisionBoard = (bool *)malloc(sizeof(bool) * N * N);
        memcpy(revisionBoard, board, sizeof(bool) * N * N);

        // 그 위치에서 퀸의 공격 가능 범위를 true로 셋
        // 가로
        for (int k = 0; k < N; k++)
        {
            *(board + i * N + k) = true;
        }

        // 세로
        for (int k = 0; k < N; k++)
        {
            *(board + k * N + j) = true;
        }

        // 오른아래 대각
        for (int k = 1; i + k < N && j + k < N; k++)
        {
            *(board + (i + k) * N + j + k) = true;
        }

        // 왼위 대각
        for (int k = 1; i - k >= 0 && j - k >= 0; k++)
        {
            *(board + (i - k) * N + j - k) = true;
        }

        // 오른위 대각
        for (int k = 1; i - k >= 0 && j + k < N; k++)
        {
            *(board + (i - k) * N + j + k) = true;
        }

        // 왼아래 대각
        for (int k = 1; i + k < N && j - k >= 0; k++)
        {
            *(board + (i + k) * N + j - k) = true;
        }

        QueenRecursive(board, N, depth + 1);

        memcpy(board, revisionBoard, sizeof(bool) * N * N);
        free(revisionBoard);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    bool board[N][N];
    memset(board, 0, sizeof(bool) * N * N);

    QueenRecursive((bool *)board, N);

    printf("%d", count);

    return 0;
}
