#include <iostream>

#define MAX 1000

int g_nums[MAX];

int main(void)
{
    int A;
    int B;

    std::cin >> A >> B;

    int temp = 1;
    int tempCount = 1;
    for (int i = 0; i < B; ++i)
    {
        g_nums[i] = temp;
        tempCount--;

        if (tempCount == 0)
        {
            temp++;
            tempCount = temp;
        }
    }

    int result = 0;
    for (int i = A - 1; i < B; ++i)
    {
        result += g_nums[i];
    }

    std::cout << result;
}
