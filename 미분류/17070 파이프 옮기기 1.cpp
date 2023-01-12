#include <iostream>
#include <queue>

#define MAX_N 16
#define WALL '1'
#define BLANK '0'

char g_map[MAX_N][MAX_N];

struct Position
{
    unsigned char FrontX;
    unsigned char FrontY;
    unsigned char BackX;
    unsigned char BackY;
};

union Pipe
{
    unsigned int Value;
    Position pos;
};

int main(void)
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> g_map[i][j];
        }
    }

    std::queue<unsigned int> q;
    Pipe start;
    start.pos.FrontX = 0;
    start.pos.FrontY = 0;
    start.pos.BackX = 1;
    start.pos.BackY = 0;

    q.push(start.Value);

    int result = 0;
    while (q.empty() == false)
    {
        Pipe currentPipe;
        currentPipe.Value = q.front();
        q.pop();

        if (currentPipe.pos.BackX == N - 1 && currentPipe.pos.BackY == N - 1)
        {
            ++result;
            continue;
        }

        bool IsHorizontal = currentPipe.pos.BackY == currentPipe.pos.FrontY;
        bool IsVertical = currentPipe.pos.BackX == currentPipe.pos.FrontX;
        bool IsDiagonal = !IsHorizontal && !IsVertical;

        bool canGoRight = currentPipe.pos.BackX < N - 1 && g_map[currentPipe.pos.BackY][currentPipe.pos.BackX + 1] == BLANK;
        bool canGoDown = currentPipe.pos.BackY < N - 1 && g_map[currentPipe.pos.BackY + 1][currentPipe.pos.BackX] == BLANK;
        bool canGoRightDown = canGoRight && canGoDown && g_map[currentPipe.pos.BackY + 1][currentPipe.pos.BackX + 1] == BLANK;

        if (canGoRightDown)
        {
            Pipe nextPipe;
            nextPipe.pos.FrontX = currentPipe.pos.BackX;
            nextPipe.pos.FrontY = currentPipe.pos.BackY;
            nextPipe.pos.BackX = currentPipe.pos.BackX + 1;
            nextPipe.pos.BackY = currentPipe.pos.BackY + 1;

            q.push(nextPipe.Value);
        }

        if ((IsHorizontal || IsDiagonal) && canGoRight)
        {
            Pipe nextPipe;
            nextPipe.pos.FrontX = currentPipe.pos.BackX;
            nextPipe.pos.FrontY = currentPipe.pos.BackY;
            nextPipe.pos.BackX = currentPipe.pos.BackX + 1;
            nextPipe.pos.BackY = currentPipe.pos.BackY;

            q.push(nextPipe.Value);
        }

        if ((IsVertical || IsDiagonal) && canGoDown)
        {
            Pipe nextPipe;
            nextPipe.pos.FrontX = currentPipe.pos.BackX;
            nextPipe.pos.FrontY = currentPipe.pos.BackY;
            nextPipe.pos.BackX = currentPipe.pos.BackX;
            nextPipe.pos.BackY = currentPipe.pos.BackY + 1;

            q.push(nextPipe.Value);
        }
    }

    std::cout << result;
}
