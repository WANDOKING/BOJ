#include <iostream>

using namespace std;

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int result = 1;
    for (int i = 2; i <= N; i++) {
        result *= i;
    }
    
    printf("%d", result);

    return 0;
}
