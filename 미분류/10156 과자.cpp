#include <iostream>

int main(void)
{
    int K;
    int N;
    int M;
    
    std::cin >> K >> N >> M;
    
    int result = K * N - M > 0 ? K * N - M : 0;
    
    std::cout << result;
}
