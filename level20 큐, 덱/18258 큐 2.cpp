#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // 배열 기반 원형 버퍼 큐
    const int QUEUE_SIZE = 2000000;
    
    int N;
    int queue[QUEUE_SIZE];
    int size = 0;
    int front = 0;
    int back = -1;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        char command[10];
        
        scanf("%s", command);
        
        if (strcmp("push", command) == 0) {
            // size가 max일 때 push 없다고 가정
            
            int num;
            scanf("%d", &num);
            
            back++;
            if (back >= QUEUE_SIZE) {
                back = 0;
            }
            
            queue[back] = num;
            
            if (size == 0) {
                front = back;
            }
            
            size++;
        } else if (strcmp("pop", command) == 0) {
            if (size == 0) {
                printf("%d\n", -1);
                continue;
            }
            
            printf("%d\n", queue[front]);
            
            front++;
            if (front >= QUEUE_SIZE) {
                front = 0;
            }
            
            size--;
        } else if (strcmp("size", command) == 0) {
            printf("%d\n", size);
        } else if (strcmp("empty", command) == 0) {
            if (size == 0) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        } else if (strcmp("front", command) == 0) {
            if (size == 0) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[front]);
            }
        } else if (strcmp("back", command) == 0) {
            if (size == 0) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[back]);
            }
        }
    }
    
    return 0;
}
