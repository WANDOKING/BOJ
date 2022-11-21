#include <iostream>
#include <queue>
#include <tuple>
#include <set>

#define MAX 1000

#define WALL '1'

char g_map [MAX][MAX];

int main(void)
{
    int N;
    int M;

    // input
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> g_map[i][j];
        }
    }

    std::queue<std::tuple<int, int, bool>> q; // yx, distance, wallBreak
    q.push(std::make_tuple(0, 1, true));

    std::set<std::pair<int, bool>> visited; // yx, wallBreak

    int result = -1;
    while (q.empty() == false)
    {
        int y = std::get<0>(q.front()) / 1000;
        int x = std::get<0>(q.front()) % 1000;
        int distance = std::get<1>(q.front());
        bool bCanBreakWall = std::get<2>(q.front());

        if (y == N - 1 && x == M - 1)
        {
            result = distance;
            break;
        }

        if (g_map[y][x] == WALL)
        {
            bCanBreakWall = false;
        }

        auto visitInfo = std::make_pair(std::get<0>(q.front()), bCanBreakWall);
        if (visited.find(visitInfo) != visited.end())
        {
            q.pop();
            continue;
        }

        visited.insert(visitInfo);
        q.pop();

        // 조건에 맞는 경로들 큐에 push
        if (y > 0 && ((g_map[y - 1][x] == WALL && bCanBreakWall) || (g_map[y - 1][x] != WALL)))
        {
            q.push(std::make_tuple((y - 1) * 1000 + x, distance + 1, bCanBreakWall));
        }

        if (y < N - 1 && ((g_map[y + 1][x] == WALL && bCanBreakWall) || (g_map[y + 1][x] != WALL)))
        {
            q.push(std::make_tuple((y + 1) * 1000 + x, distance + 1, bCanBreakWall));
        }

        if (x > 0 && ((g_map[y][x - 1] == WALL && bCanBreakWall) || (g_map[y][x - 1] != WALL)))
        {
            q.push(std::make_tuple(y * 1000 + (x - 1), distance + 1, bCanBreakWall));
        }
        
        if (x < M - 1 && ((g_map[y][x + 1] == WALL && bCanBreakWall) || (g_map[y][x + 1] != WALL)))
        {
            q.push(std::make_tuple(y * 1000 + (x + 1), distance + 1, bCanBreakWall));
        }
    }

    std::cout << result;
}
