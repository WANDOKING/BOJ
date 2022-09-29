#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;

    cin >> N;

    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (pq.empty() == true)
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
