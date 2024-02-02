#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int g_visitOrderCount = 1;

void Dfs(int v, vector<vector<int>>& graph, unordered_set<int>& visited, vector<int>& visitOrders)
{
    if (visited.find(v) != visited.end())
    {
        return;
    }

    visitOrders[v] = g_visitOrderCount++;
    visited.insert(v);

    sort(graph[v].rbegin(), graph[v].rend());

    for (auto& neighbors : graph[v])
    {
        Dfs(neighbors, graph, visited, visitOrders);
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

    vector<vector<int>> graph;
    vector<int> visitOrders;

    for (int i = 0; i <= N; i++)
    {
        graph.push_back(vector<int>());
        visitOrders.push_back(0);
    }

    for (int i = 0; i < M; i++)
    {
        int v1;
        int v2;

        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    unordered_set<int> visited;
    Dfs(R, graph, visited, visitOrders);

    for (int i = 1; i <= N; i++)
    {
        cout << visitOrders[i] << '\n';
    }
}
