#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int stack[10000]; // 스택
    int size = 0;     // 스택의 사이즈
    int N;            // 명령어 갯수
    
    char command[10]; // 명령어
    
    int* top = NULL;  // 스택의 top
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> command;
        
        if (strcmp(command, "push") == 0) {
            int num;
            cin >> num;
            
            stack[size] = num;
            top = &stack[size];
            size++;
            
        } else if (strcmp(command, "pop") == 0) {
            if (top == NULL) {
                cout << -1 << endl;
                continue;
            }
            
            cout << *top << endl;
            size--;
            
            if (size == 0) {
                top = NULL;
            } else {
                top = &stack[size - 1];
            }
            
            
        } else if (strcmp(command, "size") == 0) {
            cout << size << endl;
            
        } else if (strcmp(command, "empty") == 0) {
            if (size == 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
            
        } else if (strcmp(command, "top") == 0) {
            if (top == NULL) {
                cout << -1 << endl;
            } else {
                cout << *top << endl;
            }
            
        }
    }
    
    return 0;
}
