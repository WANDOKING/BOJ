#include <iostream>
#include <climits>

int g_saveCount = 0;
int g_K;

void Merge(int arr[], int start, int mid, int end)
{
    int temp[end - start + 1];
    int leftIndex = start;
    int rightIndex = mid + 1;

    for (int tempIndex = 0; tempIndex < end - start + 1; tempIndex++)
    {
        int leftMin = leftIndex <= mid ? arr[leftIndex] : INT_MAX;
        int rightMin = rightIndex <= end ? arr[rightIndex] : INT_MAX;
        int totalMin;

        if (leftMin <= rightMin)
        {
            totalMin = leftMin;
            leftIndex++;
        }
        else
        {
            totalMin = rightMin;
            rightIndex++;
        }

        temp[tempIndex] = totalMin;
        g_saveCount++;
        if (g_saveCount == g_K)
        {
            printf("%d", totalMin);
        }
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void MergeSortRecursive(int arr[], int start, int end)
{
    if (start == end)
    {
        return;
    }

    int mid = (start + end) / 2;

    MergeSortRecursive(arr, start, mid);
    MergeSortRecursive(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}

int main(void)
{
    int N;

    scanf("%d %d", &N, &g_K);

    int nums[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    MergeSortRecursive(nums, 0, N - 1);

    if (g_saveCount < g_K)
    {
        printf("-1");
    }
}
