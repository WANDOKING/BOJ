#include <iostream>
#include <climits>

int main(void)
{
    int N;
    int M;
    int B;

    scanf("%d %d %d", &N, &M, &B);

    int board[N][M];
    int maxBlock = INT_MIN;
    int minBlock = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);

            if (board[i][j] > maxBlock)
            {
                maxBlock = board[i][j];
            }

            if (board[i][j] < minBlock)
            {
                minBlock = board[i][j];
            }
        }
    }

    int minTime = INT_MAX;
    int minHeight = INT_MAX;

    for (int i = minBlock; i <= maxBlock; i++)
    {
        int time = 0;
        int blockCount = B;

        // cut
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (board[j][k] > i)
                {
                    blockCount += board[j][k] - i;
                    time += 2 * (board[j][k] - i);
                }
            }
        }

        // fill
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (board[j][k] < i)
                {
                    blockCount -= i - board[j][k];

                    if (blockCount < 0)
                    {
                        goto NEXT_LEVEL;
                    }

                    time += i - board[j][k];
                }
            }
        }

        if (time <= minTime)
        {
            minTime = time;
            minHeight = i;
        }
    NEXT_LEVEL:;
    }

    printf("%d %d", minTime, minHeight);
}
