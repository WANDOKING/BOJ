#include <iostream>
#include <string>
#include <algorithm>

#define MAX_SUBJECT_NAME_LENGTH 50

int main(void)
{
    int N;
    int B;

    std::cin >> N >> B;

    std::string answer = "";

    while (N > 0)
    {
        int temp = N % B;
        N /= B;

        char ch;

        if (temp >= 0 && temp <= 9)
        {
            ch = '0' + temp;
        }
        else
        {
            ch = 'A' + temp - 10;
        }

        answer += ch;
    }

    std::reverse(answer.begin(), answer.end());

    std::cout << answer;
}
