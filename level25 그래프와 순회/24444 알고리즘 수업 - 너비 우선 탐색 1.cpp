#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    int M;
    int R;

    cin >> N >> M >> R;

    vector<set<int>> graph;
    vector<int> result;
    graph.reserve(N + 1);
    result.reserve(N + 1);

    for (int i = 0; i <= N; i++)
    {
        graph.push_back(set<int>());
        result.push_back(0);
    }

    for (int i = 0; i < M; i++)
    {
        int v1;
        int v2;

        cin >> v1 >> v2;

        graph[v1].insert(v2);
        graph[v2].insert(v1);
    }

    unordered_set<int> visited;
    queue<int> q;

    q.push(R);

    int visitOrder = 1;
    while (q.empty() == false)
    {
        int visit = q.front();
        q.pop();

        if (visited.find(visit) != visited.end())
        {
            continue;
        }

        visited.insert(visit);
        result[visit] = visitOrder++;

        for (auto& neighbor : graph[visit])
        {
            q.push(neighbor);
        }
    }

    for (int i = 1; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }
}
