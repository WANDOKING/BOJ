#include <iostream>
#include <queue>

// node of tree
struct Node
{
	int num;
	char instruction;
	Node* prev;
	Node* childD;
	Node* childS;
	Node* childL;
	Node* childR;
};

// 4가지 연산
int D(int num);
int S(int num);;
int L(int num);
int R(int num);

// tree delete
void FreeNodeRecursive(Node* head);

// 결과를 출력하기 위한 함수, 내부적으로 PrintRecursive()를 호출
void PrintEndToHead(Node* end);

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int T;

	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		bool visited[10000] = { 0, };
		int A;
		int B;

		std::cin >> A >> B;

		std::queue<Node*> q;

		Node* const head = new Node();
		head->num = A;
		head->prev = nullptr;

		q.push(head);
		visited[A] = true;

		while (q.empty() == false)
		{
			Node* tree = q.front();

			if (tree->num == B)
			{
				PrintEndToHead(tree);
				FreeNodeRecursive(head);
				break;
			}

			if (visited[D(tree->num)] == false)
			{
				tree->childD = new Node();
				tree->childD->num = D(tree->num);
				tree->childD->prev = tree;
				tree->childD->instruction = 'D';
				q.push(tree->childD);

				visited[tree->childD->num] = true;
			}

			if (visited[S(tree->num)] == false)
			{
				tree->childS = new Node();
				tree->childS->num = S(tree->num);
				tree->childS->prev = tree;
				tree->childS->instruction = 'S';
				q.push(tree->childS);

				visited[tree->childS->num] = true;
			}

			if (visited[L(tree->num)] == false)
			{
				tree->childL = new Node();
				tree->childL->num = L(tree->num);
				tree->childL->prev = tree;
				tree->childL->instruction = 'L';
				q.push(tree->childL);

				visited[tree->childL->num] = true;
			}

			if (visited[R(tree->num)] == false)
			{
				tree->childR = new Node();
				tree->childR->num = R(tree->num);
				tree->childR->prev = tree;
				tree->childR->instruction = 'R';
				q.push(tree->childR);

				visited[tree->childR->num] = true;
			}

			q.pop();
		}
	}
}

int D(int num)
{
	return (num * 2) % 10000;
}

int S(int num)
{
	if (num == 0)
	{
		return 9999;
	}
	else
	{
		return num - 1;
	}
}

int L(int num)
{
	int temp = num / 1000;
	num = (num * 10) % 10000;
	num += temp;

	return num;
}

int R(int num)
{
	int temp = num % 10;
	num /= 10;
	num += temp * 1000;

	return num;
}

// tree delete
void FreeNodeRecursive(Node* head)
{
	if (head->childD != nullptr)
	{
		FreeNodeRecursive(head->childD);
	}
	if (head->childS != nullptr)
	{
		FreeNodeRecursive(head->childS);
	}
	if (head->childL != nullptr)
	{
		FreeNodeRecursive(head->childL);
	}
	if (head->childR != nullptr)
	{
		FreeNodeRecursive(head->childR);
	}
	delete head;
}

// 결과를 출력하기 위한 함수 PrintEndToHead()에 의해 호출됨
void PrintRecursive(Node* end, std::string* str)
{
	if (end->prev == nullptr)
	{
		for (int i = str->length() - 1; i >= 0; i--)
		{
			std::cout << (*str)[i];
		}
		std::cout << '\n';
		return;
	}

	*str += end->instruction;
	PrintRecursive(end->prev, str);
}

// 결과를 출력하기 위한 함수, 내부적으로 PrintRecursive()를 호출
void PrintEndToHead(Node* end)
{
	std::string* str = new std::string("");
	PrintRecursive(end, str);
	delete str;
}
