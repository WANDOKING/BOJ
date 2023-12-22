#include <iostream>

int main(void)
{
    std::string board;

    std::cin >> board;

    for (int i = 0; i < board.length();)
    {
        if (board[i] == '.')
        {
            i += 1;
            continue;
        }
        else if (board[i] == 'X' && board[i + 1] == 'X' && board[i + 2] == 'X' && board[i + 3] == 'X')
        {
            board[i] = 'A';
            board[i + 1] = 'A';
            board[i + 2] = 'A';
            board[i + 3] = 'A';

            i += 4;
        }
        else if (board[i] == 'X' && board[i + 1] == 'X')
        {
            board[i] = 'B';
            board[i + 1] = 'B';

            i += 2;
        }
        else
        {
            std::cout << -1;
            return 0;
        }
    }

    std::cout << board;
}
