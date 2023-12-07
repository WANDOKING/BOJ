#include <iostream>

int main(void)
{
    int N;

    std::cin >> N;

    int result = 0;

    // 제곱수의 개수를 찾아야 함
    for (int i = 1; i <= N; ++i)
    {
        if (i * i > N)
        {
            break;
        }

        result++;
    }

    std::cout << result;
}
