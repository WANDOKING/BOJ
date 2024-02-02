#include <iostream>
#include <climits>

#define MAX 1000
#define GRADE_COUNT 5

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    short table[MAX][MAX];

    short countStudent;

    std::cin >> countStudent;

    for (int i = 0; i < countStudent; i++)
    {
        for (int j = 0; j < GRADE_COUNT; j++)
        {
            std::cin >> table[i][j];
        }
    }

    int classHead = -1;
    int maxKnownStudent = -1;

    for (int student = 0; student < countStudent; student++)
    {
        bool bKnowStudent[MAX] = { 0, };
        int countKnownStudent = 0;

        for (int i = 0; i < GRADE_COUNT; i++)
        {
            for (int j = 0; j < countStudent; j++)
            {
                if (j == student)
                {
                    continue;
                }

                if (table[j][i] == table[student][i] && bKnowStudent[j] == false)
                {
                    bKnowStudent[j] = true;
                    countKnownStudent++;
                }
            }
        }

        if (countKnownStudent > maxKnownStudent)
        {
            classHead = student;
            maxKnownStudent = countKnownStudent;
        }
    }

    std::cout << classHead + 1;

    return 0;
}
