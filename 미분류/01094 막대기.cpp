#include <iostream>

int main(void)
{
	int X;

	std::cin >> X;

	int result = 0;
	while (X > 0)
	{
		int stickLength = 64;
		while (stickLength > X)
		{
			stickLength /= 2;
		}

		X -= stickLength;
		++result;
	}

	std::cout << result;
}
