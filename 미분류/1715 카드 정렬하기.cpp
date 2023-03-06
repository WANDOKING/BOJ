#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 100'000

int g_nums[MAX_N];

int main(void)
{
    int N;
    std::cin >> N;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    long long result = 0;
    
    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin >> num;
        pq.push(num);
    }

    if (N == 1)
    {
        std::cout << 0;
        return 0;
    }

    while (pq.size() >= 2)
    {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();

        result += num1 + num2;
        pq.push(num1 + num2);
    }

    std::cout << result;
}
