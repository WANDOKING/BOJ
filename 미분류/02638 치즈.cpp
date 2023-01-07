#include <iostream>
#include <queue>
#include <vector>
#include <list>

#define MAX 100

#define EMPTY '0'
#define CHEESE '1'
#define AIR '2'

char g_board[MAX][MAX];
int N;
int M;

void FillAir(const int startX, const int startY)
{
    std::queue<short> q; // y * 100 + x
    q.push(startY * 100 + startX);
    g_board[startY][startX] = AIR;

    while (q.empty() == false)
    {
        int x = q.front() % 100;
        int y = q.front() / 100;
        q.pop();

        if (x > 0 && g_board[y][x - 1] == EMPTY)
        {
            q.push(y * 100 + (x - 1));
            g_board[y][x - 1] = AIR;
        }

        if (x < M - 1 && g_board[y][x + 1] == EMPTY)
        {
            q.push(y * 100 + (x + 1));
            g_board[y][x + 1] = AIR;
        }

        if (y > 0 && g_board[y - 1][x] == EMPTY)
        {
            q.push((y - 1) * 100 + x);
            g_board[y - 1][x] = AIR;
        }

        if (y < N - 1 && g_board[y + 1][x] == EMPTY)
        {
            q.push((y + 1) * 100 + x);
            g_board[y + 1][x] = AIR;
        }
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;

    std::list<short> cheeses;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> g_board[i][j];

            if (g_board[i][j] == CHEESE)
            {
                cheeses.push_back(i * 100 + j);
            }
        }
    }

    FillAir(0, 0);

    int result = 0;
    while (cheeses.size() > 0)
    {
        ++result;

        std::vector<short> toDeleteCoordinate; // y * 100 + x
        toDeleteCoordinate.reserve(cheeses.size());

        for (std::list<short>::iterator it = cheeses.begin(); it != cheeses.end();)
        {
            int x = (*it) % 100;
            int y = (*it) / 100;

            int airCount = 0;
            if (g_board[y - 1][x] == AIR)
            {
                airCount++;
            }

            if (g_board[y + 1][x] == AIR)
            {
                airCount++;
            }

            if (g_board[y][x - 1] == AIR)
            {
                airCount++;
            }

            if (g_board[y][x + 1] == AIR)
            {
                airCount++;
            }

            if (airCount >= 2)
            {
                it = cheeses.erase(it);
                toDeleteCoordinate.push_back(y * 100 + x);
            }
            else
            {
                ++it;
            }
        }

        for (int coordinate : toDeleteCoordinate)
        {
            int x = coordinate % 100;
            int y = coordinate / 100;

            FillAir(x, y);
        }
    }

    std::cout << result;
}
