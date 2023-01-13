#include <iostream>
#include <set>
#include <queue>

#define MAX_N 1000
#define MAX_M 1000

char g_map[MAX_N][MAX_M];
int* g_linkedOneCounts[MAX_N][MAX_M] = { nullptr, }; 


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
			if (g_map[i][j] == '0')
			{
				g_linkedOneCounts[i][j] = new int;
				*(g_linkedOneCounts[i][j]) = 0;
				continue;
			}

			if (g_linkedOneCounts[i][j] != nullptr)
			{
				continue;
			}

			int* count = new int;
			g_linkedOneCounts[i][j] = count;
			*count = 1;

			std::queue<int> q;
			q.push(i * 1000 + j);

			while (q.empty() == false)
			{
				int y = q.front() / 1000;
				int x = q.front() % 1000;
				q.pop();

				if (x > 0 && g_map[y][x - 1] == '1' && g_linkedOneCounts[y][x - 1] == nullptr)
				{
					*count += 1;
					q.push(y * 1000 + x - 1);
					g_linkedOneCounts[y][x - 1] = count;
				}

				if (x < M - 1 && g_map[y][x + 1] == '1' && g_linkedOneCounts[y][x + 1] == nullptr)
				{
					*count += 1;
					q.push(y * 1000 + x + 1);
					g_linkedOneCounts[y][x + 1] = count;
				}

				if (y > 0 && g_map[y - 1][x] == '1' && g_linkedOneCounts[y - 1][x] == nullptr)
				{
					*count += 1;
					q.push((y - 1) * 1000 + x);
					g_linkedOneCounts[y - 1][x] = count;
				}

				if (y < N - 1 && g_map[y + 1][x] == '1' && g_linkedOneCounts[y + 1][x] == nullptr)
				{
					*count += 1;
					q.push((y + 1) * 1000 + x);
					g_linkedOneCounts[y + 1][x] = count;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::set<int*> countPointers;

			if (i > 0)
			{
				countPointers.insert(g_linkedOneCounts[i - 1][j]);
			}

			if (i < N - 1)
			{
				countPointers.insert(g_linkedOneCounts[i + 1][j]);
			}

			if (j > 0)
			{
				countPointers.insert(g_linkedOneCounts[i][j - 1]);
			}

			if (j < M - 1)
			{
				countPointers.insert(g_linkedOneCounts[i][j + 1]);
			}

			int totalCount = 1;
			for (int* countPointer : countPointers)
			{
				totalCount += *countPointer;
			}

			if (totalCount > result)
			{
				result = totalCount;
			}
		}
	}
	
	std::cout << result;
}
