#include <iostream>
#include <cmath>

int main(void)
{
    int N;
    scanf("%d", &N);

    int costs[N][3];   // input
    int minSums[N][3]; // dp를 위한 grid. 이 셀을 선택하는 경로의 최소합
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &costs[i][j]);
        }
    }

    // 첫 줄 초기화
    minSums[0][0] = costs[0][0];
    minSums[0][1] = costs[0][1];
    minSums[0][2] = costs[0][2];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // cell[i][j] = costs[i][j] + min(cell[i - 1][다른색1], cell[i - 1][다른색2])
            if (minSums[i - 1][(j + 1) % 3] < minSums[i - 1][(j + 2) % 3])
            {
                minSums[i][j] = minSums[i - 1][(j + 1) % 3] + costs[i][j];
            }
            else
            {
                minSums[i][j] = minSums[i - 1][(j + 2) % 3] + costs[i][j];
            }
        }
    }

    int result = std::min(std::min(minSums[N - 1][0], minSums[N - 1][1]), minSums[N - 1][2]);

    printf("%d", result);
}
