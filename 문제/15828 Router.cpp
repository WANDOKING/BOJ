#include <iostream>
#include <queue>

int main(void)
{
    int N;

    std::cin >> N;

    std::queue<int> packets;

    while (true)
    {
        int input;
        std::cin >> input;

        if (input == -1)
        {
            break;
        }
        else if (input == 0)
        {
            packets.pop();
        }
        else if (packets.size() < N)
        {
            packets.push(input);
        }
    }

    if (packets.empty() == true)
    {
        std::cout << "empty";
    }
    else
    {
        while (packets.empty() == false)
        {
            std::cout << packets.front() << ' ';
            packets.pop();
        }
    }
}
