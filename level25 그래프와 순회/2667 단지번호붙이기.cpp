#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    const int MAX = 25;

    char board[MAX][MAX];
    int N;
    cin >> N;

    vector<pair<int, int>> houses;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '1')
            {
                houses.push_back(make_pair(j, i));
            }
        }
    }

    set<pair<int, int>> visited;
    vector<int> danjis;
    for (auto house : houses)
    {
        if (visited.find(house) != visited.end())
        {
            continue;
        }

        stack<pair<int, int>> s;
        s.push(house);

        int houseCount = 0;
        while (s.empty() == false)
        {
            pair<int, int> visit = s.top();
            s.pop();

            if (visited.find(visit) != visited.end())
            {
                continue;
            }

            visited.insert(visit);
            houseCount++;

            int x = visit.first;
            int y = visit.second;

            if (x > 0 && board[y][x - 1] == '1')
            {
                s.push(make_pair(x - 1, y));
            }
            if (x < N - 1 && board[y][x + 1] == '1')
            {
                s.push(make_pair(x + 1, y));
            }
            if (y > 0 && board[y - 1][x] == '1')
            {
                s.push(make_pair(x, y - 1));
            }
            if (y < N - 1 && board[y + 1][x] == '1')
            {
                s.push(make_pair(x, y + 1));
            }
        }

        danjis.push_back(houseCount);
    }

    sort(danjis.begin(), danjis.end());

    cout << danjis.size() << '\n';
    
    for (auto danji : danjis)
    {
        cout << danji << '\n';
    }
}
