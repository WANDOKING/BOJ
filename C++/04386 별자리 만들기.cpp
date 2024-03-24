#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 100

struct Point
{
	float X;
	float Y;
};

Point g_stars[MAX_N];
int g_parents[MAX_N];

int GetParentsRecursive(int n)
{
	if (g_parents[n] == n)
	{
		return n;
	}

	g_parents[n] = GetParentsRecursive(g_parents[n]);
	return g_parents[n];
}

bool Find(int a, int b)
{
	int parentA = GetParentsRecursive(a);
	int parentB = GetParentsRecursive(b);

	return parentA == parentB;
}

void Union(int a, int b)
{
	int parentA = GetParentsRecursive(a);
	int parentB = GetParentsRecursive(b);

	int minParent = std::min(parentA, parentB);
	g_parents[parentA] = minParent;
	g_parents[parentB] = minParent;
}

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> g_stars[i].X >> g_stars[i].Y;
	}

	if (n == 1)
	{
		std::cout << 0;
		return 0;
	}

	std::vector<std::tuple<float, int, int>> edges; // weight, v1, v2
	edges.reserve((n * (n - 1)) / 2);

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			float xDiff = g_stars[i].X - g_stars[j].X;
			float yDiff = g_stars[i].Y - g_stars[j].Y;
			float distance = std::sqrt((xDiff * xDiff) + (yDiff * yDiff));
			edges.push_back(std::make_tuple(distance, i, j));
		}
	}

	std::sort(edges.begin(), edges.end());

	for (int i = 0; i < n; ++i)
	{
		g_parents[i] = i;
	}

	float result = 0.0f;
	for (auto edge : edges)
	{
		float distance = std::get<0>(edge);
		int v1 = std::get<1>(edge);
		int v2 = std::get<2>(edge);

		if (Find(v1, v2) == true)
		{
			continue;
		}

		result += distance;
		Union(v1, v2);
	}

	std::cout << result;
}
