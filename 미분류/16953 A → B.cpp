#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main(void)
{
    long long A;
    long long B;

    cin >> A >> B;

    queue<pair<long long, int>> q;
    q.push(make_pair(A, 1));
    unordered_set<long long> visited;

    int result = -1;
    while (q.empty() == false)
    {
        long long num = q.front().first;
        int operationCount = q.front().second;
        q.pop();

        if (visited.find(num) != visited.end())
        {
            continue;
        }

        if (num == B)
        {
            result = operationCount;
            break;
        }

        visited.insert(num);

        if (num * 2 <= B)
        {
            q.push(make_pair(num * 2, operationCount + 1));
        }

        if (num * 10 + 1 <= B)
        {
            q.push(make_pair(num * 10 + 1, operationCount + 1));
        }
    }

    std::cout << result;
}
