#include <iostream>
#include <queue>
#include <unordered_map>

#define MAX_POS 100000

int main(void)
{
    int N;
    int K;

    std::cin >> N >> K;

    std::queue<std::pair<int, int>> q;
    std::unordered_map<int, int> minTimes;

    q.push(std::make_pair(N, 0));

    int minTime = -1;
    int countRoute = 0;

    while (q.empty() == false)
    {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();

        if (minTime != -1 && time > minTime)
        {
            break;
        }

        if (minTime == -1 && pos == K)
        {
            minTime = time;
            countRoute++;
            continue;
        }

        if (minTime == time && pos == K)
        {
            countRoute++;
            continue;
        }

        auto temp = minTimes.find(pos);
        if (temp != minTimes.end() && time > temp->second)
        {
            continue;
        }

        minTimes[pos] = time;

        int nextPos1 = pos - 1;
        int nextPos2 = pos + 1;
        int nextPos3 = pos * 2;

        q.push(std::make_pair(nextPos1, time + 1));
        q.push(std::make_pair(nextPos2, time + 1));

        if (nextPos3 <= MAX_POS * 2 && nextPos3 >= 0)
        {
            q.push(std::make_pair(nextPos3, time + 1));
        }
    }

    std::cout << minTime << '\n' << countRoute;
}
