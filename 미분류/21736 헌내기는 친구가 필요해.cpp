#include <iostream>
#include <stack>
#include <unordered_set>

#define MAX_N 600
#define MAX_M 600

char g_map[MAX_N][MAX_M];

struct MyHash
{
    size_t operator()(const std::pair<short, short>& s) const noexcept
    {
        return s.first * 1000 + s.second;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    int startX;
    int startY;

    std::cin >> N >> M;

    std::cin.get();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            g_map[i][j] = std::cin.get();

            if (g_map[i][j] == 'I')
            {
                startX = j;
                startY = i;
            }
        }
        std::cin.get();
    }

    std::stack<std::pair<short, short>> dfs;
    std::unordered_set<std::pair<short, short>, MyHash> visited;

    dfs.push(std::make_pair(startX, startY));
    visited.insert(std::make_pair(startX, startY));

    int result = 0;

    while (dfs.empty() == false)
    {
        int x = dfs.top().first;
        int y = dfs.top().second;

        dfs.pop();

        if (g_map[y][x] == 'P')
        {
            result++;
        }

        if (x > 0 && g_map[y][x - 1] != 'X' && visited.find(std::make_pair(x - 1, y)) == visited.end())
        {
            dfs.push(std::make_pair(x - 1, y));
            visited.insert(std::make_pair(x - 1, y));
        }
        if (x < M - 1 && g_map[y][x + 1] != 'X' && visited.find(std::make_pair(x + 1, y)) == visited.end())
        {
            dfs.push(std::make_pair(x + 1, y));
            visited.insert(std::make_pair(x + 1, y));
        }
        if (y > 0 && g_map[y - 1][x] != 'X' && visited.find(std::make_pair(x, y - 1)) == visited.end())
        {
            dfs.push(std::make_pair(x, y - 1));
            visited.insert(std::make_pair(x, y - 1));
        }
        if (y < N - 1 && g_map[y + 1][x] != 'X' && visited.find(std::make_pair(x, y + 1)) == visited.end())
        {
            dfs.push(std::make_pair(x, y + 1));
            visited.insert(std::make_pair(x, y + 1));
        }
    }

    if (result == 0)
    {
        std::cout << "TT";
    }
    else
    {
        std::cout << result;
    }
}
