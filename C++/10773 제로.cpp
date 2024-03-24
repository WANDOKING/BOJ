#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int stack[100000]; // 스택
    int size = 0;     // 스택의 사이즈
    int K;            // 입력의 갯수
    
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        
        if (num == 0) {
            size--;
        } else {
            stack[size] = num;
            size++;
        }
    }
    
    // 합 구하기
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += stack[i];
    }
    
    cout << sum;
    
    return 0;
}
