#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    const int NONE = -1;

    vector<vector<vector<int>>> box; // H, N, M

    int M;
    int N;
    int H;

    cin >> M >> N >> H;

    int maxCountRipes = H * N * M;
    int countRipes = 0;

    queue<tuple<int, int, int>> q;

    for (int i = 0; i < H; i++)
    {
        box.push_back(vector<vector<int>>());
        box[i].reserve(N);
        for (int j = 0; j < N; j++)
        {
            box[i].push_back(vector<int>());
            box[i][j].reserve(M);
            for (int k = 0; k < M; k++)
            {
                int input;
                cin >> input;
                box[i][j].push_back(input);

                if (box[i][j][k] == 1)
                {
                    countRipes++;
                    q.push(make_tuple(i, j, k));
                }
                else if (box[i][j][k] == NONE)
                {
                    maxCountRipes--;
                }
            }
        }
    }

    // 이미 모든 토마토가 익어있는 상태라면 0을 출력
    if (countRipes == maxCountRipes)
    {
        cout << '0';
        return 0;
    }

    // bfs 시작

    int result = 0;
    while (q.empty() == false)
    {
        const tuple<int, int, int>& visit = q.front();

        int z = get<0>(visit);
        int y = get<1>(visit);
        int x = get<2>(visit);

        q.pop();

        if (box[z][y][x] > result)
        {
            result = box[z][y][x];
        }

        if ((z > 0) && (box[z - 1][y][x] == 0))
        {
            countRipes++;
            box[z - 1][y][x] = box[z][y][x] + 1;
            q.push(make_tuple(z - 1, y, x));
        }

        if ((z < H - 1) && (box[z + 1][y][x] == 0))
        {
            countRipes++;
            box[z + 1][y][x] = box[z][y][x] + 1;
            q.push(make_tuple(z + 1, y, x));
        }

        if ((y > 0) && (box[z][y - 1][x] == 0))
        {
            countRipes++;
            box[z][y - 1][x] = box[z][y][x] + 1;
            q.push(make_tuple(z, y - 1, x));
        }

        if ((y < N - 1) && (box[z][y + 1][x] == 0))
        {
            countRipes++;
            box[z][y + 1][x] = box[z][y][x] + 1;
            q.push(make_tuple(z, y + 1, x));
        }

        if ((x > 0) && (box[z][y][x - 1] == 0))
        {
            countRipes++;
            box[z][y][x - 1] = box[z][y][x] + 1;
            q.push(make_tuple(z, y, x - 1));
        }

        if ((x < M - 1) && (box[z][y][x + 1] == 0))
        {
            countRipes++;
            box[z][y][x + 1] = box[z][y][x] + 1;
            q.push(make_tuple(z, y, x + 1));
        }

        if (countRipes == maxCountRipes)
        {
            break;
        }
    }

    if (countRipes == maxCountRipes)
    {
        cout << result;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
