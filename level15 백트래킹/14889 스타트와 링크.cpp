#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

int g_minStatsDiff = INT_MAX;

int GetTeamStatsDiff(const void* arr, int N, bool bTeamSelects[])
{
    const int (*stats)[N] = (const int(*)[N])arr;

    int team1StatsSum = 0;
    int team2StatsSum = 0;

    for (int i = 0; i < N;  i++)
    {
        bool bTeamI = bTeamSelects[i];

        for (int j = 0; j < N; j++)
        {
            bool bTeamJ = bTeamSelects[j];

            if (bTeamI == bTeamJ && bTeamI == true)
            {
                team1StatsSum += stats[i][j];
            }
            
            if (bTeamI == bTeamJ && bTeamI == false)
            {
                team2StatsSum += stats[i][j];
            }
        }
    }

    return abs(team1StatsSum - team2StatsSum);
}

void Dfs(const void* arr, int N, bool bTeamSelects[], int teamSelecting = 0, int depth = 0)
{
    if (depth == N / 2)
    {
        int teamStatsDiff = GetTeamStatsDiff(arr, N, bTeamSelects);

        if (teamStatsDiff < g_minStatsDiff)
        {
            g_minStatsDiff = teamStatsDiff;
        }

        return;
    }

    for (int i = teamSelecting; i < N; i++)
    {
        if (bTeamSelects[i] == false)
        {
            bTeamSelects[i] = true;
            Dfs(arr, N, bTeamSelects, i + 1, depth + 1);
        }

        bTeamSelects[i] = false;
    }

    return;
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int arr[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    bool bTeamSelects[N];
    memset(bTeamSelects, false, sizeof(bool) * N);
    Dfs(arr, N, bTeamSelects);

    cout << g_minStatsDiff << endl;
}
