#include <iostream>
#include <climits>

int main(void)
{
    int stairsCount;
    scanf("%d", &stairsCount);

    int scores[stairsCount + 1];
    int maxScoreSum[stairsCount + 1]; // DP grid
    bool bCanJump1Step[stairsCount + 1]; // 그 칸에서 1칸 점프를 할 수 있는지

    for (int i = 1; i <= stairsCount; i++)
    {
        scanf("%d", &scores[i]);
    }

    // DP grid 초기화
    maxScoreSum[0] = 0;
    bCanJump1Step[0] = true;
    maxScoreSum[1] = scores[1];
    bCanJump1Step[1] = true;
    maxScoreSum[2] = scores[1] + scores[2];
    bCanJump1Step[2] = false;

    for (int i = 3; i <= stairsCount; i++)
    {
        // 전 칸에서 1칸 뛰는 경우
        int score1Step;
        if (bCanJump1Step[i - 1] == true)
        {
            score1Step = maxScoreSum[i - 1] + scores[i];
        }
        else
        {
            // i-3에서 2칸 뛰고, i-1에서 1칸 뛴 것
            score1Step = maxScoreSum[i - 3] + scores[i - 1] + scores[i];
        }

        // 전전 칸에서 2칸 뛰는 경우
        int score2Step = maxScoreSum[i - 2] + scores[i];

        if (score1Step > score2Step)
        {
            maxScoreSum[i] = score1Step;
            bCanJump1Step[i] = false;
        }
        else
        {
            maxScoreSum[i] = score2Step;
            bCanJump1Step[i] = true;
        }
    }

    printf("%d", maxScoreSum[stairsCount]);
}
