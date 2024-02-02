#include <iostream>

using namespace std;

int main()
{
    while (true) {
        int A;
        int B;
        
        // EOF가 종료조건
        if (scanf("%d %d", &A, &B) == -1) {
            break;
        }
        
        printf("%d\n", A + B);
    }

    return 0;
}
