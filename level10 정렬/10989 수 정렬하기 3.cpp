#include <iostream>

int main(void)
{
    const int COUNTING_SIZE = 10001;
    int N;
    
    scanf("%d", &N);
    
    // 입력 카운팅
    int counting[COUNTING_SIZE] = {0, };
    for (int i = 0; i < N; i++) {
        int num;
        
        scanf("%d", &num);
        
        counting[num]++;
    }
    
    // 출력
    for (int i = 0; i < COUNTING_SIZE; i++) {
        for (int j = 0; j < counting[i]; j++) {
            printf("%d\n", i);
        }
    }
}
