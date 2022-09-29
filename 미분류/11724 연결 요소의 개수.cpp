#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

int main(void)
{
    int N;
    int M;

    scanf("%d %d", &N, &M);

    vector<vector<int>> graph;
    graph.reserve(N);

    for (int i = 0; i < N + 1; i++)
    {
        graph.push_back(vector<int>());
    }

    for (int i = 0; i < M; i++)
    {
        int v1;
        int v2;

        scanf("%d %d", &v1, &v2);

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    unordered_set<int> visited;

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        // 방문했었다면 패스
        if (visited.find(i) != visited.end())
        {
            continue;
        }

        // 방문한 적이 없으면 DFS
        stack<int> s;
        s.push(i);
        visited.insert(i);
        while (s.empty() == false)
        {
            int vertex = s.top();
            s.pop();

            for (int& neighbor : graph[vertex])
            {
                if (visited.find(neighbor) != visited.end())
                {
                    continue;
                }

                visited.insert(neighbor);
                s.push(neighbor);
            }
        }

        count++;
    }

    printf("%d", count);
}
