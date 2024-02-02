#include <iostream>
#include <climits>

int main(void)
{
    int N;

    std::cin >> N;

    int minX = INT_MAX;
    int maxX = INT_MIN;
    int minY = INT_MAX;
    int maxY = INT_MIN;

    for (int i = 0; i < N; ++i)
    {
        int x;
        int y;

        std::cin >> x >> y;

        if (minX > x)
        {
            minX = x;
        }

        if (maxX < x)
        {
            maxX = x;
        }

        if (minY > y)
        {
            minY = y;
        }

        if (maxY < y)
        {
            maxY = y;
        }
    }

    if (N == 1)
    {
        std::cout << 0;
    }
    else
    {
        int width = maxX - minX;
        int height = maxY - minY;

        std::cout << width * height;
    }
}
