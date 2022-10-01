#include <iostream>
#include <cstring>
#include <queue>

#define MAX 100000

using namespace std;

int main(void)
{

    int N;
    int K;
    int times[MAX + 1];
    memset(times, 0, sizeof(int) * (MAX + 1));

    scanf("%d %d", &N, &K);

    queue<int> q;
    q.push(N);
    times[N] = 0;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

        if (front == K)
        {
            break;
        }

        if (front - 1 >= 0 && times[front - 1] == 0 && front - 1 != N)
        {
            times[front - 1] = times[front] + 1;
            q.push(front - 1);
        }

        if (front + 1 <= MAX && times[front + 1] == 0 && front + 1 != N)
        {
            times[front + 1] = times[front] + 1;
            q.push(front + 1);
        }

        if (front * 2 <= MAX && times[front * 2] == 0 && front * 2 != N)
        {
            times[front * 2] = times[front] + 1;
            q.push(front * 2);
        }
    }

    printf("%d", times[K]);
}
