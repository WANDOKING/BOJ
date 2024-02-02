#include <iostream>
#include <cstring>

int g_board[9][9];
int g_emptyCount = 0;

bool g_bIsInside[3][3][9];
bool g_bIsConsistentX[9][9];
bool g_bIsConsistentY[9][9];

int g_answerCount[3][3];

int g_numCount[9];

bool Dfs(int writeCount, int tryN, int blockN)
{
    if (writeCount >= g_emptyCount)
    {
        return true;
    }
    
    for (int tryNum = tryN; tryNum <= 9; tryNum++)
    {
        if (g_numCount[tryNum - 1] == 9)
        {
            continue;
        }
        
        int blockNumInit = tryNum == tryN ? blockN : 0;
        
        for (int blockNum = blockNumInit; blockNum < 9; blockNum++)
        {
            // 꽉 차있으면 건너뜀
            if (g_answerCount[blockNum / 3][blockNum % 3] == 9)
            {
                continue;
            }
            
            // 그 블록에 숫자가 이미 있다면 건너뜀
            if (g_bIsInside[blockNum / 3][blockNum % 3][tryNum - 1] == true)
            {
                continue;
            }
            
            // Dfs
            int startI = 3 * (blockNum / 3);
            int startJ = 3 * (blockNum % 3);
            
            for (int i = startI; i < startI + 3; i++)
            {
                if (g_bIsConsistentX[i][tryNum - 1] == false)
                {
                    continue;
                }
                
                for (int j = startJ; j < startJ + 3; j++)
                {
                    if (g_bIsConsistentY[j][tryNum - 1] == false)
                    {
                        continue;
                    }
                    
                    if (g_board[i][j] != 0)
                    {
                        continue;
                    }
                    
                    // 들어갈 수 있다면
                    g_board[i][j] = tryNum;
                    g_bIsInside[i / 3][j / 3][tryNum - 1] = true;
                    g_bIsConsistentX[i][tryNum - 1] = false;
                    g_bIsConsistentY[j][tryNum - 1] = false;
                    g_answerCount[i / 3][j / 3]++;
                    g_numCount[tryNum - 1]++;
                    
                    int nextTryN = tryN + (blockN + 1) / 9;
                    int nextBlockN = (blockN + 1) % 9;
                    
                    if (writeCount + 1 == g_emptyCount)
                    {
                        return true;
                    }
                    
                    bool bIsAnswer = Dfs(writeCount + 1, nextTryN, nextBlockN);
                    
                    if (bIsAnswer == true)
                    {
                        return true;
                    }
                    else
                    {
                        g_board[i][j] = 0;
                        g_bIsInside[i / 3][j / 3][tryNum - 1] = false;
                        g_bIsConsistentX[i][tryNum - 1] = true;
                        g_bIsConsistentY[j][tryNum - 1] = true;
                        g_answerCount[i / 3][j / 3]--;
                        g_numCount[tryNum - 1]--;
                    }
                }
            }
            
            // 이번 재귀의 모든 케이스가 오답임
            return false;
        }
    }
    
    return true;
}

int main(void)
{
    memset(g_bIsInside, false, sizeof(bool) * 3 * 3 * 9);
    memset(g_answerCount, 0, sizeof(int) * 3 * 3);
    memset(g_bIsConsistentX, true, sizeof(bool) * 9 * 9);
    memcpy(g_bIsConsistentY, g_bIsConsistentX, sizeof(bool) * 9 * 9);
    
    
    // input
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &g_board[i][j]);

            if (g_board[i][j] == 0)
            {
                g_emptyCount++;
            }
            else
            {
                g_answerCount[i / 3][j / 3]++;
                g_bIsInside[i / 3][j / 3][g_board[i][j] - 1] = true;
                g_bIsConsistentX[i][g_board[i][j] - 1] = false;
                g_bIsConsistentY[j][g_board[i][j] - 1] = false;
                g_numCount[g_board[i][j] - 1]++;
            }
        }
    }

    Dfs(0, 1, 0);

    // output
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", g_board[i][j]);
        }
        
        printf("\n");
    }
}
