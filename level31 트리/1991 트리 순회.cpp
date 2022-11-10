#include <iostream>

void PrintPreorderTraversal(const char graph[][2], const char root)
{
    char left = graph[root - 'A'][0];
    char right = graph[root - 'A'][1];

    std::cout << root;

    if (left != '.')
    {
        PrintPreorderTraversal(graph, left);
    }

    if (right != '.')
    {
        PrintPreorderTraversal(graph, right);
    }
}

void PrintInorderTraversal(const char graph[][2], const char root)
{
    char left = graph[root - 'A'][0];
    char right = graph[root - 'A'][1];

    if (left != '.')
    {
        PrintInorderTraversal(graph, left);
    }

    std::cout << root;

    if (right != '.')
    {
        PrintInorderTraversal(graph, right);
    }
}

void PrintPostorderTraversal(const char graph[][2], const char root)
{
    char left = graph[root - 'A'][0];
    char right = graph[root - 'A'][1];

    if (left != '.')
    {
        PrintPostorderTraversal(graph, left);
    }

    if (right != '.')
    {
        PrintPostorderTraversal(graph, right);
    }

    std::cout << root;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    char graph[26][2];

    for (int i = 0; i < N; i++)
    {
        char parent;
        char left;
        char right;

        std::cin >> parent >> left >> right;

        graph[parent - 'A'][0] = left;
        graph[parent - 'A'][1] = right;
    }

    PrintPreorderTraversal(graph, 'A');
    std::cout << '\n';
    PrintInorderTraversal(graph, 'A');
    std::cout << '\n';
    PrintPostorderTraversal(graph, 'A');
}
