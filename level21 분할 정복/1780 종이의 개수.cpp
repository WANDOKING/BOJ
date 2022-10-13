#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int g_numCounts[3] = { 0, 0, 0 }; // -1, 0, 1

bool IsPaperRecursive(const vector<vector<int>>& paper, int paperI, int paperJ, int length, int num)
{
    if (length == 1)
    {
        return paper[paperI][paperJ] == num;
    }

    int newLength = length / 3;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (IsPaperRecursive(paper, paperI + newLength * i, paperJ + newLength * j, newLength, num) == false)
            {
                return false;
            }
        }
    }

    return true;
}

void SolveRecursive(const vector<vector<int>>& paper, int paperI, int paperJ, int length)
{
    assert(length >= 1);

    if (IsPaperRecursive(paper, paperI, paperJ, length, -1) == true)
    {
        g_numCounts[0]++;
        return;
    }
    else if (IsPaperRecursive(paper, paperI, paperJ, length, 0) == true)
    {
        g_numCounts[1]++;
        return;
    }
    else if (IsPaperRecursive(paper, paperI, paperJ, length, 1) == true)
    {
        g_numCounts[2]++;
        return;
    }

    int newLength = length / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            SolveRecursive(paper, paperI + newLength * i, paperJ + newLength * j, newLength);
        }
    }
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    const int MAX = 2187;
    vector<vector<int>> paper;

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        paper.push_back(vector<int>());
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;

            paper[i].push_back(input);
        }
    }

    SolveRecursive(paper, 0, 0, N);

    cout << g_numCounts[0] << '\n';
    cout << g_numCounts[1] << '\n';
    cout << g_numCounts[2] << '\n';
}
