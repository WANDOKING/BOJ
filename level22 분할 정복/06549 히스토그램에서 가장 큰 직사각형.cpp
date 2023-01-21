#include <cassert>
#include <iostream>
#include <climits>

#define MAX_N 100000

int g_h[MAX_N];
long long g_result = 0;

struct Node
{
    int start;
    int end;
    int minIndex;
    Node* left;
    Node* right;
};

// 세그먼트 트리를 만든다
void MakeSegmentTreeRecursive(Node* head)
{
    if (head->start == head->end)
    {
        head->minIndex = head->start;
        head->left = nullptr;
        head->right = nullptr;
        return;
    }

    int mid = (head->start + head->end) / 2;

    Node* newLeft = new Node;
    newLeft->start = head->start;
    newLeft->end = mid;

    Node* newRight = new Node;
    newRight->start = mid + 1;
    newRight->end = head->end;

    MakeSegmentTreeRecursive(newLeft);
    MakeSegmentTreeRecursive(newRight);

    if (g_h[newLeft->minIndex] < g_h[newRight->minIndex])
    {
        head->minIndex = newLeft->minIndex;
    }
    else
    {
        head->minIndex = newRight->minIndex;
    }

    head->left = newLeft;
    head->right = newRight;
}

// start ~ end의 최솟값
int GetMinIndexRecursive(const Node* head, const int start, const int end)
{
    if ((head->start == start && head->end == end) || head->start == head->end)
    {
        return head->minIndex;
    }

    int mid = (head->start + head->end) / 2;

    int leftMinIndex = INT_MAX;
    int rightMinIndex = INT_MAX;
    if (start <= mid)
    {
        leftMinIndex = GetMinIndexRecursive(head->left, start, std::min(mid, end));
    }

    if (end >= mid + 1)
    {
        rightMinIndex = GetMinIndexRecursive(head->right, std::max(mid + 1, start), end);
    }

    if (rightMinIndex == INT_MAX)
    {
        return leftMinIndex;
    }
    else if (leftMinIndex == INT_MAX)
    {
        return rightMinIndex;
    }
    else if (g_h[leftMinIndex] < g_h[rightMinIndex])
    {
        return leftMinIndex;
    }
    else
    {
        return rightMinIndex;
    }
}

void SolveRecursive(const Node* head, const int start, const int end)
{
    int minHeightIndex = GetMinIndexRecursive(head, start, end);
    int minHeight = g_h[minHeightIndex];

    int length = end - start + 1;
    long long area = (long long)length * minHeight;

    if (area > g_result)
    {
        g_result = area;
    }

    // recursive
    if (minHeightIndex > start)
    {
        SolveRecursive(head, start, minHeightIndex - 1);
    }

    if (minHeightIndex < end)
    {
        SolveRecursive(head, minHeightIndex + 1, end);
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    while (true)
    {
        int n;
        std::cin >> n;

        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> g_h[i];
        }

        Node* head = new Node;
        head->start = 0;
        head->end = n - 1;
        MakeSegmentTreeRecursive(head);

        g_result = 0;
        SolveRecursive(head, 0, n - 1);
        std::cout << g_result << '\n';
    }
}
