#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int N;
    int K;
    
    scanf("%d %d", &N, &K);
    
    stack<int> coins;
    for (int i = 0; i < N; i++)
    {
        int coin;
        scanf("%d", &coin);
        coins.push(coin);
    }
    
    int count = 0;
    while (true)
    {
        int coin = coins.top();
        coins.pop();
        count += K / coin;
        K = K % coin;
        
        if (K == 0)
        {
            break;
        }
    }
    
    printf("%d", count);

    return 0;
}
