#include <iostream>

char g_board[5][15];

int main(void)
{
	for (int i = 0; i < 5; ++i)
	{
		std::cin >> g_board[i];
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (g_board[j][i] != 0)
			{
				std::cout << g_board[j][i];
			}
		}
	}
}
