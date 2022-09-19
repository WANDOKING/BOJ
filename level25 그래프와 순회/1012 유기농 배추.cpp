#include <iostream>
#include <cstring>

using namespace std;

void Dfs(void* field, int N, int M, int x, int y)
{
    int(*f)[M] = (int(*)[M])field;
    f[y][x] *= 2;

    if (x > 0 && f[y][x - 1] == 1)
    {
        Dfs(field, N, M, x - 1, y);
    }
    if (x < M - 1 && f[y][x + 1] == 1)
    {
        Dfs(field, N, M, x + 1, y);
    }
    if (y > 0 && f[y - 1][x] == 1)
    {
        Dfs(field, N, M, x, y - 1);
    }
    if (y < N - 1 && f[y + 1][x] == 1)
    {
        Dfs(field, N, M, x, y + 1);
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int M;
        int N;
        int K;
        cin >> M >> N >> K;

        int field[N][M];
        memset(field, 0, sizeof(int) * N * M);

        for (int j = 0; j < K; j++)
        {
            int x;
            int y;
            cin >> x >> y;

            field[y][x] = 1;
        }

        int result = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (field[j][k] != 1)
                {
                    continue;
                }

                result++;
                Dfs(field, N, M, k, j);
            }
        }

        cout << result << '\n';
    }
}
