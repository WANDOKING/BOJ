#include <iostream>
#include <climits>

#define MAX_N 2'000
#define MAX_M 2'000

char g_board[MAX_N][MAX_M];

int g_whiteStartSum[MAX_N][MAX_M]; // [0, 0]이 W로 시작하는 보드를 기준으로
int g_blackStartSum[MAX_N][MAX_M]; // [0, 0]이 B로 시작하는 보드를 기준으로
// [0, 0] ~ [i, j] 드래그 모양 판에 칠해야하는 정사각형의 누적 수를 계산해서 채워넣는다
// ex. g_whiteStartSum[3][3]은 [0, 0] ~ [3, 3]의 3X3 보드를 [0, 0]이 W로 시작하는 보드로 만들기 위해서 칠을 바꿔야하는 타일의 수

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;
    int K;

    std::cin >> N >> M >> K;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> g_board[i][j];
        }
    }

    bool bIsBlackTurn = true;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char thisBlock;

            if (bIsBlackTurn)
            {
                thisBlock = 'W';
            }
            else
            {
                thisBlock = 'B';
            }

            bIsBlackTurn = !bIsBlackTurn;

            if (g_board[i][j] == thisBlock)
            {
                g_blackStartSum[i][j] = 1;
                g_whiteStartSum[i][j] = 0;
            }
            else
            {
                g_blackStartSum[i][j] = 0;
                g_whiteStartSum[i][j] = 1;
            }

            if (i == 0 && j == 0)
            {
                continue;
            }
            else if (i == 0)
            {
                g_blackStartSum[i][j] += g_blackStartSum[i][j - 1];
                g_whiteStartSum[i][j] += g_whiteStartSum[i][j - 1];
            }
            else if (j == 0)
            {
                g_blackStartSum[i][j] += g_blackStartSum[i - 1][j];
                g_whiteStartSum[i][j] += g_whiteStartSum[i - 1][j];
            }
            else
            {
                g_blackStartSum[i][j] += g_blackStartSum[i - 1][j] + g_blackStartSum[i][j - 1] - g_blackStartSum[i - 1][j - 1];
                g_whiteStartSum[i][j] += g_whiteStartSum[i - 1][j] + g_whiteStartSum[i][j - 1] - g_whiteStartSum[i - 1][j - 1];
            }
        }

        if (M % 2 == 0)
        {
            bIsBlackTurn = !bIsBlackTurn;
        }
    }

    int result = INT_MAX;

    for (int i = K - 1; i < N; ++i)
    {
        for (int j = K - 1; j < M; ++j)
        {
            int tempValueBlack;
            int tempValueWhite;

            if (i <= K - 1 && j <= K - 1)
            {
                tempValueBlack = g_blackStartSum[i][j];
                tempValueWhite = g_whiteStartSum[i][j];
            }
            else if (i <= K - 1)
            {
                tempValueBlack = g_blackStartSum[i][j] - g_blackStartSum[i][j - K];
                tempValueWhite = g_whiteStartSum[i][j] - g_whiteStartSum[i][j - K];
            }
            else if (j <= K - 1)
            {
                tempValueBlack = g_blackStartSum[i][j] - g_blackStartSum[i - K][j];
                tempValueWhite = g_whiteStartSum[i][j] - g_whiteStartSum[i - K][j];
            }
            else
            {
                tempValueBlack = g_blackStartSum[i][j] - g_blackStartSum[i - K][j] - g_blackStartSum[i][j - K] + g_blackStartSum[i - K][j - K];
                tempValueWhite = g_whiteStartSum[i][j] - g_whiteStartSum[i - K][j] - g_whiteStartSum[i][j - K] + g_whiteStartSum[i - K][j - K];
            }

            int needPaintCount = tempValueBlack < tempValueWhite ? tempValueBlack : tempValueWhite;

            if (needPaintCount < result)
            {
                result = needPaintCount;
            }
        }
    }

    std::cout << result;
}
