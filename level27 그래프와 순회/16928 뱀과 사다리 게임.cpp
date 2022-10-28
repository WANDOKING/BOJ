#include <iostream>
#include <queue>

#define MAX 100
#define MIN 1

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	bool visited[MAX + 1] = { 0, };
	int ladders[MAX + 1] = { 0, };
	int snakes[MAX + 1] = { 0, };
	int minRollDice[MAX + 1] = { 0, };

	int N;
	int M;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int laddersStart;
		int laddersEnd;

		std::cin >> laddersStart >> laddersEnd;

		ladders[laddersStart] = laddersEnd;
	}

	for (int i = 0; i < M; i++)
	{
		int snakeStart;
		int snakeEnd;

		std::cin >> snakeStart >> snakeEnd;

		snakes[snakeStart] = snakeEnd;
	}

	std::queue<int> q;

	q.push(MIN);
	minRollDice[MIN] = 0;
	visited[MIN] = true;

	while (q.empty() == false)
	{
		int visit = q.front();
		q.pop();

		if (visit == MAX)
		{
			break;
		}

		visited[visit] = true;

		for (int i = 1; i <= 6 && visit + i <= MAX; i++)
		{
			int tileToGo = visit + i;

			while (true)
			{
				if (ladders[tileToGo] != 0)
				{
					tileToGo = ladders[tileToGo];
				}
				else if (snakes[tileToGo] != 0)
				{
					tileToGo = snakes[tileToGo];
				}
				else
				{
					break;
				}
			}

			if (visited[tileToGo] == false)
			{
				visited[tileToGo] = true;
				minRollDice[tileToGo] = minRollDice[visit] + 1;
				q.push(tileToGo);
			}
		}
	}

	std::cout << minRollDice[MAX];
}
