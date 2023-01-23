#include <iostream>
#include <climits>
#include <cassert>

#define MAX_N 1000000

long long g_nums[MAX_N];

struct Node
{
	int start;
	int end;
	long long sum;
	Node* left;
	Node* right;
};

void MakeSegmentTreeRecursive(Node* head)
{
	assert(head != nullptr);

	if (head->start == head->end)
	{
		head->sum = g_nums[head->start];
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

	head->sum = newLeft->sum + newRight->sum;
	head->left = newLeft;
	head->right = newRight;
}

void UpdateSegmentTreeRecursive(Node* head, const int index, const long long data)
{
	assert(head != nullptr);
	assert(head->start <= index);
	assert(head->end >= index);

	if (head->start == head->end)
	{
		head->sum = data;
		return;
	}

	head->sum -= g_nums[index];
	head->sum += data;
	int mid = (head->start + head->end) / 2;

	if (index <= mid)
	{
		UpdateSegmentTreeRecursive(head->left, index, data);
	}
	else
	{
		UpdateSegmentTreeRecursive(head->right, index, data);
	}
}

long long GetSumRecursive(Node* head, const int start, const int end)
{
	if ((head->start == start && head->end == end) || head->start == head->end)
	{
		return head->sum;
	}

	int mid = (head->start + head->end) / 2;

	long long leftSum = 0;
	long long rightSum = 0;
	if (start <= mid)
	{
		leftSum = GetSumRecursive(head->left, start, std::min(mid, end));
	}

	if (end >= mid + 1)
	{
		rightSum = GetSumRecursive(head->right, std::max(mid + 1, start), end);
	}

	return leftSum + rightSum;
}

int main(void)
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;
	int K;

	std::cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> g_nums[i];
	}

	Node* head = new Node;
	head->start = 0;
	head->end = N - 1;

	MakeSegmentTreeRecursive(head);

	for (int i = 0; i < M + K; ++i)
	{
		long long a;
		long long b;
		long long c;

		std::cin >> a >> b >> c;

		if (a == 1)
		{
			UpdateSegmentTreeRecursive(head, b - 1, c);
			g_nums[b - 1] = c;
		}
		else
		{
			long long sum = GetSumRecursive(head, b - 1, c - 1);
			std::cout << sum << '\n';
		}
	}
}
