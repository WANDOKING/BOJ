#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;

    cin >> N >> M;

    queue<int> nums;
    for (int i = 1; i <= N; i++)
    {
        nums.push(i);
    }

    queue<int> inputs;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        inputs.push(num);
    }

    int totalCount = 0;
    while (inputs.empty() == false)
    {
        int num = inputs.front();
        inputs.pop();

        int count = 0;
        while (nums.front() != num)
        {
            count++;
            nums.push(nums.front());
            nums.pop();
        }

        // 반절보다 많이 돌았으면 반대쪽으로 했으면 더 빨랐을 것
        if (count > nums.size() / 2)
        {
            count = nums.size() - count;
        }

        totalCount += count;

        nums.pop();
    }

    cout << totalCount << '\n';
}
