#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    priority_queue<int> maxHeap; // 중간값보다 작은값
    priority_queue<int, vector<int>, greater<int>> minHeap; // 중간값보다 큰값

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (minHeap.size() >= maxHeap.size())
        {
            maxHeap.push(num);

            if (minHeap.empty() == false && maxHeap.top() > minHeap.top())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            if (minHeap.size() >= maxHeap.size() + 2)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else
        {
            minHeap.push(num);

            if (maxHeap.empty() == false && maxHeap.top() > minHeap.top())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if (maxHeap.size() >= minHeap.size() + 2)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }

        if (maxHeap.size() >= minHeap.size())
        {
            cout << maxHeap.top() << '\n';
        }
        else
        {
            cout << minHeap.top() << '\n';
        }
    }
}
