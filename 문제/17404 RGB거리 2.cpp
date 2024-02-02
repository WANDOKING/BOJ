#include <iostream>
#include <climits>

#define MAX_N 1000

int main(void)
{
    int costs[MAX_N][3];
    int dpCosts[3][MAX_N][3];

    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> costs[i][j];
        }
    }

    // dp를 총 세 번 구한다.
    // 첫 번째를 빨강으로 고정하고 한 번
    // 첫 번째를 초록으로 고정하고 한 번
    // 첫 번째를 파랑으로 고정하고 한 번
    // 최종적으로 구해진 6개의 결과들 중 최솟값이 해답
    int result = INT_MAX;
    for (int k = 0; k < 3; ++k)
    {
        // dp 첫 번째 줄 처리
        for (int i = 0; i < 3; ++i)
        {
            if (i == k)
            {
                dpCosts[k][0][i] = costs[0][i];
            }
            else
            {
                dpCosts[k][0][i] = INT_MAX;
            }
        }

        // dp
        for (int i = 1; i < N - 1; ++i)
        {
            
            dpCosts[k][i][0] = std::min(dpCosts[k][i - 1][1], dpCosts[k][i - 1][2]);
            dpCosts[k][i][0] = dpCosts[k][i][0] != INT_MAX ? dpCosts[k][i][0] + costs[i][0] : INT_MAX;
            
            dpCosts[k][i][1] = std::min(dpCosts[k][i - 1][0], dpCosts[k][i - 1][2]);
            dpCosts[k][i][1] = dpCosts[k][i][1] != INT_MAX ? dpCosts[k][i][1] + costs[i][1] : INT_MAX;

            dpCosts[k][i][2] = std::min(dpCosts[k][i - 1][0], dpCosts[k][i - 1][1]);
            dpCosts[k][i][2] = dpCosts[k][i][2] != INT_MAX ? dpCosts[k][i][2] + costs[i][2] : INT_MAX;
        }

        // dp 마지막 줄 처리
        for (int i = 0; i < 3; ++i)
        {
            if (i == k)
            {
                dpCosts[k][N - 1][i] = INT_MAX;
            }
            else
            {
                dpCosts[k][N - 1][i] = costs[N - 1][i];
                dpCosts[k][N - 1][i] += std::min(dpCosts[k][N - 2][(i + 1) % 3], dpCosts[k][N - 2][(i + 2) % 3]);
                result = std::min(result, dpCosts[k][N - 1][i]); // 최솟값
            }
        }
    }

    std::cout << result;
}
