#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

int main(void)
{
    int M;
    scanf("%d", &M);

    unordered_set<int> s;
    for (int i = 0; i < M; i++)
    {
        char command[10];
        scanf("%s", command);

        int x;
        if (strcmp(command, "add") == 0)
        {
            scanf("%d", &x);
            s.insert(x);
        }
        if (strcmp(command, "remove") == 0)
        {
            scanf("%d", &x);
            s.erase(x);
        }
        if (strcmp(command, "check") == 0)
        {
            scanf("%d", &x);

            if (s.find(x) == s.end())
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }
        if (strcmp(command, "toggle") == 0)
        {
            scanf("%d", &x);

            if (s.find(x) == s.end())
            {
                s.insert(x);
            }
            else
            {
                s.erase(x);
            }
        }
        if (strcmp(command, "all") == 0)
        {
            for (int j = 1; j <= 20; j++)
            {
                s.insert(j);
            }
        }
        if (strcmp(command, "empty") == 0)
        {
            s.clear();
        }
    }
}
