#include <iostream>
#include <climits>

void SwapNum(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int N;
    int S;

    scanf("%d", &N);

    int nums[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &S);

    // 기본적으로 버블 정렬을 하되, 
    // 남은 횟수가 남은 정렬해야할 요소 수 보다 적을 경우 그 수준에서 그리디
    int unsortedArrayStart = 0;
    while (unsortedArrayStart < N)
    {
        if (S == 0)
        {
            break;
        }
        
        int maxRange;

        if (N - 1 - unsortedArrayStart < S)
        {
            maxRange = N;
        }
        else
        {
            maxRange = unsortedArrayStart + 1 + S;
        }

        //최대값을 찾아서 가장 앞으로 옮긴다 (그리디한 선택)
        int maxNum = INT_MIN;
        int maxNumIndex = -1;
        for (int i = unsortedArrayStart; i < maxRange; i++)
        {
            if (nums[i] > maxNum)
            {
                maxNum = nums[i];
                maxNumIndex = i;
            }
        }

        for (int i = maxNumIndex; i > unsortedArrayStart; i--)
        {
            SwapNum(nums[i], nums[i - 1]);
            S--;
        }

        unsortedArrayStart++;
    }

    // output
    for (int i = 0; i < N; i++)
    {
        printf("%d ", nums[i]);
    }
}
