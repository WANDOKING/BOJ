#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second > b.second) {
            return true;
        }

        return false;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int vertexNum;
    int edgeNum;
    int startVertex;

    cin >> vertexNum >> edgeNum >> startVertex;

    vector<vector<pair<int, char>>> graph;
    vector<int> result;

    for (int i = 0; i <= vertexNum; i++)
    {
        graph.push_back(vector<pair<int, char>>());

        result.push_back(INT_MAX / 2);
    }

    for (int i = 0; i < edgeNum; i++)
    {
        int u;
        int v;
        int w;

        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
    }

    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> dijkstra; // vertex, dist 

    for (int i = 1; i <= vertexNum; i++)
    {
        if (i == startVertex)
        {
            dijkstra.push(make_pair(i, 0));
        }
        else
        {
            dijkstra.push(make_pair(i, INT_MAX / 2));
        }
    }

    result[startVertex] = 0;

    while (visited.size() < vertexNum)
    {
        int minDistVertexNum = dijkstra.top().first;
        int minDist = dijkstra.top().second;

        dijkstra.pop();

        if (visited.find(minDistVertexNum) != visited.end())
        {
            continue;
        }

        if (minDist != result[minDistVertexNum])
        {
            continue;
        }

        visited.insert(minDistVertexNum);

        // neighbor process
        for (pair<int, char>& neighnor : graph[minDistVertexNum])
        {
            if (neighnor.second + minDist < result[neighnor.first])
            {
                result[neighnor.first] = neighnor.second + minDist;
                dijkstra.push(make_pair(neighnor.first, result[neighnor.first]));
            }
        }
    }

    // output
    for (int i = 1; i <= vertexNum; i++)
    {
        if (result[i] == INT_MAX / 2)
        {
            cout << "INF\n";
        }
        else
        {
            cout << result[i] << '\n';
        }
    }

    return 0;
}
