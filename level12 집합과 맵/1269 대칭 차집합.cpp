#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int ACount;
    int BCount;
    
    set<int> A;
    set<int> B;
    set<int> U;
    
    scanf("%d %d", &ACount, &BCount);
    
    for (int i = 0; i < ACount; i++) {
        int n;
        scanf("%d", &n);
        A.insert(n);
        U.insert(n);
    }
    
    for (int i = 0; i < BCount; i++) {
        int n;
        scanf("%d", &n);
        B.insert(n);
        U.insert(n);
    }
    
    int count = 0;
    for (set<int>::iterator it = U.begin(); it != U.end(); it++) {
        if (A.find(*it) != A.end() && B.find(*it) != B.end()) {
            continue;
        }
        
        count++;
    }
    
    printf("%d", count);
    
    return 0;
}
