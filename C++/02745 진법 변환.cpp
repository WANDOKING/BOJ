#include <iostream>
#include <string>
#include <cmath>

#define MAX_SUBJECT_NAME_LENGTH 50

int main(void)
{
    std::string N;
    int B;

    std::cin >> N >> B;

    int answer = 0;

    for (int i = 0; i < N.size(); ++i)
    {
        int number;

        if (N[N.size() - 1 - i] >= 'A' && N[N.size() - 1 - i] <= 'Z')
        {
            number = N[N.size() - 1 - i] - 'A' + 10;
        }
        else
        {
            number = N[N.size() - 1 - i] - '0';
        }

        answer += number * static_cast<int>(std::pow(B, i));
    }

    std::cout << answer;
}
