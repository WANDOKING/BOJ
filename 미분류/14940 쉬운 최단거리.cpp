#include <iostream>
#include <queue>
#include <unordered_set>

#define MAX_N 1000
#define MAX_M 1000

int map[MAX_N][MAX_M];
int g_answer[MAX_N][MAX_M];

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;

    int startX;
    int startY;

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            g_answer[i][j] = -1;

            std::cin >> map[i][j];

            if (map[i][j] == 0)
            {
                g_answer[i][j] = 0;
            }

            if (map[i][j] == 2)
            {
                startX = j;
                startY = i;
                g_answer[i][j] = 0;
            }
        }
    }

    std::queue<int> bfs;
    std::unordered_set<int> visited;

    visited.insert(startX * 10000 + startY);

    bfs.push(startX * 10000 + startY);

    while (!bfs.empty())
    {
        int x = bfs.front() / 10000;
        int y = bfs.front() % 10000;
        int distance = g_answer[y][x];

        bfs.pop();

        if (x > 0 && map[y][x - 1] == 1 && visited.find((x - 1) * 10000 + y) == visited.end())
        {
            visited.insert((x - 1) * 10000 + y);
            bfs.push((x - 1) * 10000 + y);
            g_answer[y][x - 1] = distance + 1;
        }

        if (x < m - 1 && map[y][x + 1] == 1 && visited.find((x + 1) * 10000 + y) == visited.end())
        {
            visited.insert((x + 1) * 10000 + y);
            bfs.push((x + 1) * 10000 + y);
            g_answer[y][x + 1] = distance + 1;
        }

        if (y > 0 && map[y - 1][x] == 1 && visited.find(x * 10000 + y - 1) == visited.end())
        {
            visited.insert(x * 10000 + y - 1);
            bfs.push(x * 10000 + y - 1);
            g_answer[y - 1][x] = distance + 1;
        }

        if (y < n - 1 && map[y + 1][x] == 1 && visited.find(x * 10000 + y + 1) == visited.end())
        {
            visited.insert(x * 10000 + y + 1);
            bfs.push(x * 10000 + y + 1);
            g_answer[y + 1][x] = distance + 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {

            std::cout << g_answer[i][j] << ' ';
        }

        std::cout << '\n';
    }
}
