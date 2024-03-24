#include <iostream>
#include <stack>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    int currentTurn = 1; // 현재 들어가야하는 학생 번호
    std::stack<int> temporarySpace; // 임시로 줄 서는 공간

    for (int i = 0; i < N; ++i)
    {
        int studentNumber;

        std::cin >> studentNumber;

        if (studentNumber != currentTurn)
        {
            temporarySpace.push(studentNumber);
        }
        else
        {
            currentTurn++;

            while (temporarySpace.empty() == false)
            {
                if (temporarySpace.top() != currentTurn)
                {
                    break;
                }

                temporarySpace.pop();

                currentTurn++;
            }
        }
    }

    if (temporarySpace.empty())
    {
        std::cout << "Nice";
    }
    else
    {
        std::cout << "Sad";
    }
}
