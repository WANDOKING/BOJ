#include <iostream>
#include <vector>

#define MAX_N 1000000

// 각 노드의 부모 노드를 저장, g_parents[n] == n 이면 루트 노드
int g_parents[MAX_N + 1];

// 루트 노드를 찾는 함수
int GetParentRecursive(int n)
{
	if (n == g_parents[n])
	{
		return n;
	}

	g_parents[n] = GetParentRecursive(g_parents[n]);
	return g_parents[n];
}

// 두 집합을 합침
void Union(int a, int b)
{
	int parentOfA = GetParentRecursive(a);
	int parentOfB = GetParentRecursive(b);

	if (parentOfA < parentOfB)
	{
		g_parents[parentOfB] = a;
	}
	else if (parentOfA > parentOfB)
	{
		g_parents[parentOfA] = b;
	}
}

// 두 노드가 같은 집합에 속해있는지 확인
bool Find(int a, int b)
{
	return GetParentRecursive(a) == GetParentRecursive(b);
}

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int n;
	int m;

	std::cin >> n >> m;

	// 집합 초기화
	for (int i = 0; i <= n; ++i)
	{
		g_parents[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		const int OP_UNION = 0;
		const int OP_FIND = 1;

		int op;
		int a;
		int b;

		std::cin >> op >> a >> b;

		switch (op)
		{
		case OP_UNION:
			Union(a, b);
			break;
		case OP_FIND:
			if (Find(a, b) == true)
			{
				std::cout << "YES\n";
			}
			else
			{
				std::cout << "NO\n";
			}
			break;
		}
	}
}
