#include <iostream>

long long SolveRecursive(long long A, long long B, long long C)
{
	if (B == 0)
	{
		return 1;
	}

	if (B == 1)
	{
		return A % C;
	}

	A %= C;

	return SolveRecursive((A * A) % C, B / 2, C) * SolveRecursive(A, B % 2, C) % C;
}

int main(void)
{
	long long A;
	long long B;
	long long C;

	scanf("%lld %lld %lld", &A, &B, &C);

	long long result = SolveRecursive(A, B, C);

	printf("%lld", result);
}
