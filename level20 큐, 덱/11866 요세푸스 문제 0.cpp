#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N;
    int K;
    
    scanf("%d %d", &N, &K);
    
    queue<int> nums;
    vector<int> result;
    result.reserve(N);
    
    for (int i = 1; i <= N; i++)
    {
        nums.push(i);
    }
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < K - 1; j++)
        {
            nums.push(nums.front());
            nums.pop();
        }
        
        result.push_back(nums.front());
        nums.pop();
    }
    
    printf("<%d", result[0]);
    for (int i = 1; i < result.size(); i++)
    {
        printf(", %d", result[i]);
    }
    printf(">");

    return 0;
}
