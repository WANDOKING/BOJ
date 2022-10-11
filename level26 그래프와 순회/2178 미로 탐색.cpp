#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    const int MAX = 100;

    int maze[MAX][MAX];

    int N;
    int M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char input;
            cin >> input;

            maze[i][j] = input - '0';
        }
    }

    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    int moveCount = 1;

    q.push(make_pair(0, 0));

    while (q.empty() == false)
    {
        pair<int, int> visit = q.front();
        q.pop();

        if (visited.find(visit) != visited.end())
        {
            continue;
        }

        visited.insert(visit);

        int x = visit.second;
        int y = visit.first;

        if (x > 0 && maze[y][x - 1] != 0)
        {
            if (maze[y][x - 1] == 1)
            {
                maze[y][x - 1] = maze[y][x] + 1;
            }

            q.push(make_pair(y, x - 1));
        }

        if (x < M - 1 && maze[y][x + 1] != 0)
        {
            if (maze[y][x + 1] == 1)
            {
                maze[y][x + 1] = maze[y][x] + 1;
            }

            q.push(make_pair(y, x + 1));
        }

        if (y > 0 && maze[y - 1][x] != 0)
        {
            if (maze[y - 1][x] == 1)
            {
                maze[y - 1][x] = maze[y][x] + 1;
            }

            q.push(make_pair(y - 1, x));
        }

        if (y < N - 1 && maze[y + 1][x] != 0)
        {
            if (maze[y + 1][x] == 1)
            {
                maze[y + 1][x] = maze[y][x] + 1;
            }

            q.push(make_pair(y + 1, x));
        }
    }

    cout << maze[N - 1][M - 1];

    return 0;
}
