#include <iostream>
#include <vector>

#define MAX_N 200

int g_parent[MAX_N + 1];

int GetParentRecursive(int n)
{
    if (g_parent[n] == n)
    {
        return n;
    }

    g_parent[n] = GetParentRecursive(g_parent[n]);
    return g_parent[n];
}

void Union(int a, int b)
{
    int parentA = GetParentRecursive(a);
    int parentB = GetParentRecursive(b);

    int min = std::min(parentA, parentB);
    g_parent[parentA] = min;
    g_parent[parentB] = min;
}

bool Find(int a, int b)
{
    int parentA = GetParentRecursive(a);
    int parentB = GetParentRecursive(b);

    return parentA == parentB;
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
        g_parent[i] = i;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int input;
            std::cin >> input;

            if (input == 1)
            {
                Union(i, j);
            }
        }
    }

    std::vector<int> travelPlan;
    travelPlan.reserve(M);

    for (int i = 0; i < M; ++i)
    {
        int input;
        std::cin >> input;
        travelPlan.push_back(input);
    }

    int prevNum = travelPlan[0];
    
    bool bResult = true;
    for (int i = 1; i < M; ++i)
    {
        if (Find(prevNum, travelPlan[i]) == false)
        {
            bResult = false;
        }

        prevNum = travelPlan[i];
    }

    if (bResult == true)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}
