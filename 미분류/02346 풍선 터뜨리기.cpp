#include <iostream>
#include <deque>

int main(void)
{
    int N;

    std::cin >> N;

    std::deque<std::pair<int, int>> balloons;

    for (int i = 1; i <= N; ++i)
    {
        int num;

        std::cin >> num;

        balloons.push_back(std::make_pair(num, i));
    }

    int moveNumber = balloons.front().first;

    std::cout << balloons.front().second << ' ';

    balloons.pop_front();

    for (int i = 0; i < N - 1; ++i)
    {
        if (moveNumber > 0)
        {
            for (int j = 0; j < moveNumber - 1; ++j)
            {
                std::pair<int, int> temp = balloons.front();

                balloons.pop_front();

                balloons.push_back(temp);
            }

            moveNumber = balloons.front().first;
            std::cout << balloons.front().second << ' ';
            balloons.pop_front();
        }
        else
        {
            for (int j = 0; j < -1 * moveNumber - 1; ++j)
            {
                std::pair<int, int> temp = balloons.back();

                balloons.pop_back();

                balloons.push_front(temp);
            }

            moveNumber = balloons.back().first;
            std::cout << balloons.back().second << ' ';
            balloons.pop_back();
        }
    }
}
