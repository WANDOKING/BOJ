#include <iostream>

int main(void)
{
	const int MAX = 1000;

	int n;
	int dp[MAX + 1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	scanf("%d", &n);

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	printf("%d", dp[n]);
}
