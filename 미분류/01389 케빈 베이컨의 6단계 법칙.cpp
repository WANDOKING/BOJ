#include <climits>
#include <algorithm>
#include <iostream>

#define MAX 100

using namespace std;

int main(void)
{
	int graph[MAX][MAX];
	int N;
	int M;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i == j)
			{
				graph[i][j] = 0;
			}
			else
			{
				graph[i][j] = SHRT_MAX;
			}
		}
	}

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int v1;
		int v2;

		cin >> v1 >> v2;

		v1--;
		v2--;

		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	// floyd warshall
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
					graph[j][i] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int minKevinBaconValue = INT_MAX;
	int minKevinBaconVertex = INT_MAX;

	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			sum += graph[i][j];
		}

		if (sum < minKevinBaconValue)
		{
			minKevinBaconValue = sum;
			minKevinBaconVertex = i + 1;
		}
	}

	cout << minKevinBaconVertex;
}
