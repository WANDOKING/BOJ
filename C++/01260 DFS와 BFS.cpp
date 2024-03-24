#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N; // 정점의 개수
    int M; // 간선의 개수
    int V; // 시작 정점 번호

    cin >> N >> M >> V;

    // init
    vector<set<int>> graph;
    for (int i = 0; i < N + 1; i++)
    {
        graph.push_back(set<int>());
    }

    // input
    for (int i = 0; i < M; i++)
    {
        int v1;
        int v2;

        cin >> v1 >> v2;

        graph[v1].insert(v2);
        graph[v2].insert(v1);
    }

    stack<int> dfs;
    unordered_set<int> dfsVisited;
    dfs.push(V);

    while (dfs.empty() == false)
    {
        int visit = dfs.top();
        dfs.pop();

        if (dfsVisited.find(visit) != dfsVisited.end())
        {
            continue;
        }

        cout << visit << ' ';
        dfsVisited.insert(visit);

        for (auto neighbor = graph[visit].rbegin(); neighbor != graph[visit].rend(); neighbor++)
        {
            dfs.push(*neighbor);
        }
    }

    cout << '\n';
    
    queue<int> bfs;
    unordered_set<int> bfsVisited;
    bfs.push(V);

    while (bfs.empty() == false)
    {
        int visit = bfs.front();
        bfs.pop();

        if (bfsVisited.find(visit) != bfsVisited.end())
        {
            continue;
        }

        cout << visit << ' ';
        bfsVisited.insert(visit);

        for (auto neighbor : graph[visit])
        {
            bfs.push(neighbor);
        }
    }
}
