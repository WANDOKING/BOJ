#include <iostream>

int main(void)
{
    int N;
    int m;
    int M;
    int T;
    int R;

    std::cin >> N >> m >> M >> T >> R;

    int result = 0;
    int exerciseCount = 0;
    int currentPulse = m;

    if (m + T > M)
    {
        std::cout << -1;
        return 0;
    }

    while (exerciseCount < N)
    {
        if (currentPulse + T <= M)
        {
            exerciseCount++;
            currentPulse += T;
        }
        else
        {
            currentPulse = currentPulse - R > m ? currentPulse - R : m;
        }

        result++;
    }

    std::cout << result;
}
