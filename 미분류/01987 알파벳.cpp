#include <iostream>
#include <queue>

#define MAX 20

char g_board[MAX][MAX];

struct VisitInfo
{
	int Pos; // y * 100 + x
	unsigned int bVisited;
	int length;
};

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int R;
	int C;
	std::cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			std::cin >> g_board[i][j];
		}
	}

	std::queue<VisitInfo> q;
	VisitInfo first = { 0, 0, 1 };
	q.push(first);

	int result = 0;
	while (q.empty() == false)
	{
		VisitInfo visit = q.front();
		int y = visit.Pos / 100;
		int x = visit.Pos % 100;
		q.pop();

		if (visit.length > result)
		{
			result = visit.length;
		}

		visit.bVisited |= 1 << (g_board[y][x] - 'A');

		if (x > 0 && ((visit.bVisited & (1 << (g_board[y][x - 1] - 'A'))) == 0))
		{
			VisitInfo next = visit;
			next.Pos = y * 100 + (x - 1);
			next.length++;
			q.push(next);
		}

		if (x < C - 1 && ((visit.bVisited & (1 << (g_board[y][x + 1] - 'A'))) == 0))
		{
			VisitInfo next = visit;
			next.Pos = y * 100 + (x + 1);
			next.length++;
			q.push(next);
		}

		if (y > 0 && ((visit.bVisited & (1 << (g_board[y - 1][x] - 'A'))) == 0))
		{
			VisitInfo next = visit;
			next.Pos = (y - 1) * 100 + x;
			next.length++;
			q.push(next);
		}

		if (y < R - 1 && ((visit.bVisited & (1 << (g_board[y + 1][x] - 'A'))) == 0))
		{
			VisitInfo next = visit;
			next.Pos = (y + 1) * 100 + x;
			next.length++;
			q.push(next);
		}
	}

	std::cout << result;
}
