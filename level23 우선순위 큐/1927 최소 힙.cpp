#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    int N;

    scanf("%d", &N);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int input;

        scanf("%d", &input);

        if (input == 0)
        {
            if (pq.empty() == true)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(input);
        }
    }
}
