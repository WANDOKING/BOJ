#include <iostream>
#include <stack>

#define MAX 100
#define PAIR(F, S) ((F) * 1000 + (S))

int GetCountArea(const char paint[][MAX], const int N, const bool bColorWeakness)
{
    bool visited[MAX][MAX] = { 0, };

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == true)
            {
                continue;
            }

            result++;

            char color = paint[i][j];

            std::stack<int> s;
            s.push(PAIR(i, j));

            while (s.empty() == false)
            {
                int x = s.top() % 1000;
                int y = s.top() / 1000;
                s.pop();

                if (x < 0 || x >= N)
                {
                    continue;
                }

                if (y < 0 || y >= N)
                {
                    continue;
                }

                if (bColorWeakness == true && (color == 'G' || color == 'R'))
                {
                    if (paint[y][x] == 'B')
                    {
                        continue;
                    }
                }
                else
                {
                    if (paint[y][x] != color)
                    {
                        continue;
                    }
                }

                if (visited[y][x] == true)
                {
                    continue;
                }

                visited[y][x] = true;

                s.push(PAIR(y, x - 1));
                s.push(PAIR(y, x + 1));
                s.push(PAIR(y - 1, x));
                s.push(PAIR(y + 1, x));
            }
        }
    }

    return result;
}

int main(void)
{
    char paint[MAX][MAX];

    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> paint[i][j];
        }
    }

    int countNoColorWeakness = GetCountArea(paint, N, false);
    int countColorWeakness = GetCountArea(paint, N, true);

    std::cout << countNoColorWeakness << ' ' << countColorWeakness;
}
