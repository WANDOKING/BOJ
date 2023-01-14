#include <iostream>
#include <queue>

#define MAX_N 50
#define MAX_M 50

#define WEST_IS_WALL(X) (((X) & 1) == 1)
#define NORTH_IS_WALL(X) (((X) & 2) == 2)
#define EAST_IS_WALL(X) (((X) & 4) == 4)
#define SOUTH_IS_WALL(X) (((X) & 8) == 8)

short g_map[MAX_N][MAX_M];
int* g_roomInfo[MAX_N][MAX_M];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> M >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> g_map[i][j];
        }
    }

    int totalRoomCount = 0;
    int maxRoomSize = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (g_roomInfo[i][j] != nullptr)
            {
                continue;
            }

            totalRoomCount++;
            int* const newRoomSize = new int;
            *newRoomSize = 1;
            g_roomInfo[i][j] = newRoomSize;

            std::queue<int> q;
            q.push(100 * i + j);

            while (q.empty() == false)
            {
                int y = q.front() / 100;
                int x = q.front() % 100;
                q.pop();

                if (!WEST_IS_WALL(g_map[y][x]) && g_roomInfo[y][x - 1] == nullptr)
                {
                    *newRoomSize += 1;
                    g_roomInfo[y][x - 1] = newRoomSize;
                    q.push(y * 100 + x - 1);
                }

                if (!EAST_IS_WALL(g_map[y][x]) && g_roomInfo[y][x + 1] == nullptr)
                {
                    *newRoomSize += 1;
                    g_roomInfo[y][x + 1] = newRoomSize;
                    q.push(y * 100 + x + 1);
                }

                if (!NORTH_IS_WALL(g_map[y][x]) && g_roomInfo[y - 1][x] == nullptr)
                {
                    *newRoomSize += 1;
                    g_roomInfo[y - 1][x] = newRoomSize;
                    q.push((y - 1) * 100 + x);
                }

                if (!SOUTH_IS_WALL(g_map[y][x]) && g_roomInfo[y + 1][x] == nullptr)
                {
                    *newRoomSize += 1;
                    g_roomInfo[y + 1][x] = newRoomSize;
                    q.push((y + 1) * 100 + x);
                }
            }

            if (*newRoomSize > maxRoomSize)
            {
                maxRoomSize = *newRoomSize;
            }
        }
    }

    int maxRoomSizeWhenBreakWall = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (i > 0 && g_roomInfo[i][j] != g_roomInfo[i - 1][j])
            {
                int newRoomSize = *g_roomInfo[i][j] + *g_roomInfo[i - 1][j];
                if (newRoomSize > maxRoomSizeWhenBreakWall)
                {
                    maxRoomSizeWhenBreakWall = newRoomSize;
                }
            }

            if (i < N - 1 && g_roomInfo[i][j] != g_roomInfo[i + 1][j])
            {
                int newRoomSize = *g_roomInfo[i][j] + *g_roomInfo[i + 1][j];
                if (newRoomSize > maxRoomSizeWhenBreakWall)
                {
                    maxRoomSizeWhenBreakWall = newRoomSize;
                }
            }

            if (j > 0 && g_roomInfo[i][j] != g_roomInfo[i][j - 1])
            {
                int newRoomSize = *g_roomInfo[i][j] + *g_roomInfo[i][j - 1];
                if (newRoomSize > maxRoomSizeWhenBreakWall)
                {
                    maxRoomSizeWhenBreakWall = newRoomSize;
                }
            }

            if (j < M - 1 && g_roomInfo[i][j] != g_roomInfo[i][j + 1])
            {
                int newRoomSize = *g_roomInfo[i][j] + *g_roomInfo[i][j + 1];
                if (newRoomSize > maxRoomSizeWhenBreakWall)
                {
                    maxRoomSizeWhenBreakWall = newRoomSize;
                }
            }
        }
    }

    std::cout << totalRoomCount << '\n';
    std::cout << maxRoomSize << '\n';
    std::cout << maxRoomSizeWhenBreakWall << '\n';

}
