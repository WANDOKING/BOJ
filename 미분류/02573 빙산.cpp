#include <iostream>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <cmath>

#define MAX_N 300
#define MAX_M 300

int g_map[MAX_N][MAX_M];
int g_mapTemp[MAX_N][MAX_M];

int main(void)
{
    int N;
    int M;

    std::cin >> N >> M;

    int iceCount = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> g_map[i][j];

            if (g_map[i][j] != 0)
            {
                iceCount++;
            }
        }
    }

    int time = 0;
    while (iceCount > 0)
    {
        time++;

        int startX;
        int startY;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (g_map[i][j] == 0)
                {
                    g_mapTemp[i][j] = 0;
                    continue;
                }

                int countWaterBlock = 0;

                if (g_map[i][j - 1] == 0)
                {
                    countWaterBlock++;
                }

                if (g_map[i][j + 1] == 0)
                {
                    countWaterBlock++;
                }

                if (g_map[i - 1][j] == 0)
                {
                    countWaterBlock++;
                }

                if (g_map[i + 1][j] == 0)
                {
                    countWaterBlock++;
                }

                g_mapTemp[i][j] = std::max(g_map[i][j] - countWaterBlock, 0);

                if (g_mapTemp[i][j] == 0)
                {
                    iceCount--;
                }
                else
                {
                    startX = j;
                    startY = i;
                }
            }
        }

        memcpy(g_map, g_mapTemp, sizeof(int) * MAX_N * MAX_M);

        if (iceCount == 0)
        {
            std::cout << "0";
            return 0;
        }

        int currentIceCount = 0;
        std::stack<int> s;
        std::unordered_set<int> visited;
        s.push(startY * 1000 + startX);
        visited.insert(startY * 1000 + startX);

        while (s.empty() == false)
        {
            int x = s.top() % 1000;
            int y = s.top() / 1000;
            s.pop();

            currentIceCount++;

            if (g_map[y][x - 1] > 0 && visited.find(y * 1000 + (x - 1)) == visited.end())
            {
                s.push(y * 1000 + x - 1);
                visited.insert(y * 1000 + x - 1);
            }

            if (g_map[y][x + 1] > 0 && visited.find(y * 1000 + (x + 1)) == visited.end())
            {
                s.push(y * 1000 + x + 1);
                visited.insert(y * 1000 + x + 1);
            }

            if (g_map[y - 1][x] > 0 && visited.find((y - 1) * 1000 + x) == visited.end())
            {
                s.push((y - 1) * 1000 + x);
                visited.insert((y - 1) * 1000 + x);
            }

            if (g_map[y + 1][x] > 0 && visited.find((y + 1) * 1000 + x) == visited.end())
            {
                s.push((y + 1) * 1000 + x);
                visited.insert((y + 1) * 1000 + x);
            }
        }

        if (currentIceCount != iceCount)
        {
            std::cout << time;
            return 0;
        }
    }
}
