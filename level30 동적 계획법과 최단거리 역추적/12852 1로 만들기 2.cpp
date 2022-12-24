#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

int main(void)
{
    int N;
    
    std::cin >> N;
    
    std::unordered_set<int> visited;
    std::queue<std::pair<int, std::vector<int>>> q; // N, ops
    q.push(std::make_pair(N, std::vector<int>()));
    
    std::vector<int> result;
    while (q.empty() == false)
    {
        int num = q.front().first;
        std::vector<int> opCount = q.front().second;
        q.pop();
        
        if (num == 1)
        {
            result = opCount;
            break;
        }
        
        if (visited.find(num) != visited.end())
        {
            continue;
        }
        
        visited.insert(num);
        opCount.push_back(num);
        
        if (num % 3 == 0)
        {
            q.push(std::make_pair(num / 3, opCount));
        }
        
        if (num % 2 == 0)
        {
            q.push(std::make_pair(num / 2, opCount));
        }
        
        q.push(std::make_pair(num - 1, opCount));
    }
    
    std::cout << result.size() << '\n';
    for (int num : result)
    {
        printf("%d ", num);
    }
    printf("1");
}
