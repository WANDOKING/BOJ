#include <cassert>
#include <iostream>
#include <unordered_set>

#define MAX 1000

char g_map[MAX][MAX];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> g_map[i][j];
        }
    }

    // y + x * 1000
    std::unordered_set<int> totalVisited;
    
    int result = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int x = j;
            int y = i;

            std::unordered_set<int> visited;

            if (totalVisited.find(y + x * 1000) != totalVisited.end())
            {
                continue;
            }

            while (true)
            {
                if (visited.find(y + x * 1000) != visited.end())
                {
                    ++result;
                    break;
                }

                if (totalVisited.find(y + x * 1000) != totalVisited.end())
                {
                    break;
                }

                totalVisited.insert(y + x * 1000);
                visited.insert(y + x * 1000);

                switch (g_map[y][x])
                {
                case 'D':
                    y += 1;
                    break;
                case 'U':
                    y -= 1;
                    break;
                case 'L':
                    x -= 1;
                    break;
                case 'R':
                    x += 1;
                    break;
                default:
                    assert(false);
                }
                
                assert(x >= 0 || x < M || y >= 0 || y < N);
            }
        }
    }

    std::cout << result;
}
