#include <iostream>
#include <vector>

#define MAX_N 50
#define MAX_M 50

int g_parents[MAX_N];

int GetParentRecursive(int n)
{
    if (n == g_parents[n])
    {
        return n;
    }

    g_parents[n] = GetParentRecursive(g_parents[n]);
    return g_parents[n];
}

void Union(int a, int b)
{
    int parentA = GetParentRecursive(a);
    int parentB = GetParentRecursive(b);

    int min = std::min(parentA, parentB);

    g_parents[parentA] = min;
    g_parents[parentB] = min;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        g_parents[i] = i;
    }

    std::vector<std::vector<int>> parties(M);

    int countPeopleKnowTruth;
    std::cin >> countPeopleKnowTruth;

    // 진실을 아는 사람들끼리 합집합 구성
    for (int i = 0; i < countPeopleKnowTruth; ++i)
    {
        int num;
        std::cin >> num;

        Union(0, num);
    }

    for (int i = 0; i < M; ++i)
    {
        int countPeople;
        std::cin >> countPeople;

        parties[i].reserve(countPeople);

        int prevNum;
        std::cin >> prevNum;

        parties[i].push_back(prevNum);
        for (int j = 1; j < countPeople; ++j)
        {
            int num;
            std::cin >> num;

            parties[i].push_back(num);

            Union(prevNum, num);
            prevNum = num;
        }
    }

    int result = 0;
    for (const auto& party : parties)
    {
        bool bCanTellLie = true;
        for (const auto& person : party)
        {
            if (GetParentRecursive(person) == 0)
            {
                bCanTellLie = false;
                break;
            }
        }

        if (bCanTellLie)
        {
            result++;
        }
    }

    std::cout << result;
}
