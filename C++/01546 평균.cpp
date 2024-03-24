#include <iostream>

using namespace std;

int main()
{
    int numSubject;
    
    scanf("%d", &numSubject);
    
    int sumScore = 0;
    int maxScore = -1;
    for (int i = 0; i < numSubject; i++) {
        int score;
        
        scanf("%d", &score);
        
        sumScore += score;
        
        if (maxScore < score) {
            maxScore = score;
        }
    }
    
    // 식을 정리해서 한 번에 계산
    double result = (double)(sumScore * 100) / (numSubject * maxScore);
    printf("%lf", result);

    return 0;
}
