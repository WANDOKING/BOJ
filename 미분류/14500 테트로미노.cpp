#include <iostream>

#define MAX 500

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	std::cin >> N >> M;

	short nums[MAX][MAX];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> nums[i][j];
		}
	}

	// brute force
	short maxSum = -1;
	short sum = -1;

	// [][][][]
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= M - 4; j++)
		{
			sum = nums[i][j] + nums[i][j + 1] + nums[i][j + 2] + nums[i][j + 3];
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	// []
	// []
	// []
	// []
	for (int i = 0; i <= N - 4; i++)
	{
		for (int j = 0; j < M; j++)
		{
			sum = nums[i][j] + nums[i + 1][j] + nums[i + 2][j] + nums[i + 3][j];
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	// [][]
	// [][]
	for (int i = 0; i <= N - 2; i++)
	{
		for (int j = 0; j <= M - 2; j++)
		{
			sum = nums[i][j] + nums[i + 1][j] + nums[i][j + 1] + nums[i + 1][j + 1];
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	// [][][]
	// [][][]
	for (int i = 0; i <= N - 2; i++)
	{
		for (int j = 0; j <= M - 3; j++)
		{
			// [1][2][3]
			// [4][5][6]
			short num1 = nums[i][j];
			short num2 = nums[i][j + 1];
			short num3 = nums[i][j + 2];
			short num4 = nums[i + 1][j];
			short num5 = nums[i + 1][j + 1];
			short num6 = nums[i + 1][j + 2];

			//    [2]
			// [4][5][6]
			sum = num2 + num4 + num5 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}


			// [1][2][3]
			//    [5]
			sum = num1 + num2 + num3 + num5;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			//    [2][3]
			// [4][5]
			sum = num2 + num3 + num4 + num5;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1][2]
			//    [5][6]
			sum = num1 + num2 + num5 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			//       [3]
			// [4][5][6]
			sum = num3 + num4 + num5 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1][2][3]
			// [4]
			sum = num1 + num2 + num3 + num4;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1][2][3]
			//       [6]
			sum = num1 + num2 + num3 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1]
			// [4][5][6]
			sum = num1 + num4 + num5 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	// [][]
	// [][]
	// [][]
	for (int i = 0; i <= N - 3; i++)
	{
		for (int j = 0; j <= M - 2; j++)
		{
			// [1][2]
			// [3][4]
			// [5][6]
			short num1 = nums[i][j];
			short num2 = nums[i][j + 1];
			short num3 = nums[i + 1][j];
			short num4 = nums[i + 1][j + 1];
			short num5 = nums[i + 2][j];
			short num6 = nums[i + 2][j + 1];

			// [1]
			// [3][4]
			// [5]
			sum = num1 + num3 + num4 + num5;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			//    [2]
			// [3][4]
			//    [6]
			sum = num2 + num3 + num4 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1]
			// [3][4]
			//    [6]
			sum = num1 + num3 + num4 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			//    [2]
			// [3][4]
			// [5]
			sum = num2 + num3 + num4 + num5;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1]
			// [3]
			// [5][6]
			sum = num1 + num3 + num5 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1][2]
			//    [4]
			//    [6]
			sum = num1 + num2 + num4 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			//    [2]
			//    [4]
			// [5][6]
			sum = num2 + num4 + num5 + num6;
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			// [1][2]
			// [3]
			// [5]
			sum = num1 + num2 + num3 + num5;
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	std::cout << maxSum;
}
