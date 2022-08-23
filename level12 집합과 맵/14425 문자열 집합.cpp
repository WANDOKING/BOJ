#include <iostream>
#include <set>

int main()
{
    int N;
    int M;
    
    scanf("%d %d", &N, &M);
    
    std::set<std::string> S;
    for (int i = 0; i < N; i++) {
        std::string input;
        
        std::cin >> input;
        
        S.insert(input);
    }
    
    int count = 0;
    for (int i = 0; i < M; i++) {
        std::string input;
        
        std::cin >> input;
        
        if (S.find(input) != S.end()) {
            count++;
        }
    }
    
    std::cout << count;

    return 0;
}
