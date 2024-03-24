#include <iostream>
#include <climits>

#define MAX 100
#define SIZE_PAPER 10

int main(void)
{
    bool board[MAX][MAX] = { 0, };

    int countPaper;
    scanf("%d", &countPaper);

    int result = 0;
    for (int i = 0; i < countPaper; i++)
    {
        int x;
        int y;
        scanf("%d %d", &x, &y);

        for (int i = x; i < x + SIZE_PAPER; i++)
        {
            for (int j = y; j < y + SIZE_PAPER; j++)
            {
                if (board[i][j] == false)
                {
                    board[i][j] = true;
                    result++;
                }
            }
        }
    }

    printf("%d", result);
}
