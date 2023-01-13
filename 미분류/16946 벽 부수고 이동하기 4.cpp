#include <iostream>
#include <set>
#include <queue>

#define MAX_N 1000
#define MAX_M 1000

#define WALL '1'
#define BLANK '0'

char g_map[MAX_N][MAX_M];
short g_result[MAX_N][MAX_M];

// 연결된 빈칸의 개수를 저장, 벽이라면 이 값은 0이 된다
// int*인 이유는 1) 빈칸에서 탐색으로 갈 수 있는 칸의 개수를 세서 이에 대한 포인터를 공유하게 하려고
//               2) 1을 통해 마지막에 g_result를 계산할 때 중복으로 계산하지 않게 하기 위함
int* g_linkedZeroCounts[MAX_N][MAX_M] = { nullptr, }; 


int main(void)
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> g_map[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (g_map[i][j] == WALL)
			{
				g_linkedZeroCounts[i][j] = new int;
				*(g_linkedZeroCounts[i][j]) = 0;
				continue;
			}

			if (g_linkedZeroCounts[i][j] != nullptr)
			{
				continue;
			}

			int* count = new int;
			g_linkedZeroCounts[i][j] = count;
			*count = 1;

			std::queue<int> q;
			q.push(i * 1000 + j);

			while (q.empty() == false)
			{
				int y = q.front() / 1000;
				int x = q.front() % 1000;
				q.pop();

				if (x > 0 && g_map[y][x - 1] == BLANK && g_linkedZeroCounts[y][x - 1] == nullptr)
				{
					*count += 1;
					q.push(y * 1000 + x - 1);
					g_linkedZeroCounts[y][x - 1] = count;
				}

				if (x < M - 1 && g_map[y][x + 1] == BLANK && g_linkedZeroCounts[y][x + 1] == nullptr)
				{
					*count += 1;
					q.push(y * 1000 + x + 1);
					g_linkedZeroCounts[y][x + 1] = count;
				}

				if (y > 0 && g_map[y - 1][x] == BLANK && g_linkedZeroCounts[y - 1][x] == nullptr)
				{
					*count += 1;
					q.push((y - 1) * 1000 + x);
					g_linkedZeroCounts[y - 1][x] = count;
				}

				if (y < N - 1 && g_map[y + 1][x] == BLANK && g_linkedZeroCounts[y + 1][x] == nullptr)
				{
					*count += 1;
					q.push((y + 1) * 1000 + x);
					g_linkedZeroCounts[y + 1][x] = count;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (g_map[i][j] == BLANK)
			{
				g_result[i][j] = 0;
				continue;
			}

			std::set<int*> countPointers;

			if (i > 0)
			{
				countPointers.insert(g_linkedZeroCounts[i - 1][j]);
			}

			if (i < N - 1)
			{
				countPointers.insert(g_linkedZeroCounts[i + 1][j]);
			}

			if (j > 0)
			{
				countPointers.insert(g_linkedZeroCounts[i][j - 1]);
			}

			if (j < M - 1)
			{
				countPointers.insert(g_linkedZeroCounts[i][j + 1]);
			}

			int totalCount = 1;
			for (int* countPointer : countPointers)
			{
				totalCount += *countPointer;
			}

			g_result[i][j] = totalCount % 10;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cout << g_result[i][j];
		}
		std::cout << '\n';
	}
}
