#include <iostream>
#include <climits>

#define MAX_N 100000

int g_nums[MAX_N];

struct Node
{
	int start;
	int end;
	int max;
	int min;
	Node* left;
	Node* right;
};

// 세그먼트 트리를 만든다
void MakeSegmentTreeRecursive(Node* head)
{
	if (head->start == head->end)
	{
		head->max = g_nums[head->start];
		head->min = g_nums[head->start];
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

	head->max = std::max(newLeft->max, newRight->max);
	head->min = std::min(newLeft->min, newRight->min);
	head->left = newLeft;
	head->right = newRight;
}

// start ~ end의 최값
int GetMaxRecursive(Node* head, const int start, const int end)
{
	if ((head->start == start && head->end == end) || head->start == head->end)
	{
		return head->max;
	}

	int mid = (head->start + head->end) / 2;
	
	int leftMax = 0;
	int rightMax = 0;
	if (start <= mid)
	{
		leftMax = GetMaxRecursive(head->left, start, std::min(mid, end));
	}

	if (end >= mid + 1)
	{
		rightMax = GetMaxRecursive(head->right, std::max(mid + 1, start), end);
	}

	return std::max(leftMax, rightMax);
}

// start ~ end의 최솟값
int GetMinRecursive(Node* head, const int start, const int end)
{
	if ((head->start == start && head->end == end) || head->start == head->end)
	{
		return head->min;
	}

	int mid = (head->start + head->end) / 2;

	int leftMin = INT_MAX;
	int rightMin = INT_MAX;
	if (start <= mid)
	{
		leftMin = GetMinRecursive(head->left, start, std::min(mid, end));
	}

	if (end >= mid + 1)
	{
		rightMin = GetMinRecursive(head->right, std::max(mid + 1, start), end);
	}

	return std::min(leftMin, rightMin);
}

int main(void)
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> g_nums[i];
	}

	Node* head = new Node;
	head->start = 0;
	head->end = N - 1;

	MakeSegmentTreeRecursive(head);

	for (int i = 0; i < M; ++i)
	{
		int start;
		int end;

		std::cin >> start >> end;
		int max = GetMaxRecursive(head, start - 1, end - 1);
		int min = GetMinRecursive(head, start - 1, end - 1);

		std::cout << min << ' ' << max << '\n';
	}
}
