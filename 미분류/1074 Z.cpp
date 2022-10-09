#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int SolveRecurisve(int length, int squareX, int squareY, int targetX, int targetY, int sum = 0)
{
    if (length == 1)
    {
        return sum;
    }

    bool bIsInLeftSide = targetX >= squareX && targetX < squareX + length / 2;
    bool bIsInUpSide = targetY >= squareY && targetY < squareY + length / 2;

    bool bIsUpLeftSide = bIsInLeftSide && bIsInUpSide;
    bool bIsUpRightSide = !bIsInLeftSide && bIsInUpSide;
    bool bIsDownLeftSide = bIsInLeftSide && !bIsInUpSide;
    bool bIsDownRightSide = !bIsInLeftSide && !bIsInUpSide;

    if (bIsUpLeftSide)
    {
        return SolveRecurisve(length / 2, squareX, squareY, targetX, targetY, sum);
    }
    else if (bIsUpRightSide)
    {
        sum += (length / 2) * (length / 2);
        return SolveRecurisve(length / 2, squareX + length / 2, squareY, targetX, targetY, sum);
    }
    else if (bIsDownLeftSide)
    {
        sum += (length / 2) * (length / 2) * 2;
        return SolveRecurisve(length / 2, squareX, squareY + length / 2, targetX, targetY, sum);
    }
    else if (bIsDownRightSide)
    {
        sum += (length / 2) * (length / 2) * 3;
        return SolveRecurisve(length / 2, squareX + length / 2, squareY + length / 2, targetX, targetY, sum);
    }
    else
    {
        assert(false);
    }
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    int r;
    int c;

    cin >> N >> r >> c;

    cout << SolveRecurisve((int)pow(2, N), 0, 0, c, r);
}
