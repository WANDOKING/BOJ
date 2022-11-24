#include <iostream>
#include <vector>

void PostorderTraversalPrintRecursive(const std::vector<int>& tree, const int start, const int end)
{
    int headData = tree[start];

    int i;
    for (i = start + 1; i <= end; i++)
    {
        if (tree[i] > headData)
        {
            break;
        }
    }

    if (start + 1 <= i - 1)
    {
        PostorderTraversalPrintRecursive(tree, start + 1, i - 1);
    }
    
    if (i <= end)
    {
        PostorderTraversalPrintRecursive(tree, i, end);
    }
    

    std::cout << headData << '\n';
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::vector<int> treeNums;
    treeNums.reserve(10000);

    int num;
    while (std::cin >> num)
    {
        treeNums.push_back(num);
    }

    PostorderTraversalPrintRecursive(treeNums, 0, treeNums.size() - 1);
}
