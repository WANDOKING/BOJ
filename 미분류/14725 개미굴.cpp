#include <iostream>
#include <map>
#include <vector>

struct Node
{
    Node(const std::string& name)
        : Name(name)
    {

    }

    std::string Name;
    std::map<std::string, Node*> Childs;
};

Node* g_head;

void recursive(Node* head, const std::vector<std::string>& names, int index = 0)
{
    auto it = head->Childs.find(names[index]);

    if (it == head->Childs.end())
    {
        Node* newNode = new Node(names[index]);
        head->Childs.insert(std::make_pair(names[index], newNode));

        index++;

        if (index == names.size())
        {
            return;
        }

        recursive(newNode, names, index);
    }
    else
    {
        index++;

        if (index == names.size())
        {
            return;
        }

        recursive(it->second, names, index);
    }
}

void PrintRecursive(Node* head, int indent = 0)
{
    for (auto it = head->Childs.begin(); it != head->Childs.end(); ++it)
    {
        for (int i = 0; i < indent; ++i)
        {
            std::cout << '-';
        }

        std::cout << it->first << '\n';

        PrintRecursive(it->second, indent + 2);
    }
}

int main(void)
{
    int N;

    std::cin >> N;

    g_head = new Node("root");

    for (int i = 0; i < N; ++i)
    {
        int t;

        std::cin >> t;

        std::vector<std::string> names;
        names.reserve(t);

        for (int j = 0; j < t; ++j)
        {
            std::string name;

            std::cin >> name;

            names.push_back(std::move(name));
        }

        recursive(g_head, names);
    }

    PrintRecursive(g_head);
}
