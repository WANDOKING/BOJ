#include <iostream>
#include <queue>

using namespace std;

struct document
{
    int index;
    int priority;
};

int main(void)
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        int M;
        queue<document> q;
        priority_queue<int> pq;
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++)
        {
            document d;
            d.index = i;
            scanf("%d", &d.priority);
            q.push(d);
            pq.push(d.priority);
        }

        int count = 1;
        while (true)
        {
            int topPriority = pq.top();

            if (q.front().priority == topPriority)
            {
                if (q.front().index == M)
                {
                    break;
                }

                count++;
                pq.pop();
                q.pop();
            }
            else
            {
                document temp = q.front();
                q.pop();
                q.push(temp);
            }
        }

        printf("%d\n", count);
    }
}
