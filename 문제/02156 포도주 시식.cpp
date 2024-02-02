#include <iostream>
#include <cmath>

int main(void)
{
    int n;
    int dp[10000];
    int wine[10000];
    int drinkarowCount[10001];

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &wine[i]);
    }

    dp[0] = 0;
    drinkarowCount[0] = 0;

    dp[1] = wine[1];
    drinkarowCount[1] = wine[1] != 0 ? 1 : 0;

    dp[2] = dp[1] + wine[2];
    drinkarowCount[2] = wine[2] != 0 ? drinkarowCount[1] + 1 : 0;

    for (int i = 3; i <= n; i++)
    {
        int drinkInarow = drinkarowCount[i - 1] < 2 ? dp[i - 1] + wine[i] : -1;
        int dontDrink = dp[i - 1];
        int drinkExceptBefore = dp[i - 2] + wine[i];
        int drinkExceptBeforBefore = dp[i - 3] + wine[i - 1] + wine[i];

        int max = std::max (drinkExceptBeforBefore, std::max(drinkInarow, std::max(dontDrink, drinkExceptBefore)));

        dp[i] = max;

        if (dontDrink == max)
        {
            drinkarowCount[i] = 0;
        }
        else if (drinkExceptBefore == max)
        {
            drinkarowCount[i] = 1;
        }
        else if (drinkInarow == max)
        {
            drinkarowCount[i] = drinkarowCount[i - 1] + 1;
        }
        else
        {
            drinkarowCount[i] = 2;
        }
    }

    printf("%d", std::max(dp[n], dp[n - 1]));
}
