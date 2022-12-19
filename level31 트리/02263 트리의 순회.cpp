#include <iostream>
#include <vector>

#define MAX_N 100000

int g_inorder[MAX_N];
int g_postorderReversed[MAX_N];
int g_postorderReversedIndex = 0;
int n;

struct Node
{
	int number;
	Node* left;
	Node* right;

	Node(int number)
	{
		this->number = number;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void InsertRecursive(Node* head, int inorderStart = 0, int inorderEnd = n - 1)
{
	int nextRightInorderStart = -1;
	int nextRightInorderEnd = inorderEnd;

	int nextLeftInorderStart = inorderStart;
	int nextLeftInorderEnd = n;

	for (int i = 0; i < n; ++i)
	{
		if (g_inorder[i] == head->number)
		{
			nextRightInorderStart = i + 1;
			nextLeftInorderEnd = i - 1;
			break;
		}
	}

	if (nextRightInorderStart <= nextRightInorderEnd && nextRightInorderStart >= 0 && nextRightInorderEnd < n)
	{
		g_postorderReversedIndex++;
		Node* newRightNode = new Node(g_postorderReversed[g_postorderReversedIndex]);
		head->right = newRightNode;
		InsertRecursive(head->right, nextRightInorderStart, nextRightInorderEnd);
	}

	if (nextLeftInorderStart <= nextLeftInorderEnd && nextLeftInorderStart >= 0 && nextLeftInorderEnd < n)
	{
		g_postorderReversedIndex++;
		Node* newLeftNode = new Node(g_postorderReversed[g_postorderReversedIndex]);
		head->left = newLeftNode;
		InsertRecursive(head->left, nextLeftInorderStart, nextLeftInorderEnd);
	}
}

void PrintPreorder(const Node* headOrNull)
{
	if (headOrNull == nullptr)
	{
		return;
	}

	std::cout << headOrNull->number << ' ';
	PrintPreorder(headOrNull->left);
	PrintPreorder(headOrNull->right);
}

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> g_inorder[i];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		std::cin >> g_postorderReversed[i];
	}

	Node* head = new Node(g_postorderReversed[0]);
	InsertRecursive(head);
	PrintPreorder(head);
}
