#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int g_orderCount = 1;

void Dfs(int v, vector<set<int>>& matrix, bool visited[], int order[])
{
    visited[v] = true;
    order[v] = g_orderCount++;

    set<int> neighbors = matrix[v];

    for (const int& i : neighbors)
    {
        if (visited[i] == false)
        {
            Dfs(i, matrix, visited, order);
        }
    }
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    int M;
    int R;

    cin >> N >> M >> R;

    vector<set<int>> matrix;

    for (int i = 0; i <= N; i++)
    {
        matrix.push_back(set<int>());
    }

    for (int i = 0; i < M; i++)
    {
        int v1;
        int v2;

        cin >> v1 >> v2;

        matrix[v1].insert(v2);
        matrix[v2].insert(v1);
    }

    bool bVisited[N + 1];
    memset(bVisited, false, sizeof(bool) * (N + 1));
    int order[N + 1];
    memset(order, 0, sizeof(int) * (N + 1));
    Dfs(R, matrix, bVisited, order);

    for (int i = 1; i <= N; i++)
    {
        cout << order[i] << '\n';
    }
}
