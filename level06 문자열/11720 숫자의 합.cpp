#include <iostream>

using namespace std;

int main()
{
    int N;
    
    scanf("%d", &N);
    
    char nums[N + 1];
    
    scanf("%s", nums);
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += nums[i] - '0';
    }
    
    printf("%d", sum);
    
    return 0;
}
