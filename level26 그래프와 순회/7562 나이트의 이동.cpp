#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    const int MAX_L = 300;
    int board[MAX_L][MAX_L];

    int testCaseNum;

    cin >> testCaseNum;

    for (int i = 0; i < testCaseNum; i++)
    {
        int l;
        int startPosX;
        int startPosY;
        int endPosX;
        int endPosY;

        cin >> l;
        cin >> startPosX >> startPosY;
        cin >> endPosX >> endPosY;

        pair<int, int> startPos = make_pair(startPosX, startPosY);
        pair<int, int> endPos = make_pair(endPosX, endPosY);

        set<pair<int, int>> visited;
        queue<pair<int, int>> q;

        q.push(startPos);
        board[startPos.first][startPos.second] = 0;

        int result = 0;
        int movesCount = 1;
        while (q.empty() == false)
        {
            pair<int, int> visit = q.front();
            int x = visit.first;
            int y = visit.second;
            q.pop();
            
            if (visit.first == endPos.first && visit.second == endPos.second)
            {
                break;
            }

            if (visited.find(visit) != visited.end())
            {
                goto NEXT_LOOP;
            }
            
            visited.insert(visit);

            if (x - 2 >= 0 && y - 1 >= 0)
            {
                q.push(make_pair(x - 2, y - 1));
            }
            if (x - 1 >= 0 && y - 2 >= 0)
            {
                q.push(make_pair(x - 1, y - 2));
            }
            if (x + 1 < l && y - 2 >= 0)
            {
                q.push(make_pair(x + 1, y - 2));
            }
            if (x + 2 < l && y - 1 >= 0)
            {
                q.push(make_pair(x + 2, y - 1));
            }
            if (x + 2 < l && y + 1 < l)
            {
                q.push(make_pair(x + 2, y + 1));
            }
            if (x + 1 < l && y + 2 < l)
            {
                q.push(make_pair(x + 1, y + 2));
            }
            if (x - 1 >= 0 && y + 2 < l)
            {
                q.push(make_pair(x - 1, y + 2));
            }
            if (x - 2 >= 0 && y + 1 < l)
            {
                q.push(make_pair(x - 2, y + 1));
            }
        NEXT_LOOP:
            movesCount--;
            if (movesCount == 0)
            {
                movesCount = q.size();
                result++;
            }
        }

        cout << result << '\n';
    }
}
