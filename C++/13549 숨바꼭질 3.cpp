#include <iostream>
#include <deque>
#include <unordered_set>

#define MAX_N 100000

int main(void)
{
	int N;
	int K;

	std::cin >> N >> K;

	std::deque<std::pair<int, int>> q; // pos, time
	q.push_front(std::make_pair(N, 0));

	std::unordered_set<int> visited;
	
	// 0-1 BFS
	int result = -1;
	while (q.empty() == false)
	{
		int pos = q.front().first;
		int sec = q.front().second;
		q.pop_front();

		if (pos < 0 || pos > MAX_N * 2)
		{
			continue;
		}

		if (visited.find(pos) != visited.end())
		{
			continue;
		}

		if (pos == K)
		{
			result = sec;
			break;
		}

		visited.insert(pos);

		q.push_front(std::make_pair(pos * 2, sec));
		q.push_back(std::make_pair(pos - 1, sec + 1));
		q.push_back(std::make_pair(pos + 1, sec + 1));
		
	}

	std::cout << result;
}
