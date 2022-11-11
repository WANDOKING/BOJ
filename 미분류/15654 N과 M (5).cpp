#include <iostream>
#include <algorithm>

#define MAX_N 8

int g_nums[MAX_N];
int g_N;
int g_M;

int g_backtrackingResult[MAX_N];
bool g_used[MAX_N] = { false, };

void BacktrackingRecursive(int depth = 0)
{
	if (depth == g_M)
	{
		for (int i = 0; i < g_M; i++)
		{
			std::cout << g_backtrackingResult[i] << ' ';
		}

		std::cout << '\n';
		return;
	}

	for (int i = 0; i < g_N; i++)
	{
		if (g_used[i] == true)
		{
			continue;
		}

		g_backtrackingResult[depth] = g_nums[i];
		g_used[i] = true;
		BacktrackingRecursive(depth + 1);
		g_used[i] = false;
	}
}

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	std::cin >> g_N >> g_M;

	for (int i = 0; i < g_N; i++)
	{
		std::cin >> g_nums[i];
	}

	std::sort(g_nums, g_nums + g_N);

	BacktrackingRecursive();
}
