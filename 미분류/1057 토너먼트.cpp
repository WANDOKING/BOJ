#include <iostream>

int main(void)
{
	int N;
	int jisu;
	int hansu;

	std::cin >> N >> jisu >> hansu;

	int result = 1;

	while (true)
	{
		int tempJisu = (jisu - 1) / 2 + 1;
		int tempHansu = (hansu - 1) / 2 + 1;

		if (tempJisu == tempHansu)
		{
			break;
		}

		jisu = tempJisu;
		hansu = tempHansu;

		result++;
	}

	std::cout << result;

	return 0;
}
