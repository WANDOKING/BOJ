#include <iostream>

int nums[8];


void DfsRecursive(int depth, int N, int M)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");
        
        return;
    }
    
    int prevNum;
    if (depth == 0)
    {
        prevNum = 1;
    }
    else
    {
        prevNum = nums[depth - 1];
    }
    
    for (int i = prevNum; i <= N; i++)
    {
        nums[depth] = i;
        DfsRecursive(depth + 1, N, M);
    }
}

int main()
{
   int N;
   int M;
   
   scanf("%d %d", &N, &M);
   
   DfsRecursive(0, N, M);

    return 0;
}
