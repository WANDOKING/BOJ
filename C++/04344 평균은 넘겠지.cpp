#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int C;
    scanf("%d", &C);
    
    for (int i = 0; i < C; i++) {
        int N;
        scanf("%d", &N);
        
        int scores[N];
        int sumScores = 0;
        for (int j = 0; j < N; j++) {
            scanf("%d", &scores[j]);
            sumScores += scores[j];
        }
        
        double average = (double)sumScores / N;
        
        int scoreAverageUpCount = 0;
        for (int j = 0; j < N; j++) {
            if (scores[j] > average) {
                scoreAverageUpCount++;
            }
        }
        
        printf("%.3lf%%\n", (double) scoreAverageUpCount / N * 100);
    }

    return 0;
}
