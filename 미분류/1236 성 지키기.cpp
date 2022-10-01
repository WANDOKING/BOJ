#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    const int MAX = 50;

    char castle[MAX][MAX];
    bool bHasGuardN[MAX];
    bool bHasGuardM[MAX];

    memset(bHasGuardN, false, sizeof(bool) * MAX);
    memset(bHasGuardM, false, sizeof(bool) * MAX);

    int N;
    int M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> castle[i][j];
            
            if (castle[i][j] == 'X')
            {
                bHasGuardN[i] = true;
                bHasGuardM[j] = true;
            }
        }
    }


    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (bHasGuardN[i] == true)
        {
            continue;
        }        


        bool bAddGuard = false;
        for (int j = 0; j < M; j++)
        {
            if (bHasGuardM[j] == true)
            {
                continue;
            }

            result++;
            bHasGuardN[i] = true;
            bHasGuardM[j] = true;
            bAddGuard = true;
            break;
        }

        if (bAddGuard == false)
        {
            result++;
            bHasGuardN[i] = true;
            bHasGuardM[M - 1] = true;
        }
    }

    for (int i = 0; i < M; i++)
    {
        if (bHasGuardM[i] == false)
        {
            result++;
        }
    }

    cout << result;
}
