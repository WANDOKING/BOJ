#include <iostream>

#define MAX_N 100
#define MAX_M 100

int g_basket[MAX_N + 1];

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		g_basket[i] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;

		std::cin >> a >> b;

		int temp = g_basket[a];
		g_basket[a] = g_basket[b];
		g_basket[b] = temp;
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cout << g_basket[i] << ' ';
	}
}
