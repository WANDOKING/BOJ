#include <iostream>

using namespace std;

int main()
{
    int N; // 정수의 개수
    int X; // X보다 작은 수들을 출력할 것
    
    scanf("%d %d", &N, &X);
    
    for (int i = 0; i < N; i++) {
        int num;
        
        scanf("%d", &num);
        if (num < X) {
            printf("%d ", num);
        }
    }

    return 0;
}
