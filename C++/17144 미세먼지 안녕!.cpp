#include <iostream>
#include <cstring>

#define MAX_R 50
#define MAX_C 50

#define AIR_CLEANER -1

int g_map[MAX_R][MAX_C];

int g_airCleanerY;

int R;
int C;
int T;

// 미세먼지 확산
void SpreadDust()
{
    int mapTemp[MAX_R][MAX_C] = { 0, };

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (g_map[i][j] == 0)
            {
                continue;
            }

            if (g_map[i][j] == AIR_CLEANER)
            {
                mapTemp[i][j] = AIR_CLEANER;
                continue;
            }

            int spreadSize = g_map[i][j] / 5;
            int spreadCount = 0;

            if (i > 0 && g_map[i - 1][j] != AIR_CLEANER)
            {
                mapTemp[i - 1][j] += spreadSize;
                spreadCount++;
            }

            if (i < R - 1 && g_map[i + 1][j] != AIR_CLEANER)
            {
                mapTemp[i + 1][j] += spreadSize;
                spreadCount++;
            }

            if (j > 0 && g_map[i][j - 1] != AIR_CLEANER)
            {
                mapTemp[i][j - 1] += spreadSize;
                spreadCount++;
            }

            if (j < C - 1 && g_map[i][j + 1] != AIR_CLEANER)
            {
                mapTemp[i][j + 1] += spreadSize;
                spreadCount++;
            }

            mapTemp[i][j] += g_map[i][j] - spreadSize * spreadCount;
        }
    }

    memcpy(g_map, mapTemp, sizeof(int) * MAX_R * MAX_C);
}

// 공기청정기 작동
void RunAirCleaner()
{

    int airCleanerUpY = g_airCleanerY - 1;
    int airCleanerDownY = g_airCleanerY;

    int x;
    int y;

    // 위쪽 순환
    {
        x = 0;
        y = airCleanerUpY - 1;
        while (y >= 0)
        {
            g_map[y + 1][x] = g_map[y][x];
            y--;
        }

        x = 1;
        y = 0;
        while (x < C)
        {
            g_map[y][x - 1] = g_map[y][x];
            x++;
        }

        x = C - 1;
        y = 1;
        while (y <= airCleanerUpY)
        {
            g_map[y - 1][x] = g_map[y][x];
            y++;
        }

        x = C - 2;
        y = airCleanerUpY;
        while (x > 0)
        {
            g_map[y][x + 1] = g_map[y][x];
            x--;
        }
        
        g_map[airCleanerUpY][0] = AIR_CLEANER;
        g_map[airCleanerUpY][1] = 0;
    }
    
    // 아래쪽 순환
    {
        x = 0;
        y = airCleanerDownY + 1;
        while (y < R)
        {
            g_map[y - 1][x] = g_map[y][x];
            y++;
        }

        x = 1;
        y = R - 1;
        while (x < C)
        {
            g_map[y][x - 1] = g_map[y][x];
            x++;
        }

        x = C - 1;
        y = R - 2;
        while (y >= airCleanerUpY)
        {
            g_map[y + 1][x] = g_map[y][x];
            y--;
        }

        x = C - 2;
        y = airCleanerDownY;
        while (x > 0)
        {
            g_map[y][x + 1] = g_map[y][x];
            x--;
        }

        g_map[airCleanerDownY][0] = AIR_CLEANER;
        g_map[airCleanerDownY][1] = 0;
    }
}

int GetTotalDustCount()
{
    int ret = 0;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            ret += g_map[i][j];
        }
    }

    return ret - AIR_CLEANER * 2;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> R >> C >> T;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            std::cin >> g_map[i][j];

            if (g_map[i][j] == AIR_CLEANER)
            {
                g_airCleanerY = i;
            }
        }
    }

    for (int i = 0; i < T; ++i)
    {
        SpreadDust();
        RunAirCleaner();
    }
    
    std::cout << GetTotalDustCount();
}
