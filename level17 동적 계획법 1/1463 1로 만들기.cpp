#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    const int MAX = 1000000;
    uint16_t memo[MAX + 1];
    int N;
    cin >> N;

    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;

    for (int i = 4; i <= N; i++)
    {
        uint16_t min = INT16_MAX;

        if (i % 3 == 0 && memo[i / 3] < min)
        {
            min = memo[i / 3];
        }
        if (i % 2 == 0 && memo[i / 2] < min)
        {
            min = memo[i / 2];
        }
        if (memo[i - 1] < min)
        {
            min = memo[i - 1];
        }

        memo[i] = min + 1;
    }

    cout << memo[N];
}
