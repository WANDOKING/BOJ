#include <iostream>
#include <string>

int main(void)
{
    int N;

    std::cin >> N;

    while (true)
    {
        std::string strNum = std::to_string(N);

        // 금민수 : 4와 7로만 이루어진 수
        bool bIsGuemMinSu = true;

        for (const char ch : strNum)
        {
            if (ch != '7' && ch != '4')
            {
                bIsGuemMinSu = false;
                break;
            }
        }

        if (bIsGuemMinSu)
        {
            std::cout << N;
            break;
        }

        --N;
    }
}
