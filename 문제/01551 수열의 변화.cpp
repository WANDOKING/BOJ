#include <iostream>
#include <vector>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int K;

    std::cin >> N >> K;

    std::vector<int> resultArray;
    resultArray.reserve(N);

    int firstNum;
    std::cin >> firstNum;

    resultArray.push_back(firstNum);

    for (int i = 1; i < N; ++i)
    {
        char ignoreDelimiter;
        int inputNum;

        std::cin >> ignoreDelimiter >> inputNum;

        resultArray.push_back(inputNum);
    }

    for (int i = 0; i < K; ++i)
    {
        int currentArrayLength = N - i - 1;

        for (int j = 0; j < currentArrayLength; ++j)
        {
            resultArray[j] = resultArray[j + 1] - resultArray[j];
        }
    }

    // 출력

    std::cout << resultArray[0];
    for (int i = 1; i < N - K; ++i)
    {
        std::cout << ',' << resultArray[i];
    }
}
