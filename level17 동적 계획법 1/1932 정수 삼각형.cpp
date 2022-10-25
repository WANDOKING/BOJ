#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int triangle[n][n];
    int sums[n][n]; // grid : 해당 값까지의 경로들 중 합이 최대인 경로의 합

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    sums[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                sums[i][j] = triangle[i][j] + sums[i - 1][j];
            }
            else if (j == i)
            {
                sums[i][j] = triangle[i][j] + sums[i - 1][j - 1];
            }
            else
            {
                int maxValue = max(sums[i - 1][j - 1], sums[i - 1][j]);
                sums[i][j] = triangle[i][j] + maxValue;
            }
        }
    }

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (sums[n - 1][i] > max)
        {
            max = sums[n - 1][i];
        }
    }

    cout << max;
}
