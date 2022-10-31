#include <iostream>
#include <cassert>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T;

    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        int M;
        int N;
        int x;
        int y;

        std::cin >> M >> N >> x >> y;

        int num1 = M;
        int num2 = N;
        while (num1 % num2 != 0)
        {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        int gcd = num2;
        long long lcm = (M * N) / gcd;

        int tempY = (x % N) == 0 ? N : x % N;
        long long result = -1;
        long long k = x;
        while (k <= lcm)
        {
            if (tempY == y)
            {
                result = k;
                break;
            }

            tempY = (tempY + M) % N == 0 ? N : (tempY + M) % N;

            k += M;
        }

        std::cout << result << '\n';
    }
}
