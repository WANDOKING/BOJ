#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    // input (역순으로 순회할 것)
    stack<int> nums;
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        nums.push(num);
    }
    
    stack<int> answers; // 나중에 역순으로 출력하기 위함
    stack<int> temp;    // 오큰수를 찾기 위한 스택
    while (nums.empty() == false)
    {
        int n = nums.top();
        nums.pop();
        
        // temp가 비어있다면 -1
        if (temp.empty() == true)
        {
            answers.push(-1);
            temp.push(n);
            continue;
        }
        
        // temp 스택에서 n보다 큰 수를 찾을 때까지 pop()
        while (true)
        {
            if (temp.empty() == true)
            {
                answers.push(-1);
                break;
            }
            
            if (temp.top() > n)
            {
                answers.push(temp.top());
                break;
            }
            
            temp.pop();
        }
        
        temp.push(n);
    }
    
    // output
    while (answers.empty() == false)
    {
        printf("%d ", answers.top());
        answers.pop();
    }
}
