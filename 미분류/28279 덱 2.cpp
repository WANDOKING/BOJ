#include <iostream>

#define MAX_N 1'000'000

int g_nums[MAX_N];
int front = 0;
int end = 0;
int size = 0;

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int operation;

        std::cin >> operation;

        switch (operation)
        {
        case 1:
        {
            int x;

            std::cin >> x;

            if (size == 0)
            {
                front = end = 0;
                g_nums[0] = x;
            }
            else
            {
                front = (MAX_N + front - 1) % MAX_N;
                g_nums[front] = x;
            }

            size++;
        }
        break;
        case 2:
        {
            int x;

            std::cin >> x;

            if (size == 0)
            {
                front = end = 0;
                g_nums[0] = x;
            }
            else
            {
                end = (end + 1) % MAX_N;
                g_nums[end] = x;
            }

            size++;
        }
        break;
        case 3:
        {
            if (size == 0)
            {
                std::cout << -1 << '\n';
                break;
            }

            std::cout << g_nums[front] << '\n';
            front = (front + 1) % MAX_N;
            size--;
        }
        break;
        case 4:
        {
            if (size == 0)
            {
                std::cout << -1 << '\n';
                break;
            }

            std::cout << g_nums[end] << '\n';
            end = (MAX_N + end - 1) % MAX_N;
            size--;
        }
        break;
        case 5:
        {
            std::cout << size << '\n';
        }
        break;
        case 6:
        {
            if (size == 0)
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        break;
        case 7:
        {
            if (size == 0)
            {
                std::cout << -1 << '\n';
                break;
            }

            std::cout << g_nums[front] << '\n';
        }
        break;
        case 8:
        {
            if (size == 0)
            {
                std::cout << -1 << '\n';
                break;
            }

            std::cout << g_nums[end] << '\n';
        }
        break;
        }
    }
}
