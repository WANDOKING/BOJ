#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <climits>

using namespace std;

int main(void)
{
    int M;
    int N;

    vector<vector<int>> box;
    queue<pair<int, int>> q;

    scanf("%d %d", &M, &N);

    int ripeTomatoCount = 0;
    int totalTomatoNum = N * M;

    for (int i = 0; i < N; i++)
    {
        box.push_back(vector<int>());

        for (int j = 0; j < M; j++)
        {
            int input;
            scanf("%d", &input);

            box[i].push_back(input);

            if (box[i][j] == 1)
            {
                q.push(make_pair(i, j));
                ripeTomatoCount++;
            }
            else if (box[i][j] == -1)
            {
                totalTomatoNum--;
            }
        }
    }

    if (ripeTomatoCount == totalTomatoNum)
    {
        printf("0");
        return 0;
    }

    int dayCount = 1;
    while (q.empty() == false)
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        dayCount = box[i][j];

        // left
        if (j > 0 && box[i][j - 1] == 0)
        {
            box[i][j - 1] = box[i][j] + 1;
            ripeTomatoCount++;
            q.push(make_pair(i, j - 1));
        }

        // right
        if (j + 1 < M && box[i][j + 1] == 0)
        {
            box[i][j + 1] = box[i][j] + 1;
            ripeTomatoCount++;
            q.push(make_pair(i, j + 1));
        }

        // up
        if (i > 0 && box[i - 1][j] == 0)
        {
            box[i - 1][j] = box[i][j] + 1;
            ripeTomatoCount++;
            q.push(make_pair(i - 1, j));
        }

        // down
        if (i + 1 < N && box[i + 1][j] == 0)
        {
            box[i + 1][j] = box[i][j] + 1;
            ripeTomatoCount++;
            q.push(make_pair(i + 1, j));
        }
    }

    if (ripeTomatoCount == totalTomatoNum)
    {
        printf("%d", dayCount - 1);
    }
    else
    {
        printf("-1");
    }
}
