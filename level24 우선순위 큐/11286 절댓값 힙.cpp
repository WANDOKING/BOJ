#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

bool compare(int a, int b)
{
    if (abs(a) == abs(b))
    {
        if (a < b)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (abs(a) < abs(b))
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    priority_queue<int, vector<int>, bool (*)(int, int)> pq(compare);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(input);
        }
    }
}
