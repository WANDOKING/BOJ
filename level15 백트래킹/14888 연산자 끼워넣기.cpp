#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int g_max = INT_MIN;
int g_min = INT_MAX;

void Dfs(int nums[], char calculateOps[], char allOps[], bool bUsed[], int N, int depth = 0)
{
    if (depth == N - 1)
    {
        int result = nums[0];
        for (int i = 0; i < N - 1; i++)
        {
            switch (calculateOps[i])
            {
            case '+':
                result += nums[i + 1];
                break;
            case '-':
                result -= nums[i + 1];
                break;
            case '*':
                result *= nums[i + 1];
                break;
            case '/':
                result /= nums[i + 1];
                break;
            default:
                break;
            }
        }

        if (result > g_max)
        {
            g_max = result;
        }

        if (result < g_min)
        {
            g_min = result;
        }

        return;
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (bUsed[i] == true)
        {
            continue;
        }

        bUsed[i] = true;
        calculateOps[depth] = allOps[i];
        Dfs(nums, calculateOps, allOps, bUsed, N, depth + 1);
        bUsed[i] = false;
    }
}

int main(void)
{
    int N;
    cin >> N;

    int nums[N];
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    // + - * / 의 개수대로 배열을 저장하여 visited를 체크하는식으로 dfs
    int plusCount;
    int minusCount;
    int multiplyCount;
    int divideCount;
    cin >> plusCount >> minusCount >> multiplyCount >> divideCount;

    char operators[N - 1];
    int operatorsI = 0;
    for (int i = 0; i < plusCount; i++)
    {
        operators[operatorsI] = '+';
        operatorsI++;
    }
    for (int i = 0; i < minusCount; i++)
    {
        operators[operatorsI] = '-';
        operatorsI++;
    }
    for (int i = 0; i < multiplyCount; i++)
    {
        operators[operatorsI] = '*';
        operatorsI++;
    }
    for (int i = 0; i < divideCount; i++)
    {
        operators[operatorsI] = '/';
        operatorsI++;
    }

    bool bUsed[N - 1]; // visited
    memset(bUsed, false, sizeof(bUsed) / sizeof(bool));
    char calculateOps[N - 1];

    Dfs(nums, calculateOps, operators, bUsed, N);

    cout << g_max << '\n';
    cout << g_min << '\n';
}
