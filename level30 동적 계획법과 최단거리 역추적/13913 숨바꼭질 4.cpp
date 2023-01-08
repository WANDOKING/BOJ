#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    int K;
    cin >> N >> K;

    if (N >= K)
    {
        cout << N - K << '\n';
        while (N >= K)
        {
            cout << N << ' ';
            --N;
        }
        return 0;
    }

    queue<pair<int, vector<int>>> q;
    unordered_set<int> visited;

    q.push(make_pair(N, vector<int>()));
    visited.insert(N);

    while (q.empty() == false)
    {
        int currentPos = q.front().first;
        vector<int>& currentPath = q.front().second;

        // find answer
        if (currentPos == K)
        {
            cout << currentPath.size() << '\n';
            for (int pos : currentPath)
            {
                cout << pos << ' ';
            }
            cout << K;
            break;
        }

        if (currentPos < 0)
        {
            q.pop();
            continue;
        }

        currentPath.push_back(currentPos);

        if (visited.find(currentPos - 1) == visited.end())
        {
            q.push(make_pair(currentPos - 1, currentPath));
            visited.insert(currentPos - 1);
        }
        
        if (currentPos < K && visited.find(currentPos + 1) == visited.end())
        {
            q.push(make_pair(currentPos + 1, currentPath));
            visited.insert(currentPos + 1);
        }

        if (currentPos * 2 < K + K / 2 && visited.find(currentPos * 2) == visited.end())
        {
            q.push(make_pair(currentPos * 2, currentPath));
            visited.insert(currentPos * 2);
        }

        q.pop();
    }
}
