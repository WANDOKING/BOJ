#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(void)
{
    int comNum;
    scanf("%d", &comNum);
    
    bool g[comNum + 1][comNum + 1];
    bool visited[comNum + 1];
    memset(g, false, sizeof(bool) * (comNum + 1) * (comNum + 1));
    memset(visited, false, sizeof(bool) * (comNum + 1));
    
    int connectedComNum;
    scanf("%d", &connectedComNum);
    
    for (int i = 0; i < connectedComNum; i++)
    {
        int v1;
        int v2;
        scanf("%d %d", &v1, &v2);
        g[v1][v2] = true;
        g[v2][v1] = true;
    }
    
    int count = 0;
    
    stack<int> s;
    for (int i = 1; i <= comNum; i++)
    {
        if (g[1][i] == true)
        {
            visited[i] = true;
            s.push(i);
            count++;
        }
    }
    visited[1] = true;
    
    while (s.empty() == false)
    {
        int top = s.top();
        s.pop();
        
        for (int i = 1; i <= comNum; i++)
        {
            if (g[top][i] == true && visited[i] == false)
            {
                visited[i] = true;
                s.push(i);
                count++;
            }
        }
    }
    
    printf("%d", count);
}
