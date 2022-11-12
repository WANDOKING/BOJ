#include <iostream>
#include <vector>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int K;

    std::cin >> N >> K;

    std::vector<std::vector<int>> dp;
    dp.reserve(N);

    dp.push_back(std::vector<int>());
    dp[0].reserve(K + 1);
    for (int i = 0; i <= K; i++)
    {
        dp[0].push_back(0);
    }

    for (int i = 1; i <= N; i++)
    {
        dp.push_back(std::vector<int>());
        dp[i].reserve(K + 1);

        int W;
        int V;
        std::cin >> W >> V;

        for (int j = 0; j <= K; j++)
        {
            if (j - W < 0 || dp[i - 1][j - W] + V < dp[i - 1][j])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - W] + V;
            }
        }
    }

    std::cout << dp[N][K];
}
