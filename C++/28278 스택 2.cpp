#include <iostream>

#define MAX_N 1'000'000

int g_stack[MAX_N];
int g_stackSize = 0;

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
        case 1: // Push
        {
            int x;
            std::cin >> x;

            g_stack[g_stackSize++] = x;
        }
        break;
        case 2: // Pop
        {
            if (g_stackSize == 0)
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << g_stack[--g_stackSize] << '\n';
            }
        }
        break;
        case 3:
        {
            std::cout << g_stackSize << '\n';
        }
        break;
        case 4:
        {
            if (g_stackSize == 0)
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
        }
        break;
        case 5:
        {
            if (g_stackSize == 0)
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << g_stack[g_stackSize - 1] << '\n';
            }
        }
        break;
        }
    }
}
