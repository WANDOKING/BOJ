#include <iostream>

const int MAX_COUNT = 5000000;

int queueNums[MAX_COUNT];
int back = 0;
int front = 0;
int numCount = 0;

void Enqueue(int n)
{
    numCount++;
    queueNums[back] = n;
    back = (back + 1) % MAX_COUNT;
    
}

int Dequeue()
{
    numCount--;
    int ret = queueNums[front];
    
    front = (front + 1) % MAX_COUNT;
    
    return ret;
}


int main()
{
    
    int N;
    
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        Enqueue(i);
    }
    
    while (numCount > 1) {
        Dequeue();
        Enqueue(Dequeue());
    }
    
    printf("%d", Dequeue());

    return 0;
}
