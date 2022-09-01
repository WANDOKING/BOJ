#include <iostream>

int nums[9] = { 0, };

void DfsRecursive(int depth, int N, int M)
{
    if (depth == M)
    {
        for (int i = nums[depth - 1] + 1; i <= N; i++)
        {
            nums[depth] = i;
            for (int j = 1; j <= M; j++)
            {
                printf("%d ", nums[j]);
            }
            printf("\n");
        }
    }
    
    for (int i = nums[depth - 1] + 1; i <= N; i++)
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
    
    DfsRecursive(1, N, M);

    return 0;
}
