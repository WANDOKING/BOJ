#include <iostream>

int nums[8];
bool visited[9] = { false,  };

void DfsRecursive(int depth, int N, int M) {
    // base condition
    if (depth == M) {
        for (int i = 1; i <= N; i++) {
            if (visited[i] == false) {
                nums[M - 1] = i;
                
                for (int j = 0; j < M; j++) {
                    printf("%d ", nums[j]);
                }
                printf("\n");
            }
        }
        
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            nums[depth - 1] = i;
            DfsRecursive(depth + 1, N, M);
            visited[i] = false;
        }
    }
}

int main(void)
{
    int N;
    int M;
    
    scanf("%d %d", &N, &M);
    
    DfsRecursive(1, N, M);
}
