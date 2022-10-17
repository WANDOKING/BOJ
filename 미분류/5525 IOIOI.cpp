#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    const int MAX = 1000000;
    
    int dp[MAX * 2 + 2];
    char input[MAX * 2 + 2];
    
    int N;
    int M;
    
    cin >> N >> M;
    cin >> input;
    
    bool bIsCounting = false;
    int counting = -1;
    int i = 0;
    while (i < M - 2)
    {
        if (bIsCounting == false && input[i] == 'I')
        {
            bIsCounting = true;
            dp[i] = 0;
            counting = 0;
        }
        
        if (bIsCounting && input[i] == 'I')
        {
            if (input[i + 1] == 'O' && input[i + 2] == 'I')
            {
                dp[i + 1] = -1;
                dp[i + 2] = ++counting;
                i++;
            }
            else
            {
                bIsCounting = false;
                counting = -1;
            }
        }
        else if (bIsCounting && input[i] == 'O')
        {
            bIsCounting = false;
            dp[i] = -1;
        }
        else if (bIsCounting == false)
        {
            dp[i] = -1;
        }
        
        i++;
    }
    
    int result = 0;
    for (int i = 0; i < M; i++)
    {
        if (dp[i] >= N)
        {
            result++;
        }
    }
    
    cout << result;
}
